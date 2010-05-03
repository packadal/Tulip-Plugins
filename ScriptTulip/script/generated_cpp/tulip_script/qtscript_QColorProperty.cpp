#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QColorProperty.h>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QVariant>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlist.h>
#include <qobject.h>

#include "qtscriptshell_QColorProperty.h"

static const char * const qtscript_QColorProperty_function_names[] = {
    "QColorProperty"
    // static
    // prototype
    , "toString"
};

static const char * const qtscript_QColorProperty_function_signatures[] = {
    "QGraph arg__1"
    // static
    // prototype
""
};

static const int qtscript_QColorProperty_function_lengths[] = {
    1
    // static
    // prototype
    , 0
};

static QScriptValue qtscript_QColorProperty_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QColorProperty::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QColorProperty*)
Q_DECLARE_METATYPE(QtScriptShell_QColorProperty*)
Q_DECLARE_METATYPE(QGraph*)
Q_DECLARE_METATYPE(QProperty*)

//
// QColorProperty
//

static QScriptValue qtscript_QColorProperty_prototype_call(QScriptContext *context, QScriptEngine *)
{
#if QT_VERSION > 0x040400
    Q_ASSERT(context->callee().isFunction());
    uint _id = context->callee().data().toUInt32();
#else
    uint _id;
    if (context->callee().isFunction())
        _id = context->callee().data().toUInt32();
    else
        _id = 0xBABE0000 + 0;
#endif
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    QColorProperty* _q_self = qscriptvalue_cast<QColorProperty*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QColorProperty.%0(): this object is not a QColorProperty")
            .arg(qtscript_QColorProperty_function_names[_id+1]));
    }

    switch (_id) {
    case 0: {
    QString result = QString::fromLatin1("QColorProperty");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QColorProperty_throw_ambiguity_error_helper(context,
        qtscript_QColorProperty_function_names[_id+1],
        qtscript_QColorProperty_function_signatures[_id+1]);
}

static QScriptValue qtscript_QColorProperty_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    if (context->thisObject().strictlyEquals(context->engine()->globalObject())) {
        return context->throwError(QString::fromLatin1("QColorProperty(): Did you forget to construct with 'new'?"));
    }
    if (context->argumentCount() == 1) {
        QGraph* _q_arg0 = qscriptvalue_cast<QGraph*>(context->argument(0));
        QtScriptShell_QColorProperty* _q_cpp_result = new QtScriptShell_QColorProperty(_q_arg0);
        QScriptValue _q_result = context->engine()->newQObject(context->thisObject(), (QColorProperty*)_q_cpp_result, QScriptEngine::AutoOwnership);
        _q_cpp_result->__qtscript_self = _q_result;
        return _q_result;
    }
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QColorProperty_throw_ambiguity_error_helper(context,
        qtscript_QColorProperty_function_names[_id],
        qtscript_QColorProperty_function_signatures[_id]);
}

static QScriptValue qtscript_QColorProperty_toScriptValue(QScriptEngine *engine, QColorProperty* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QColorProperty_fromScriptValue(const QScriptValue &value, QColorProperty* &out)
{
    out = qobject_cast<QColorProperty*>(value.toQObject());
}

QScriptValue qtscript_create_QColorProperty_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QColorProperty*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QColorProperty*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QProperty*>()));

    qScriptRegisterMetaType<QColorProperty*>(engine, qtscript_QColorProperty_toScriptValue, 
        qtscript_QColorProperty_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QColorProperty_static_call, proto, qtscript_QColorProperty_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
