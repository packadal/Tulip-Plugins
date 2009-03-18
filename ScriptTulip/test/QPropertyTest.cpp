#include "QPropertyTest.h"
#include <tulip/Graph.h>
#include <tulip/ColorProperty.h>

#include "TulipScriptEngine.h"
#include "QGraph.h"
#include "QProperty.h"
#include "QNode.h"
#include "utilsTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(QPropertyTest);


void QPropertyTest::setUp()
{
	_engine = new TulipScriptEngine();
	_engine->addScriptFunction(storeGraph, "storeGraph");
	_engine->addScriptFunction(storeNode, "storeNode");
	_engine->addScriptFunction(storeEdge, "storeEdge");
	_engine->addScriptFunction(storeString, "storeString");

}

void QPropertyTest::tearDown()
{
	delete _engine;
}

void QPropertyTest::setNodeValueTest()
{
	QGraph qgraph;
	QNode* node = qgraph.addNode();
	QColorProperty* property0 = qgraph.getColorProperty("viewColor");
	QProperty* property1 = qgraph.getGraphProperty("viewGraph");
	QProperty* property2 = qgraph.getDoubleProperty("viewDouble");
	QProperty* property3 = qgraph.getLayoutProperty("viewLayout");
	QProperty* property4 = qgraph.getStringProperty("viewString");
	QProperty* property5 = qgraph.getIntegerProperty("viewInteger");
	QProperty* property6 = qgraph.getSizeProperty("viewSize");
	QProperty* property7 = qgraph.getBooleanProperty("viewBoolean");

	_engine->addQObject(property0,QString::fromStdString("property0"));
	_engine->addQObject(property1,QString::fromStdString("property1"));
	_engine->addQObject(property2,QString::fromStdString("property2"));
	_engine->addQObject(property3,QString::fromStdString("property3"));
	_engine->addQObject(property4,QString::fromStdString("property4"));
	_engine->addQObject(property5,QString::fromStdString("property5"));
	_engine->addQObject(property6,QString::fromStdString("property6"));
	_engine->addQObject(property7,QString::fromStdString("property7"));

	_engine->addQObject(node,QString::fromStdString("node"));

	QString value("(10,11,12,255)");
	_engine->evaluate("property0.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	QString result = property0->getNodeStringValue(node);
	CPPUNIT_ASSERT(value == result);
	_engine->evaluate("var realValue = new QColor(11, 12, 13, 0); property0.setNodeValue(node, realValue)");
	handleError();
	QColor realResult = property0->getNodeValue(node);
	CPPUNIT_ASSERT(value == result);

	value="";
	_engine->evaluate("property1.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property1->getNodeStringValue(node);
	CPPUNIT_ASSERT(value == result);

	value="2.1";
	_engine->evaluate("property2.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property2->getNodeStringValue(node);
	CPPUNIT_ASSERT(value == result);

	value="(100,10,1000)";
	_engine->evaluate("property3.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property3->getNodeStringValue(node);
	CPPUNIT_ASSERT(value == result);

	value="a standard test for stringzz";
	_engine->evaluate("property4.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property4->getNodeStringValue(node);
	CPPUNIT_ASSERT(value == result);

	value="10";
	_engine->evaluate("property5.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property5->getNodeStringValue(node);
	CPPUNIT_ASSERT(value == result);

	value="(100,10,1000)";
	_engine->evaluate("property6.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property6->getNodeStringValue(node);
	CPPUNIT_ASSERT(value == result);

	value="false";
	_engine->evaluate("property7.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property7->getNodeStringValue(node);
	CPPUNIT_ASSERT(value == result);


}

void QPropertyTest::getNodeValueTest()
{
	QGraph qgraph;
	QNode* node = qgraph.addNode();
	QProperty* property = qgraph.getColorProperty("viewColor");
	QString value("(10,11,12,255)");
	property->setNodeStringValue(node,value);


	_engine->addQObject(property,QString::fromStdString("property"));
	_engine->addQObject(node,QString::fromStdString("node"));

	_engine->evaluate("var value = property.getNodeStringValue(node); storeString(value);");
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}

	CPPUNIT_ASSERT(value == _string);

}

void QPropertyTest::eraseNodeTest()
{
	QGraph qgraph;
	QNode* node = qgraph.addNode();
	const std::string s = "viewColor";
	QProperty property(qgraph.asGraph()->getProperty<tlp::ColorProperty>(s));
	QString value("(10,11,12,255)");
	property.setNodeStringValue(node,value);


	_engine->addQObject(&property,QString::fromStdString("property"));
	_engine->addQObject(node,QString::fromStdString("node"));

	_engine->evaluate("property.erase(node);var value = property.getNodeStringValue(node); storeString(value);");
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}
	CPPUNIT_ASSERT(value != _string);

}


void QPropertyTest::handleError() {
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}
}
