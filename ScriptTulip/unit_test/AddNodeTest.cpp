#include "AddNodeTest.h"
#include <iostream>

#include "utilsTest.h"

#include "QGraph.h"
#include "QNode.h"
#include "TulipScriptEngine.h"

using namespace std;
using namespace tlp;

CPPUNIT_TEST_SUITE_REGISTRATION(AddNodeTest);

void AddNodeTest::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(storeGraph, "storeGraph");
	_engine->addScriptFunction(storeEdge, "storeEdge");
	_engine->addScriptFunction(storeNode, "storeNode");
	_engine->addScriptFunction(storeString, "storeString");
	_engine->addScriptFunction(testNode, "testNode");
}

void AddNodeTest::tearDown()
{
	delete _engine;
}

void AddNodeTest::invokeTest()
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

QScriptValue testNode(QScriptContext *context, QScriptEngine*)
{
	_graph = qobject_cast<QGraph*>(context->argument(0).toQObject());
	_node = qobject_cast<QNode*>(context->argument(1).toQObject());
	return QScriptValue();
}
