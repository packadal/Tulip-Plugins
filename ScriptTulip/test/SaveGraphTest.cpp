#include "SaveGraphTest.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <tulip/Graph.h>

#include <QtScript/QScriptEngine>
#include <QTextStream>
#include <QFile>
#include <QScriptValue>
#include "QGraph.h"


using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(saveGraphTest);

void SaveGraphTest::setUp()
{
	_engine = new TulipScriptEngine();
	_graph = tlp::newGraph();

	_engine->addScriptFunction(graphFactory, "newGraph");
	_engine->addScriptFunction(saveGraph, "saveGraph");
	_engine->addScriptFunction(loadGraph, "loadGraph");

	filename = "grapheTest.tlp";
	filenameReference = "graphReference.tlp";
}

void SaveGraphTest::tearDown()
{
	std::system(std::string("rm " + filename).c_str());
	delete _graph;
	delete _engine;
}

void SaveGraphTest::saveTest()
{

	tlp::Graph* referenceGraph = tlp::loadGraph(filenameReference);
	tlp::saveGraph(referenceGraph,filenameReference);
	QGraph* qreferenceGraph = new QGraph(_engine,referenceGraph);
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
