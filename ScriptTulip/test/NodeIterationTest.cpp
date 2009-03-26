#include "NodeIterationTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(NodeIterationTest);

#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
#include <QtCore/QTextStream>
#include <QtCore/QFile>

#include "TulipScriptEngine.h"
#include "QGraph.h"
#include "utilsTest.h"

void NodeIterationTest::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(storeGraph, "storeGraph");
	_engine->addScriptFunction(storeNode, "storeNode");
	_engine->addScriptFunction(storeEdge, "storeEdge");
	_engine->addScriptFunction(storeString, "storeString");

	_engine->evaluate(QString::fromStdString("var g = newGraph(); storeGraph(g);"));

	// 4 nodes (n1, n2, n3, n4)
	_engine->evaluate(QString::fromStdString("var n1 = g.addNode(); var n2 = g.addNode(); var n3 = g.addNode(); var n4 = g.addNode();"));
	// 4 edges (n1->n2, n2->n3, n3->n4, n4->n1)
	_engine->evaluate(QString::fromStdString("g.addEdge(n1, n2); g.addEdge(n2, n3); g.addEdge(n3, n4); g.addEdge(n4, n1); "));
}

void NodeIterationTest::tearDown()
{
	delete _engine;
}

void NodeIterationTest::invokeTest()
{
	testGetNodes();
	testGetInNodes();
	testGetOutNodes();
	testGetInOutNodes();
}

void NodeIterationTest::testGetNodes()
{
	_engine->evaluate(QString::fromStdString("var it = g.getNodes();"));
		if(_engine->hasUncaughtException())
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	tlp::Graph *testGraph = _graph->asGraph();
	tlp::Iterator<tlp::node> *it = testGraph->getNodes();
	int itCount = 0;
	while (it->hasNext()) {
		_engine->evaluate(QString::fromStdString("storeNode(it.next());"));
			if(_engine->hasUncaughtException())
				CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
		CPPUNIT_ASSERT(_testNode->asNode() == it->next());
		itCount++;
	}
	CPPUNIT_ASSERT(itCount == 4); // the four nodes of the graph
}

void NodeIterationTest::testGetInNodes()
{
	_engine->evaluate(QString::fromStdString("var it = g.getInNodes(n1); storeNode(n1);"));
		if(_engine->hasUncaughtException())
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	tlp::Graph *testGraph = _graph->asGraph();
	tlp::Iterator<tlp::node> *it = testGraph->getInNodes(_testNode->asNode());
	int itCount = 0;
	while (it->hasNext()) {
		_engine->evaluate(QString::fromStdString("storeNode(it.next());"));
			if(_engine->hasUncaughtException())
				CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
		CPPUNIT_ASSERT(_testNode->asNode() == it->next());
		itCount++;
	}
	CPPUNIT_ASSERT(itCount == 1); // only n4 (predecessor of n1)
}

void NodeIterationTest::testGetOutNodes()
{
	_engine->evaluate(QString::fromStdString("var it = g.getOutNodes(n1); storeNode(n1);"));
		if(_engine->hasUncaughtException())
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	tlp::Graph *testGraph = _graph->asGraph();
	tlp::Iterator<tlp::node> *it = testGraph->getOutNodes(_testNode->asNode());
	int itCount = 0;
	while (it->hasNext()) {
		_engine->evaluate(QString::fromStdString("storeNode(it.next());"));
			if(_engine->hasUncaughtException())
				CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
		CPPUNIT_ASSERT(_testNode->asNode() == it->next());
		itCount++;
	}
	CPPUNIT_ASSERT(itCount == 1); // only n2 (the successor of n1)
}

void NodeIterationTest::testGetInOutNodes()
{
	_engine->evaluate(QString::fromStdString("var it = g.getInOutNodes(n1); storeNode(n1);"));
		if(_engine->hasUncaughtException())
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	tlp::Graph *testGraph = _graph->asGraph();
	tlp::Iterator<tlp::node> *it = testGraph->getInOutNodes(_testNode->asNode());
	int itCount = 0;
	while (it->hasNext()) {
		_engine->evaluate(QString::fromStdString("storeNode(it.next());"));
			if(_engine->hasUncaughtException())
				CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
		CPPUNIT_ASSERT(_testNode->asNode() == it->next());
		itCount++;
	}
	CPPUNIT_ASSERT(itCount == 2); // n4 and n2 (the predecessor and the successor of n1)
}
