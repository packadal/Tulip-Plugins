#include "IterationTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(IterationTest);

#include <QtScript/QScriptEngine>
#include <QTextStream>
#include <QFile>
#include <QScriptValue>
#include "QGraph.h"
#include "utilsTest.h"

void IterationTest::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(loadGraph, "loadGraph");
	_engine->addScriptFunction(storeGraph, "storeGraph");

	filename = "grapheTest.tlp";
	filenameReference = "graphReference.tlp";
}

void IterationTest::tearDown()
{
/* delete your stuff here */
}

void IterationTest::invokeTest()
{
	_engine->evaluate(QString::fromStdString("var g = loadGraph(\""+filenameReference+"\"); storeGraph(g);"));
	if(_engine->hasUncaughtException())
		CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));

	_engine->evaluate(QString::fromStdString("var it = g.getNodes(); it.next(); it.next(); it.next(); it.next(); it.next(); it.next(); it.next(); it.next();it.next();it.next();print(it.hasNext());"));
	if(_engine->hasUncaughtException())
		CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
}

static QScriptValue print(QScriptContext *context, QScriptEngine*)
{
	std::cout << qPrintable(context->argument(0).toString()) << std::endl;
	return QScriptValue();
}
