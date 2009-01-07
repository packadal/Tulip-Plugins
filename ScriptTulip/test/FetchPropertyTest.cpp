#include "FetchPropertyTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(FetchPropertyTest);

using namespace std;

void FetchPropertyTest::setUp()
{
	_engine = new TulipScriptEngine();

	_engine->addScriptFunction(storeProperty, "storeProperty");
}

void FetchPropertyTest::tearDown()
{
	delete _engine;
}

void FetchPropertyTest::invokeTest()
{
	_engine->evaluate(QString::fromStdString("var g = newGraph(); "));

	if(_engine->hasUncaughtException())
		cout << qPrintable(_engine->uncaughtException().toString()) << endl;

	_engine->evaluate(QString::fromStdString("var prop = g.getProperty(\"viewColor\");"));

	_engine->evaluate(QString::fromStdString("storeProperty(prop);"));

	if(_engine->hasUncaughtException())
		cout << qPrintable(_engine->uncaughtException().toString()) << endl;
}

QScriptValue storeProperty(QScriptContext *context, QScriptEngine *)
{
	_prop = (QProperty *)(context->argument(0).toQObject());
	if (_prop != 0) {
		//cout << _prop->getNodeDefaultStringValue().toStdString() << endl;
	}
	return QScriptValue();
}
