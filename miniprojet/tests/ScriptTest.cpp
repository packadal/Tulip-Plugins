/*
 * ModelTestCase.cpp
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#include <stdexcept>
#include <cstdlib>
#include <ctime>

#include "ScriptTest.h"
#include "Model.h"
#include "Data.h"
#include "ScriptTestUtility.h"

const float TESTVALUE = 42.;
const int TESTVALUE2 = 42;
float testvalue = 0;

CPPUNIT_TEST_SUITE_REGISTRATION(ScriptTest);


void ScriptTest::setUp()
{
	_data = new Data();
	_data->add(0, 0);
	_engine = new QScriptEngine();

	QScriptValue ctor = _engine->newFunction(dataFactory);
	_engine->globalObject().setProperty("Data", ctor);

	testvalue = 0;
}

void ScriptTest::tearDown()
{
	delete _data;
}

void ScriptTest::invokeTest()
{
	QScriptValue value = _engine->newQObject(_data);
	_engine->globalObject().setProperty("data", value);

	CPPUNIT_ASSERT_EQUAL((float)0., _data->getY(0));

	_engine->evaluate("data.setY(0, "+QString::number(TESTVALUE)+")");

	if(_engine->hasUncaughtException())
		std::cout << qPrintable(_engine->uncaughtException().toString()) << std::endl;

	CPPUNIT_ASSERT_EQUAL(TESTVALUE, _data->getY(0));
}

void ScriptTest::newTest()
{
	QScriptValue value = _engine->newFunction(test);
	_engine->globalObject().setProperty("test", value);

	const QString script = "var d = new Data(); d.add(0, "+QString::number(TESTVALUE)+"); test(d.getY(0));";

	_engine->evaluate(script);
	if(_engine->hasUncaughtException())
			std::cout << qPrintable(_engine->uncaughtException().toString()) << std::endl;

	CPPUNIT_ASSERT_EQUAL(TESTVALUE, testvalue);
}

void ScriptTest::argTest()
{
	testvalue = 0;
	ScriptTestUtility* testArg = new ScriptTestUtility();
	QScriptValue value = _engine->newQObject(testArg);
	_engine->globalObject().setProperty("test", value);


	value = _engine->newQObject(_data);
	_engine->globalObject().setProperty("data", value);

	const QString script = "data.setY(0, "+QString::number(TESTVALUE)+"); test.passArg(data);";

	_engine->evaluate(script);
	if(_engine->hasUncaughtException())
		std::cout << qPrintable(_engine->uncaughtException().toString()) << std::endl;

	CPPUNIT_ASSERT_EQUAL(RESVALUE, _data->getY(0));
}

QScriptValue test(QScriptContext *context, QScriptEngine *engine)
{
	testvalue = context->argument(0).toNumber();
	return QScriptValue(engine, testvalue);
}

