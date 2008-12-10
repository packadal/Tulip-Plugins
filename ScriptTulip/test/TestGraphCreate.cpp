#include "TestGraphCreate.h"

using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(TestGraphCreate);

void TestGraphCreate::setUp()
{
	_engine = new QScriptEngine();
	_graph = 0;

	_engine->globalObject().setProperty("test", _engine->newQObject(this));
}

void TestGraphCreate::tearDown()
{
	if (_graph != 0)
		delete _graph;
	delete _engine;
}

void TestGraphCreate::invokeTest()
{

	_engine->evaluate("var g = newGraph(); test.storeGraph(g); ");

	CPPUNIT_ASSERT(_graph != 0);
}

void TestGraphCreate::storeGraph(QGraph *graph) {
	_graph = graph;
}
