#include "TestAddEdge.h"
#include <iostream>

using namespace std;
using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(TestAddEdge);

void TestAddEdge::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(graphFactory, "newGraph");
	_engine->addScriptFunction(storeGraph, "storeGraph");
}

void TestAddEdge::tearDown()
{
	delete _engine;
}

void TestAddEdge::invokeTest()
{
	_engine->evaluate("var g = newGraph(); var n1 = g.addNode(); var n2 = g.addNode(); storeGraph(g);");
	if(_engine->hasUncaughtException())
		cout << qPrintable(_engine->uncaughtException().toString()) << endl;

	CPPUNIT_ASSERT(_graph != 0);
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 0);

	_engine->evaluate("var e = g.addEdge(n1, n2); storeGraph(g);");
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 1);

	_engine->evaluate("g.addEdge(e); storeGraph(g);");
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 2);
}
