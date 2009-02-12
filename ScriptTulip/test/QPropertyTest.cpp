#include "QPropertyTest.h"
#include <tulip/Graph.h>
#include <tulip/ColorProperty.h>

#include "QGraph.h"
#include "QProperty.h"
#include "QNode.h"
#include "utilsTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(QPropertyTest);


void QPropertyTest::setUp()
{
	_engine = new TulipScriptEngine();
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
	const std::string s = "viewColor";
	QProperty property(qgraph.asGraph()->getProperty<tlp::ColorProperty>(s));
	property.setNodeStringValue(node,"(0,0,0,255)");
	QString value("(10,11,12,255)");

	_engine->addQObject(&property,QString::fromStdString("property"));
	_engine->addQObject(node,QString::fromStdString("node"));

	_engine->evaluate("property.setNodeStringValue(node, \""+ value +"\")");
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}
	QString result = property.getNodeStringValue(node);

	CPPUNIT_ASSERT(value == result);

}

void QPropertyTest::getNodeValueTest()
{
	QGraph qgraph;
	QNode* node = qgraph.addNode();
	const std::string s = "viewColor";
	QProperty property(qgraph.asGraph()->getProperty<tlp::ColorProperty>(s));
	QString value("(10,11,12,255)");
	property.setNodeStringValue(node,value);


	_engine->addQObject(&property,QString::fromStdString("property"));
	_engine->addQObject(node,QString::fromStdString("node"));

	_engine->evaluate("var value = property.getNodeStringValue(node); storeString(value);");
	if(_engine->hasUncaughtException())
	{
			CPPUNIT_FAIL(qPrintable(_engine->uncaughtException().toString()));
	}

	CPPUNIT_ASSERT(value == _string);

}

