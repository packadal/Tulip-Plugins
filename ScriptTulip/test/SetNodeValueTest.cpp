#include "SetNodeValueTest.h"
#include <tulip/Graph.h>

#include "QGraph.h"
#include "QProperty.h"
#include "QNode.h"

CPPUNIT_TEST_SUITE_REGISTRATION(SetNodeValueTest);


void SetNodeValueTest::setUp()
{
	_engine = new TulipScriptEngine();


}

void SetNodeValueTest::tearDown()
{
	delete _engine;
}

void SetNodeValueTest::invokeTest()
{
	tlp::Graph* graph = tlp::newGraph();
	QGraph qgraph(graph);
	QNode node ;
	qgraph.addNode(&node);
	QProperty property(graph->getProperty("viewColor"));
	property.setNodeStringValue(&node,"(0,0,0)");
	QString value("(10,11,12)");

	_engine->addQObject(&property,QString::fromStdString("property"));
	_engine->addQObject(&node,QString::fromStdString("node"));

	_engine->evaluate("property.setNodeStringValue(\""+ value +"\")");
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}
	QString result = property.getNodeStringValue(&node);

	CPPUNIT_ASSERT(value == result);

}

