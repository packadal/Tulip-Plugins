#include "TestAddNode.h"
#include <iostream>

using namespace std;
using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(TestAddNode);

void TestAddNode::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(graphFactory, "newGraph");
	_engine->addScriptFunction(storeGraph, "storeGraph");
}

void TestAddNode::tearDown()
{
	delete _engine;
}

void TestAddNode::invokeTest()
{
	_engine->evaluate("var g = newGraph(); storeGraph(g);");
	if(_engine->hasUncaughtException())
		cout << qPrintable(_engine->uncaughtException().toString()) << endl;

	CPPUNIT_ASSERT(_graph != 0);
	CPPUNIT_ASSERT(_graph->numberOfNodes() == 0);

	_engine->evaluate("var n1 = g.addNode();");
	if(_engine->hasUncaughtException())
		cout << qPrintable(_engine->uncaughtException().toString()) << endl;

	CPPUNIT_ASSERT(_graph->numberOfNodes() == 1);

	_engine->evaluate("var n2 = g.addNode();");
	CPPUNIT_ASSERT(_graph->numberOfNodes() == 2);
}
