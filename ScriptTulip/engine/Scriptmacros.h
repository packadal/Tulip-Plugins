/*
 * Scriptmacros.h
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#ifndef SCRIPTMACROS_H_
#define SCRIPTMACROS_H_

#define CONCAT(truc, machin) truc ## machin

#define DECLARE_TYPE_TO_SCRIPT(type) Q_DECLARE_METATYPE(type*) \
QScriptValue CONCAT(type, ToScriptValue)(QScriptEngine *engine, type* const &item) { \
    return engine->newQObject(item); \
} \
void CONCAT(type, FromScriptValue)(const QScriptValue &object, type* &item) { \
    item = qobject_cast<type*>(object.toQObject()); \
} \
QScriptValue CONCAT(type, Factory)(QScriptContext *, QScriptEngine *engine) { \
    QObject *object = new type(); \
    return engine->newQObject(object, QScriptEngine::QtOwnership); \
}

#endif /* SCRIPTMACROS_H_ */
