#include "LoadGraphTest.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <tulip/Graph.h>

#include <QtScript/QScriptEngine>
#include <QTextStream>
#include <QFile>
#include <QScriptValue>
#include "QGraph.h"
#include "utilsTest.h"


using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(LoadGraphTest);

void LoadGraphTest::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(storeGraph, "storeGraph");

	filename = "grapheTest.tlp";
	filenameReference = "graphReference.tlp";
}

void LoadGraphTest::tearDown()
{
	std::system(std::string("rm " + filename).c_str());
	delete _graph;
	delete _engine;
}

void LoadGraphTest::loadTest()
{
	_engine->evaluate(QString::fromStdString("var g = loadGraph(\""+filenameReference+"\"); storeGraph(g);"));
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}

	tlp::Graph* referenceGraph = tlp::loadGraph(filenameReference);
	tlp::saveGraph(referenceGraph,filenameReference);
	tlp::saveGraph(_graph->asGraph(),filename);


	QFile file(QString::fromStdString(filename)), fileReference(QString::fromStdString(filenameReference));
	file.open(QFile::ReadOnly);
	fileReference.open(QFile::ReadOnly);
	QTextStream data(&file);
	QTextStream dataReference(&fileReference);

	CPPUNIT_ASSERT_EQUAL(dataReference.readAll().toStdString(), data.readAll().toStdString());
}
