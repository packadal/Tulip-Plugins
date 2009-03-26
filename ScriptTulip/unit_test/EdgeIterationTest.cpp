#include "EdgeIterationTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EdgeIterationTest);

#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>

#include <QtCore/QTextStream>
#include <QtCore/QFile>

#include "utilsTest.h"

#include "TulipScriptEngine.h"
#include "QGraph.h"


void EdgeIterationTest::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(storeGraph, "storeGraph");
	_engine->addScriptFunction(storeEdge, "storeEdge");
	_engine->addScriptFunction(storeNode, "storeNode");
	_engine->addScriptFunction(storeString, "storeString");

	_engine->evaluate(QString::fromStdString("var g = newGraph(); storeGraph(g);"));

	// 4 nodes (n1, n2, n3, n4)
	_engine->evaluate(QString::fromStdString("var n1 = g.addNode(); var n2 = g.addNode(); var n3 = g.addNode(); var n4 = g.addNode();"));
	// 4 edges (n1->n2, n2->n3, n3->n4, n4->n1)
	_engine->evaluate(QString::fromStdString("g.addEdge(n1, n2); g.addEdge(n2, n3); g.addEdge(n3, n4); g.addEdge(n4, n1); "));
}

void EdgeIterationTest::tearDown()
{
	delete _engine;
}

void EdgeIterationTest::invokeTest()
{
	testGetEdges();
	testGetInEdges();
	testGetOutEdges();
	testGetInOutEdges();
}

void EdgeIterationTest::testGetEdges()
{
	_engine->evaluate(QString::fromStdString("var it = g.getEdges();"));
		if(_engine->hasUncaughtException())
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	tlp::Graph *testGraph = _graph->asGraph();
	tlp::Iterator<tlp::edge> *it = testGraph->getEdges();
	int itCount = 0;
	while (it->hasNext()) {
		_engine->evaluate(QString::fromStdString("storeEdge(it.next());"));
			if(_engine->hasUncaughtException())
				CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
		CPPUNIT_ASSERT(_testEdge->asEdge() == it->next());
		itCount++;
	}
	CPPUNIT_ASSERT(itCount == 4); // the four edges of the graph
}

void EdgeIterationTest::testGetInEdges()
{
	_engine->evaluate(QString::fromStdString("var it = g.getInEdges(n1); storeNode(n1);"));
		if(_engine->hasUncaughtException())
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	tlp::Graph *testGraph = _graph->asGraph();
	tlp::Iterator<tlp::edge> *it = testGraph->getInEdges(_testNode->asNode());
	int itCount = 0;
	while (it->hasNext()) {
		_engine->evaluate(QString::fromStdString("storeEdge(it.next());"));
			if(_engine->hasUncaughtException())
				CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
		CPPUNIT_ASSERT(_testEdge->asEdge() == it->next());
		itCount++;
	}
	CPPUNIT_ASSERT(itCount == 1); // only n4->n1 (edge coming to n1)
}

void EdgeIterationTest::testGetOutEdges()
{
	_engine->evaluate(QString::fromStdString("var it = g.getOutEdges(n1); storeNode(n1);"));
		if(_engine->hasUncaughtException())
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	tlp::Graph *testGraph = _graph->asGraph();
	tlp::Iterator<tlp::edge> *it = testGraph->getOutEdges(_testNode->asNode());
	int itCount = 0;
	while (it->hasNext()) {
		_engine->evaluate(QString::fromStdString("storeEdge(it.next());"));
			if(_engine->hasUncaughtException())
				CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
		CPPUNIT_ASSERT(_testEdge->asEdge() == it->next());
		itCount++;
	}
	CPPUNIT_ASSERT(itCount == 1); // only n1->n2 (edge coming from n1)
}

void EdgeIterationTest::testGetInOutEdges()
{
	_engine->evaluate(QString::fromStdString("var it = g.getInOutEdges(n1); storeNode(n1);"));
		if(_engine->hasUncaughtException())
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	tlp::Graph *testGraph = _graph->asGraph();
	tlp::Iterator<tlp::edge> *it = testGraph->getInOutEdges(_testNode->asNode());
	int itCount = 0;
	while (it->hasNext()) {
		_engine->evaluate(QString::fromStdString("storeEdge(it.next());"));
			if(_engine->hasUncaughtException())
				CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
		CPPUNIT_ASSERT(_testEdge->asEdge() == it->next());
		itCount++;
	}
	CPPUNIT_ASSERT(itCount == 2); // n4->n1 and n1->n2 (edges coming to and from n1)
}
