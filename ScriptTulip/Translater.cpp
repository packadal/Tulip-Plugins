#include "Translater.h"

#include "QGraph.h"
#include "QIterator.h"
#include "QEdge.h"
#include "QNode.h"
#include "QProperty.h"

#include <iostream>

#include <QApplication>

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
	/*obj = new QProperty();
	parseTypes(obj);
	delete obj;*/
}

void Translater::parse()
{
	// Execute the full script first
	/*fileStream->open(QIODevice::ReadOnly);
	scriptEngine->evaluate(QString(fileStream->readAll()));
	fileStream->close();*/

	if (scriptEngine->hasUncaughtException())
		cout << scriptEngine->uncaughtException().toString().toStdString()<<endl;
	else cout << "ouuuaaaais" << endl;

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
				addLine(line);
				line.clear();
			//}
		}
	}
}

QString Translater::parseLine(QString line)
{
	/*QString toAppend;
	QRegExp regExp("var +[a-zA-Z_-0-9]+ *= *");
	if (line.contains(regExp))
	{
		//cout << line.toStdString();
	}*/
	return QString();
}

void Translater::parseTypes(QObject* obj)
{
	const QMetaObject* metaObj = obj->metaObject();//QGraph::staticMetaObject();

	for (int i = 0; i < metaObj->methodCount(); ++i) {
		QMetaMethod qmm = metaObj->method(i);
		QRegExp regExp("([a-zA-Z0-9_-]+)[ ]*\\([a-zA-Z0-9,_- ]*\\)");
		if (regExp.exactMatch(qmm.signature()))
			functionToType.insert(regExp.cap(1), QString(qmm.typeName()));
	}

}

void Translater::viewMap()
{
	for (QMap<QString, QString>::const_iterator it = functionToType.begin();
		it != functionToType.end();
		it++)
	{
		std::cout << it.key().toStdString() << " : " << it.value().toStdString() << std::endl;
	}
}

QString Translater::convert() {
	QFile* outputFile = new QFile(fileStream->fileName() + ".cpp");

	return outputFile->fileName();
}

void Translater::addLine(QString line) {
	QRegExp regExp("[ \\t\\r\\n\\v\\f]*var[ \\t\\r\\n\\v\\f]+[a-zA-Z0-9_-]+[ \\t\\r\\n\\v\\f]*=[ \\t\\r\\n\\v\\f]*(\\S*)[ \\t\\r\\n\\v\\f]*[;]");
	if (regExp.exactMatch(line)) {

		cout << "catché : " << line.toStdString() << endl;
		cout << "apres le egal : " << regExp.cap(1).toStdString() << endl;

		QString type = fetchType(regExp.cap(1));

		QRegExp replaceExp("([ \\t\\r\\n\\v\\f])*var([ \\t\\r\\n\\v\\f]+[a-zA-Z0-9_-]+[ \\t\\r\\n\\v\\f]*=)");
		line.replace(replaceExp, "\\1" + type + "\\2");
		cout << "remplacé par : " << line.toStdString() << endl;
	}

	//cout << line.toStdString() << endl << endl;

}

QString Translater::fetchType(QString line) {
cout << "line : " << line.toStdString() << endl;
	QScriptValue retVal = scriptEngine->evaluate(line);
	QString type;
	if (retVal.isBoolean())
		type = "bool";
	else if (retVal.isNumber())
		type = "double";
	else if (retVal.isString())
		type = "QString";
	else if (retVal.isQObject()) {
		type = QString(retVal.toQObject()->metaObject()->className());
	}
	else type = "void*";

	return type;
}


int main(int argc, char** argv) {
	QApplication app(argc, argv);
	Translater t("./script.txt");

	//viewMap();
}
