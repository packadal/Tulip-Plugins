#include "AddEdgeTest.h"
#include "utilsTest.h"
#include <iostream>

using namespace std;
using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(AddEdgeTest);

void AddEdgeTest::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(graphFactory, "newGraph");
	_engine->addScriptFunction(edgeFactory, "Edge");
	_engine->addScriptFunction(storeGraph, "storeGraph");
	_engine->addScriptFunction(testEdge, "testEdge");
}

void AddEdgeTest::tearDown()
{
	delete _engine;
}

void AddEdgeTest::invokeTest()
{
	_engine->evaluate("var g = newGraph(); var n1 = g.addNode(); var n2 = g.addNode(); storeGraph(g);");

	if(_engine->hasUncaughtException())
		cout << qPrintable(_engine->uncaughtException().toString()) << endl;

	CPPUNIT_ASSERT(_graph != 0);
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 0);

	_engine->evaluate("var e = g.addEdge(n1, n2); testEdge(g, e);");
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 1);

	CPPUNIT_ASSERT(_graph->isElement(_edge));

//	_engine->evaluate("var n3 = g.addNode(); var e2 = new Edge(); g.addEdge(e2); storeGraph(g);");
	_engine->evaluate("var g2 = newGraph(); g2.addNode(n1); g2.addNode(n2); g.addEdge(e); storeGraph(g);");
	if(_engine->hasUncaughtException())
			cout << qPrintable(_engine->uncaughtException().toString()) << endl;
	CPPUNIT_ASSERT(_graph->numberOfEdges() == 2);
}

QScriptValue testEdge(QScriptContext *context, QScriptEngine*)
{
	_graph = qobject_cast<QGraph*>(context->argument(0).toQObject());
	_edge = qobject_cast<QEdge*>(context->argument(1).toQObject());
	return QScriptValue();
}
