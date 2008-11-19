#ifndef DATA_CPP
#define DATA_CPP

#include "Data.h"

QScriptValue dataFactory(QScriptContext *context, QScriptEngine *engine)
{
	(void) context; //to avoid a warning, we need this function signature
    QObject *object = new Data();
    return engine->newQObject(object, QScriptEngine::ScriptOwnership);
}

/*
QScriptValue toScriptValue(QScriptEngine *engine, const Data &d)
{
	(void) engine;
	(void) d;


	QScriptValue ctor = engine->globalObject().property("Data");
	Data *cls = qscriptvalue_cast<Data*>(ctor.data());
	if (!cls)
		return engine->newVariant(qVariantFromValue(d));
	*/
//	return dataFactory(engine->currentContext(), engine);

/*	QScriptValue obj = engine->newQObject(d);
	return obj; */
//}

/*
void fromScriptValue(const QScriptValue &obj, Data &d)
{
//	d = qobject_cast<Data*>(obj.toQObject());
//	Data* d2 =

//	std::cout << "fromScriptValue: " << d.size() << std::endl;
//	for(uint i = 0; i < d.size(); ++i)
//		std::cout << "adding value: " <<  d.getX(i) <<"; " << d.getY(i) << std::endl;
//	qobject_cast<Data*>(obj.toQObject());
	d = qscriptvalue_cast<Data>(obj);
}*/

#endif // DATA_CPP
