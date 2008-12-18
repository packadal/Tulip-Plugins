#include "GetNodeValueTest.h"
#include <tulip/Graph.h>

#include "QGraph.h"
#include "QProperty.h"
#include "QNode.h"
#include "utilsTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(GetNodeValueTest);


void GetNodeValueTest::setUp()
{
	_engine = new TulipScriptEngine();
	_engine->addScriptFunction(storeString, "storeString");


}

void GetNodeValueTest::tearDown()
{
	delete _engine;
}

void GetNodeValueTest::invokeTest()
{
	tlp::Graph* graph = tlp::newGraph();
	QGraph qgraph(_engine,graph);
	QNode node ;
	qgraph.addNode(&node);
	QProperty property(graph->getProperty("viewColor"));
	QString value("(10,11,12)");
	property.setNodeStringValue(&node,value);


	_engine->addQObject(&property,QString::fromStdString("property"));
	_engine->addQObject(&node,QString::fromStdString("node"));

	_engine->evaluate("var value = property.getNodeStringValue(node); storeString(value);");
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}

	CPPUNIT_ASSERT(value == _string);

}

