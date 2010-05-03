#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QStringProperty.h>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QVariant>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlist.h>
#include <qobject.h>

#include "qtscriptshell_QStringProperty.h"

static const char * const qtscript_QStringProperty_function_names[] = {
    "QStringProperty"
    // static
    // prototype
    , "toString"
};

static const char * const qtscript_QStringProperty_function_signatures[] = {
    "QGraph arg__1"
    // static
    // prototype
""
};

static const int qtscript_QStringProperty_function_lengths[] = {
    1
    // static
    // prototype
    , 0
};

static QScriptValue qtscript_QStringProperty_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QStringProperty::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QStringProperty*)
Q_DECLARE_METATYPE(QtScriptShell_QStringProperty*)
Q_DECLARE_METATYPE(QGraph*)
Q_DECLARE_METATYPE(QProperty*)

//
// QStringProperty
//

static QScriptValue qtscript_QStringProperty_prototype_call(QScriptContext *context, QScriptEngine *)
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
    QStringProperty* _q_self = qscriptvalue_cast<QStringProperty*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QStringProperty.%0(): this object is not a QStringProperty")
            .arg(qtscript_QStringProperty_function_names[_id+1]));
    }

    switch (_id) {
    case 0: {
    QString result = QString::fromLatin1("QStringProperty");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QStringProperty_throw_ambiguity_error_helper(context,
        qtscript_QStringProperty_function_names[_id+1],
        qtscript_QStringProperty_function_signatures[_id+1]);
}

static QScriptValue qtscript_QStringProperty_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    if (context->thisObject().strictlyEquals(context->engine()->globalObject())) {
        return context->throwError(QString::fromLatin1("QStringProperty(): Did you forget to construct with 'new'?"));
    }
    if (context->argumentCount() == 1) {
        QGraph* _q_arg0 = qscriptvalue_cast<QGraph*>(context->argument(0));
        QtScriptShell_QStringProperty* _q_cpp_result = new QtScriptShell_QStringProperty(_q_arg0);
        QScriptValue _q_result = context->engine()->newQObject(context->thisObject(), (QStringProperty*)_q_cpp_result, QScriptEngine::AutoOwnership);
        _q_cpp_result->__qtscript_self = _q_result;
        return _q_result;
    }
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QStringProperty_throw_ambiguity_error_helper(context,
        qtscript_QStringProperty_function_names[_id],
        qtscript_QStringProperty_function_signatures[_id]);
}

static QScriptValue qtscript_QStringProperty_toScriptValue(QScriptEngine *engine, QStringProperty* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QStringProperty_fromScriptValue(const QScriptValue &value, QStringProperty* &out)
{
    out = qobject_cast<QStringProperty*>(value.toQObject());
}

QScriptValue qtscript_create_QStringProperty_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QStringProperty*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QStringProperty*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QProperty*>()));

    qScriptRegisterMetaType<QStringProperty*>(engine, qtscript_QStringProperty_toScriptValue, 
        qtscript_QStringProperty_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QStringProperty_static_call, proto, qtscript_QStringProperty_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
