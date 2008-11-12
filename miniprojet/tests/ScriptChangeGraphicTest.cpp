#include "ScriptChangeGraphicTest.h"
#include <cstdlib>
#include <ctime>
#include "CurveGroup.h"
#include "HistogramGroup.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ScriptChangeGraphicTest);

void ScriptChangeGraphicTest::setUp()
{
	_data = new Data();

	_data->add(10, 3);
	_data->add(30, 4);
	_data->add(40, -10);
	_data->add(50, 6);
	_data->add(60, 12);

	_graphic = new CurveGroup(_data);

	addGraphic(_data, _graphic);
}

void ScriptChangeGraphicTest::tearDown()
{

}

void ScriptChangeGraphicTest::loadTest()
{
	QScriptValue value = _engine->newQObject(_graphic);
	_engine->globalObject().setProperty("curve", value);
	_engine->evaluate("var histogram = new HistogramGroup(); viewer.changeGraphic(curve, histogram);");
	CPPUNIT_ASSERT(_engine->hasUncaughtException() == false);

	CPPUNIT_ASSERT( _mapGraphics.lower_bound(_data)->second != _graphic);
}
