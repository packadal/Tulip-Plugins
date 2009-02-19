#include "SaveGraphTest.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <tulip/Graph.h>

#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
#include <QtCore/QTextStream>
#include <QtCore/QFile>

#include "TulipScriptEngine.h"
#include "QGraph.h"


using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(SaveGraphTest);

void SaveGraphTest::setUp()
{
	_engine = new TulipScriptEngine();

	filename = "grapheTest.tlp";
	filenameReference = "graphReference.tlp";
}

void SaveGraphTest::tearDown()
{
	std::system(std::string("rm " + filename).c_str());
	delete _engine;
}

void SaveGraphTest::saveTest()
{

	tlp::Graph* referenceGraph = tlp::loadGraph(filenameReference);
	tlp::saveGraph(referenceGraph,filenameReference);
	QGraph* qreferenceGraph = new QGraph(referenceGraph);
	QScriptValue value = _engine->newQObject(qreferenceGraph);
	_engine->globalObject().setProperty("refrenceGraph",value);


	_engine->evaluate(QString::fromStdString(" saveGraph(refrenceGraph, \""+filename+"\");"));
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}


	QFile file(QString::fromStdString(filename)), fileReference(QString::fromStdString(filenameReference));
	file.open(QFile::ReadOnly);
	fileReference.open(QFile::ReadOnly);
	QTextStream data(&file);
	QTextStream dataReference(&fileReference);


	CPPUNIT_ASSERT_EQUAL(dataReference.readAll().toStdString(), data.readAll().toStdString());
}
