#include "FetchPropertyTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(FetchPropertyTest);

using namespace std;

void FetchPropertyTest::setUp()
{
	_engine = new QScriptEngine();

	QScriptValue ctor = _engine->newFunction(graphFactory);
	_engine->globalObject().setProperty("newGraph", ctor);

	QScriptValue ctor2 = _engine->newFunction(storeProperty);
	_engine->globalObject().setProperty("storeProperty", ctor2);

}

void FetchPropertyTest::tearDown()
{
	delete _engine;
}

void FetchPropertyTest::invokeTest()
{
	_engine->evaluate(QString::fromStdString("var g = newGraph(); var prop = g.getProperty(\"viewColor\"); storeProperty(prop); "));//saveGraph(g, \""+filename+"\");"));
	if(_engine->hasUncaughtException())
		{
			cout << qPrintable(_engine->uncaughtException().toString()) << endl;
		}

	//CPPUNIT_ASSERT_EQUAL(_savedFile , data.readAll().toStdString());
}

QScriptValue storeProperty(QScriptContext *context, QScriptEngine *)
{
	_prop = (QProperty *)(context->argument(0).toQObject());
	cout << _prop->getNodeDefaultStringValue().toStdString() << endl;
	return QScriptValue();
}
