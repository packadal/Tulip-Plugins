#include "TestGraphCreate.h"
#include <iostream>

using namespace std;
using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(TestGraphCreate);

void TestGraphCreate::setUp()
{
	_engine = new QScriptEngine();
	_graph = 0;

	QScriptValue value = _engine->newFunction(storeGraph);
	_engine->globalObject().setProperty("storeGraph", value);
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

QScriptValue storeGraph(QScriptContext *context, QScriptEngine *engine)
{
	(void) engine;
	_graph = (QGraph *)(context->argument(0).toQObject());
	return QScriptValue();
}
