/*
 * DataScriptClass.cpp
 *
 *  Created on: 30 oct. 2008
 *      Author: chuet
 */

#include "DataScriptClass.h"
#include "Data.h"
#include <QScriptEngine>

#include <QtCore/QObject>
#include <QtScript/QScriptable>
#include <QtScript/QScriptValue>
#include <QtCore/QObject>
#include <QtScript/QScriptClass>
#include <QtScript/QScriptString>


Q_DECLARE_METATYPE(Data*)
Q_DECLARE_METATYPE(DataScriptClass*)

DataScriptClass::DataScriptClass(QScriptEngine* engine)
:QObject(), QScriptClass(engine)
{
//	qScriptRegisterMetaType<Data>(engine, toScriptValue, fromScriptValue);


	 _prototype = engine->newQObject(new Data(),
							QScriptEngine::QtOwnership,
							QScriptEngine::SkipMethodsInEnumeration
							| QScriptEngine::ExcludeSuperClassMethods
							| QScriptEngine::ExcludeSuperClassProperties);
	 QScriptValue global = engine->globalObject();
	 _prototype.setPrototype(global.property("Object").property("prototype"));

	 _ctor = engine->newFunction(construct);
	 _ctor.setData(qScriptValueFromValue(engine, this));

}

QScriptValue DataScriptClass::construct(QScriptContext *ctx, QScriptEngine *eng)
{
	DataScriptClass *cls = qscriptvalue_cast<DataScriptClass*>(ctx->callee().data());
	if (!cls)
		return QScriptValue();
	return cls->newInstance();
}

QScriptValue DataScriptClass::newInstance()
{
	QScriptValue q;
	return q;
}
