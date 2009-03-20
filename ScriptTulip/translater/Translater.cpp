#include "Translater.h"

#include "QGraph.h"
#include "QIterator.h"
#include "QEdge.h"
#include "QNode.h"
#include "QProperty.h"

#include <iostream>
#include <algorithm>

#include <QApplication>
#include <QStringList>

using namespace std;

Translater::Translater(QString urlFile) {
	scriptEngine = new TulipScriptEngine();

	fileStream = new QFile(urlFile);
	outputFile = new QFile(fileStream->fileName() + ".cpp");
	initMap();
	parse();
}

Translater::~Translater() {
	fileStream->close();
	delete fileStream;
}

void Translater::initMap() {
	QObject * obj = new QGraph();
	parseTypes(obj);
	delete obj;
	obj = new QNode();
	parseTypes(obj);
	delete obj;
	obj = new QEdge();
	parseTypes(obj);
	delete obj;
	obj = new QIterator();
	parseTypes(obj);
	delete obj;
	obj = new QProperty();
	parseTypes(obj);
	delete obj;
}

void Translater::parse()
{
	// Execute the full script first
	fileStream->open(QIODevice::ReadOnly);
	scriptEngine->evaluate(QString(fileStream->readAll()));
	fileStream->close();

	if (scriptEngine->hasUncaughtException())
		cerr << scriptEngine->uncaughtException().toString().toStdString() << endl;

	// Open the output file
	outputFile->open(QIODevice::WriteOnly);
	// Skeleton
	QByteArray header("#include \"QGraph.h\"\n#include \"QNode.h\"\n#include \"QEdge.h\"\n#include \"QProperty.h\"\n#include \"QIterator.h\"\n\nint main() {\n");
	outputFile->write(header);

	// Then parse it
	fileStream->open(QIODevice::ReadOnly);
	QString line;
	while (!fileStream->atEnd())
	{
		QByteArray carac = fileStream->read(1);
		line.append(carac);
		//QRegExp regExp(";}")
		if (carac.at(0) == '}' || carac.at(0) == '{' || carac.at(0) == ';' || fileStream->atEnd()) {
			//if (scriptEngine->canEvaluate(line)) {
				outputFile->write(addLine(line).toAscii());
				line.clear();
			//}
		}
	}
	QByteArray footer("\nreturn 0;\n}\n");
	outputFile->write(footer);
	outputFile->flush();
	outputFile->close();
}

void Translater::parseTypes(QObject* obj)
{
	const QMetaObject* metaObj = obj->metaObject();//QGraph::staticMetaObject();
	for (int i = 0; i < metaObj->methodCount(); ++i) {
		QMetaMethod qmm = metaObj->method(i);
		QRegExp regExp("([a-zA-Z0-9_-]+)[ ]*\\([a-zA-Z0-9,_- ]*\\)");
		if (regExp.exactMatch(qmm.signature())){
			QPair<QString,int> methodPair(regExp.cap(1), qmm.parameterNames().size());
			if (functionToType.contains(methodPair)){
				if(functionToType.value(methodPair).compare(QString(qmm.typeName()))!=0)
					cout << "pas bon du tout ! " << methodPair.first.toStdString() << " " << methodPair.second<<endl;
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
		std::cout << it.key().first.toStdString() <<", "<< it.key().second << " : " << it.value().toStdString() << std::endl;
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

		cout << "catché : " << line.toStdString() << endl;

		QString rightMember = regExp.cap(2).replace(" ", "");
		cout << "apres le egal : " << rightMember.toStdString() << endl;

		QString type = fetchType(rightMember, regExp.cap(1));
		//line.replace

		//QRegExp replaceExp("var([ ]?[a-zA-Z0-9_-]+[ ]?=)");
		//line.replace(replaceExp, type + "\\1");
		line.replace(regExp, type + " \\1 =" + (toCast ? ("(" + type + ")(") : "") + "\\2" + (toCast ? ")" : "") + ";");
		cout << "remplacé par : " << line.toStdString() << endl;
	}
	return checkQuotedText(line);
}

QString Translater::fetchType(QString line, QString varName) {
	cout << "line : " << line.toStdString() << endl;
	toCast = false;
	QScriptValue retVal = scriptEngine->evaluate(line);
	//cout << retVal.toString().toStdString()<<endl();
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
		cout << "fonction : " << functionName.toStdString() << ", nb param : " << parameterNumber << endl;
		cout << "type de retour : " << functionToType.value(QPair<QString, int>(functionName, parameterNumber)).toStdString() << endl;
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
	Translater t(argv[1]);

	t.viewMap();
	return 0;
}
