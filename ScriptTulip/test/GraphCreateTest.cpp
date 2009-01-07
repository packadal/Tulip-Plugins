#include "GraphCreateTest.h"
#include <iostream>

using namespace std;
using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(GraphCreateTest);

void GraphCreateTest::setUp()
{
	_engine = new TulipScriptEngine();
	_graph = 0;

	_engine->addScriptFunction(storeGraph, "storeGraph");
}

void GraphCreateTest::tearDown()
{
	if (_graph != 0)
		delete _graph;
	delete _engine;
}

void GraphCreateTest::invokeTest()
{
	_engine->evaluate("var g = newGraph(); storeGraph(g); ");

	CPPUNIT_ASSERT(_graph != 0);
}
