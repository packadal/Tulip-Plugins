#include "TestAddEdge.h"
#include <iostream>

using namespace std;
using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(TestAddEdge);

void TestAddEdge::setUp()
{
	_engine = new QScriptEngine();
	_graph = 0;

	QScriptValue ctor1 = _engine->newFunction(graphFactory);
	_engine->globalObject().setProperty("newGraph", ctor1);

}

void TestAddEdge::tearDown()
{
	if (_graph != 0)
		delete _graph;
	delete _engine;
}

void TestAddEdge::invokeTest()
{
	_engine->evaluate("var g = newGraph(); var n1 = g.addNode(); var n2 = g.addNode(); storeGraph(g);");
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 0);

	_engine->evaluate("var e = g.addEdge(n1, n2); storeGraph(g);");
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 1);

	_engine->evaluate("g.addEdge(e); storeGraph(g);");
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 2);
}


QScriptValue storeGraph(QScriptContext *context, QScriptEngine *engine)
{
	(void) engine;
	_graph = (QGraph *)(context->argument(0).toQObject());
	return QScriptValue();
}
