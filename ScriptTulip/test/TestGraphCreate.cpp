#include "TestGraphCreate.h"
#include <iostream>

using namespace std;
using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(TestGraphCreate);

void TestGraphCreate::setUp()
{
	_engine = new TulipScriptEngine();
	_graph = 0;

	_engine->addScriptFunction(graphFactory, "newGraph");
	_engine->addScriptFunction(storeGraph, "storeGraph");
}

void TestGraphCreate::tearDown()
{
	if (_graph != 0)
		delete _graph;
	delete _engine;
}

void TestGraphCreate::invokeTest()
{
	_engine->evaluate("var g = newGraph(); storeGraph(g); ");

	CPPUNIT_ASSERT(_graph != 0);
}
