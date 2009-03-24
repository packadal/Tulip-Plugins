#include "Translater.h"

#include "QGraph.h"
#include "QIterator.h"
#include "QEdge.h"
#include "QNode.h"
#include "QProperty.h"
#include "QBooleanProperty.h"
#include "QColorProperty.h"
#include "QDoubleProperty.h"
#include "QGraphProperty.h"
#include "QIntegerProperty.h"
#include "QLayoutProperty.h"
#include "QSizeProperty.h"
#include "QStringProperty.h"

#include <iostream>
#include <algorithm>

#include <QApplication>
#include <QStringList>
#include <QtGlobal>

using namespace std;

Translater::Translater(TulipScriptEngine* engine)
:scriptEngine(engine)
{

}

Translater::Translater()
:scriptEngine(new TulipScriptEngine())
{
	QScriptValue value = scriptEngine->newQObject(newGraph());
	scriptEngine->globalObject().setProperty("graph", value);
	initMap();
}

Translater::Translater(QFile *file)
:scriptEngine(new TulipScriptEngine()), fileStream(file), outputFile(new QFile("Plugin.cpp"))
{
	initMap();
	parse(fileStream->readAll());
}

Translater::~Translater() {
	delete scriptEngine;
}

void Translater::initMap() {

	parseTypes<QGraph>();
	parseTypes<QNode>();
	parseTypes<QEdge>();
	parseTypes<QIterator>();
	parseTypes<QProperty>();
	/*parseTypes<QBooleanProperty>();
	parseTypes<QColorProperty>();
	parseTypes<QDoubleProperty>();
	parseTypes<QGraphProperty>();
	parseTypes<QLayoutProperty>();
	parseTypes<QLayoutProperty>();
	parseTypes<QStringProperty>();*/
}

QString Translater::parse(const QString& script)
{
	cout << script.toStdString() << endl;
	QString result;



	scriptEngine->evaluate(script);

	if (scriptEngine->hasUncaughtException())
		cerr << scriptEngine->uncaughtException().toString().toStdString() << endl;

	// Header
	QFile header("header.txt");
	header.open(QIODevice::ReadOnly);
	result += header.readAll();

	// Then parse it
	QString line;
	foreach(QChar c, script)
	{
		line.append(c);
		if (c == '}' || c == '{' || c == ';' ) {
			result += addLine(line).toAscii();
			line.clear();
		}
	}

	// Footer
	QFile footer("footer.txt");
	footer.open(QIODevice::ReadOnly);
	result += footer.readAll();

	return result;
}

template <class T>
void Translater::parseTypes()
{
	const QMetaObject metaObj = T::staticMetaObject;//obj->metaObject();
	for (int i = 0; i < metaObj.methodCount(); ++i) {
		QMetaMethod qmm = metaObj.method(i);
		QRegExp regExp("([a-zA-Z0-9_-]+)[ ]*\\([a-zA-Z0-9,_- ]*\\)");
		if (regExp.exactMatch(qmm.signature())){
			QPair<QString,int> methodPair(regExp.cap(1), qmm.parameterNames().size());
			if (functionToType.contains(methodPair)){
				if(functionToType.value(methodPair).compare(QString(qmm.typeName())) != 0)
					cout << "Warning: Ambiguous Method \"" << methodPair.first.toStdString()
						<< "\" with " << methodPair.second << " parameters." << endl;
			}
			functionToType.insert(methodPair, QString(qmm.typeName()));}
	}
}

void Translater::viewMap()
{
	for (QMap<QPair<QString,int>, QString>::const_iterator it = functionToType.begin();
		it != functionToType.end();
		it++)
	{
		std::cout << it.key().first.toStdString() << ", "<< it.key().second << " : " << it.value().toStdString() << std::endl;
	}
	for (QMap<QString, QString>::const_iterator it =itToType.begin();
		it != itToType.end();
		it++)
	{
		std::cout << it.key().toStdString() << " : " << it.value().toStdString() << std::endl;
	}
}

QString Translater::convert() {
	QFile* outputFile = new QFile(fileStream->fileName() + ".cpp");
	return outputFile->fileName();
}

QString Translater::addLine(QString line) {
	QRegExp regExp("var[ ]?([a-zA-Z0-9_-]+)[ ]?=[ ]?(.+\\S*)[ ]?[;]");
	if (line.simplified().contains(regExp)) {
		QString rightMember = regExp.cap(2).replace(" ", "");
		QString type = fetchType(rightMember, regExp.cap(1));

		line.replace(regExp, type + " \\1 =\\2;");
	}
	QRegExp regExpIterator("(\\w+)(\\s*\\.[\\s]*next[\\s]*\\([\\s]*\\))");
	if (line.contains(regExpIterator))
		line.replace(regExpIterator, "(" + itToType.value(regExpIterator.cap(1)) + ")(\\1\\2)");
	return checkQuotedText(line);
}

QString Translater::fetchType(QString line, QString varName) {
	toCast = false;
	QScriptValue retVal = scriptEngine->evaluate(line);
	QString type;
	if (retVal.isBoolean())
		type = "bool";
	else if (retVal.isNumber())
		type = "double";
	else if (retVal.isString())
		type = "QString";
	else if (retVal.isQObject()) {
		type = fetchReturnType(line, varName);
		if (type == "")
			type = QString(retVal.toQObject()->metaObject()->className()).append('*');
	}
	else type = "void*";

	return type;
}

QString Translater::checkQuotedText(QString line) {
	if (line.contains(QRegExp("[\"].*[.].*[\"]"))) {
		QString newLine;
		bool isQuoted = false;
		for (int i = 0; i < line.size(); ++i) {
			if (line.at(i) == '.' && !isQuoted)
				newLine.append("->");
			else if (line.at(i) == '\'' && !isQuoted)
				newLine.append("\"");
			else {
				newLine.append(line.at(i));
				if (line.at(i) == '\"')
					isQuoted = !isQuoted;
			}
		}
		return newLine;
	}
	else {
		line.replace(".", "->");
		return line;
	}
}

QString Translater::fetchReturnType(QString line, QString varName) {
	int parenthesisLevel = -1;
	QString reverseFunctionName;
	int parameterNumber = 0;
	int i;

	for (i = line.size() - 1; i >= 0; --i) {
		if (line.at(i) == ')') {
			if (parenthesisLevel==-1)
				parenthesisLevel = 0;
			parenthesisLevel++;
		}
		else if (line.at(i) == '(')
			parenthesisLevel--;
		else if (parenthesisLevel == 0 && line.at(i) == '.')
			break;
		else if (parenthesisLevel == 0)
			reverseFunctionName.append(line.at(i));
		else if (parenthesisLevel == 1 && parameterNumber == 0 && line.at(i).isLetterOrNumber())
			parameterNumber++;
		else if (parenthesisLevel == 1 && line.at(i) == ',')
			parameterNumber++;
	}

	QString functionName;
	for (int i = reverseFunctionName.size() - 1; i >= 0; i--)
		functionName.append(reverseFunctionName.at(i));

	QString itType = parseIteratorType(functionName);
	if (itType != "")
		itToType.insert(varName, itType);

	// Default case
	if (functionName != "next") {
		return functionToType.value(QPair<QString, int>(functionName, parameterNumber));
	}

	// Iterator Case (need to know the return type of the iterator)
	toCast = true;
	QString reverseItName;
	while (i >= 0) {
		if (line.at(i).isLetterOrNumber() || line.at(i) == '_')
			reverseItName.append(line.at(i));
		else break;
	}
	QString itName;
	for (int i = reverseItName.size() - 1; i >= 0; i--)
		itName.append(reverseItName.at(i));
	return itToType.value(itName);

}


QString Translater::parseIteratorType(QString functionName)
{
	if (functionName == "getNodes")
		return "QNode*";
	else if (functionName == "getInNodes")
		return "QNode*";
	else if (functionName == "getOutNodes")
		return "QNode*";
	else if (functionName == "getInOutNodes")
		return "QNode*";
	else if (functionName == "getEdges")
		return "QEdge*";
	else if (functionName == "getOutEdges")
		return "QEdge*";
	else if (functionName == "getInOutEdges")
		return "QEdge*";
	else if (functionName == "getInEdges")
		return "QEdge*";
	else if (functionName == "getSubGraphs")
		return "QGraph*";
	else
		return "";
}

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	if (argc < 2) {
		cout << "Error: Must have a filename" << endl;
	} else {
		Translater t;
		QFile f(app.arguments().at(1));
		f.open(QIODevice::ReadOnly);
		QFile fOut("Plugin.cpp");
		fOut.open(QIODevice::WriteOnly);
		fOut.write(t.parse(f.readAll()).toAscii());
		t.viewMap();
	}
	return 0;
}
