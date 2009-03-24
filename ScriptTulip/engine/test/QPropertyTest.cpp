#include "QPropertyTest.h"
#include <tulip/Graph.h>

#include "TulipScriptEngine.h"
#include "QGraph.h"
#include "QProperty.h"
#include "QColorProperty.h"
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
	_engine->evaluate(QString::fromStdString("var g = newGraph(); storeGraph(g);"));
	_engine->evaluate("var node = g.addNode(); storeNode(node);");
	QColorProperty* property0 = _graph->getColorProperty("viewColor");
	QGraphProperty* property1 = _graph->getGraphProperty("viewGraph");
	QDoubleProperty* property2 = _graph->getDoubleProperty("viewDouble");
	QLayoutProperty* property3 = _graph->getLayoutProperty("viewLayout");
	QStringProperty* property4 = _graph->getStringProperty("viewString");
	QIntegerProperty* property5 = _graph->getIntegerProperty("viewInteger");
	QSizeProperty* property6 = _graph->getSizeProperty("viewSize");
	QBooleanProperty* property7 = _graph->getBooleanProperty("viewBoolean");

	_engine->addQObject(property0,QString::fromStdString("property0"));
	_engine->addQObject(property1,QString::fromStdString("property1"));
	_engine->addQObject(property2,QString::fromStdString("property2"));
	_engine->addQObject(property3,QString::fromStdString("property3"));
	_engine->addQObject(property4,QString::fromStdString("property4"));
	_engine->addQObject(property5,QString::fromStdString("property5"));
	_engine->addQObject(property6,QString::fromStdString("property6"));
	_engine->addQObject(property7,QString::fromStdString("property7"));

	QString value("(10,11,12,255)");
	_engine->evaluate("property0.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	QString result = property0->getNodeStringValue(_testNode);
	CPPUNIT_ASSERT(value == result);
	QColor* realValue0 = new QColor(11, 12, 13, 0);
	_engine->evaluate("var realValue = new QColor(11, 12, 13, 0); property0.setNodeValue(node, realValue)");
	handleError();
	QColor* realResult0 = property0->getNodeValue(_testNode);
	CPPUNIT_ASSERT(realValue0->red()==realResult0->red());
	CPPUNIT_ASSERT(realValue0->green()==realResult0->green());
	CPPUNIT_ASSERT(realValue0->blue()==realResult0->blue());
	CPPUNIT_ASSERT(realValue0->alpha()==realResult0->alpha());

	value="";
	_engine->evaluate("property1.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property1->getNodeStringValue(_testNode);
	CPPUNIT_ASSERT(value == result);
	_engine->evaluate("var realValue1 = new QGraph(); realValue1.addNode(); property1.setNodeValue(node, realValue1)");
	handleError();
	QGraph* realResult1 = property1->getNodeValue(_testNode);
	CPPUNIT_ASSERT(realResult1->numberOfNodes() == 1);

	value="2.1";
	_engine->evaluate("property2.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property2->getNodeStringValue(_testNode);
	CPPUNIT_ASSERT(value == result);
	double realValue2 = 2.5;
	_engine->evaluate("property2.setNodeValue(node, 2.5)");
	handleError();
	double realResult2 = property2->getNodeValue(_testNode);
	CPPUNIT_ASSERT(realValue2 == realResult2);


	value="(100,10,1000)";
	_engine->evaluate("property3.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property3->getNodeStringValue(_testNode);
	CPPUNIT_ASSERT(value == result);
	QSize3D* realValue3 = new QSize3D(1,2,3);
	_engine->evaluate("property3.setNodeValue(node, new QSize3D(1,2,3))");
	handleError();
	QSize3D* realResult3 = property3->getNodeValue(_testNode);
	CPPUNIT_ASSERT(realValue3->getW() == realResult3->getW());
	CPPUNIT_ASSERT(realValue3->getH() == realResult3->getH());
	CPPUNIT_ASSERT(realValue3->getD() == realResult3->getD());

	value="a standard test for stringzz";
	_engine->evaluate("property4.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property4->getNodeStringValue(_testNode);
	CPPUNIT_ASSERT(value == result);
	QString realValue4("an other string to test");
	_engine->evaluate("property4.setNodeValue(node, \"an other string to test\");");
	handleError();
	QString realResult4 = property4->getNodeValue(_testNode);
	CPPUNIT_ASSERT(realValue4 == realResult4);


	value="10";
	_engine->evaluate("property5.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property5->getNodeStringValue(_testNode);
	CPPUNIT_ASSERT(value == result);
	int realValue5 = 10000000;
	_engine->evaluate("property5.setNodeValue(node, 10000000)");
	handleError();
	int realResult5 = property5->getNodeValue(_testNode);
	CPPUNIT_ASSERT(realValue5 == realResult5);

	value="(100,10,1000)";
	_engine->evaluate("property6.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property6->getNodeStringValue(_testNode);
	CPPUNIT_ASSERT(value == result);
	QSize3D* realValue6 = new QSize3D(1,2,3);
	_engine->evaluate("property6.setNodeValue(node, new QSize3D(1,2,3))");
	handleError();
	QSize3D* realResult6 = property6->getNodeValue(_testNode);
	CPPUNIT_ASSERT(realValue6->getW() == realResult6->getW());
	CPPUNIT_ASSERT(realValue6->getH() == realResult6->getH());
	CPPUNIT_ASSERT(realValue6->getD() == realResult6->getD());

	value="false";
	_engine->evaluate("property7.setNodeStringValue(node, \""+ value +"\")");
	handleError();
	result = property7->getNodeStringValue(_testNode);
	CPPUNIT_ASSERT(value == result);
	bool realValue7 = true;
	_engine->evaluate("property7.setNodeValue(node, true)");
	handleError();
	int realResult7 = property7->getNodeValue(_testNode);
	CPPUNIT_ASSERT(realValue7 == realResult7);


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
