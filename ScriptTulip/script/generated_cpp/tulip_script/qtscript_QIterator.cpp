#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QIterator.h>
#include <QVariant>
#include <qbytearray.h>
#include <qlist.h>
#include <qobject.h>

#include "qtscriptshell_QIterator.h"

static const char * const qtscript_QIterator_function_names[] = {
    "QIterator"
    // static
    // prototype
    , "toString"
};

static const char * const qtscript_QIterator_function_signatures[] = {
    ""
    // static
    // prototype
""
};

static const int qtscript_QIterator_function_lengths[] = {
    0
    // static
    // prototype
    , 0
};

static QScriptValue qtscript_QIterator_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QIterator::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QIterator*)
Q_DECLARE_METATYPE(QtScriptShell_QIterator*)

//
// QIterator
//

static QScriptValue qtscript_QIterator_prototype_call(QScriptContext *context, QScriptEngine *)
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
    QIterator* _q_self = qscriptvalue_cast<QIterator*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QIterator.%0(): this object is not a QIterator")
            .arg(qtscript_QIterator_function_names[_id+1]));
    }

    switch (_id) {
    case 0: {
    QString result = QString::fromLatin1("QIterator");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QIterator_throw_ambiguity_error_helper(context,
        qtscript_QIterator_function_names[_id+1],
        qtscript_QIterator_function_signatures[_id+1]);
}

static QScriptValue qtscript_QIterator_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    return context->throwError(QScriptContext::TypeError,
        QString::fromLatin1("QIterator cannot be constructed"));
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QIterator_throw_ambiguity_error_helper(context,
        qtscript_QIterator_function_names[_id],
        qtscript_QIterator_function_signatures[_id]);
}

static QScriptValue qtscript_QIterator_toScriptValue(QScriptEngine *engine, QIterator* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QIterator_fromScriptValue(const QScriptValue &value, QIterator* &out)
{
    out = qobject_cast<QIterator*>(value.toQObject());
}

QScriptValue qtscript_create_QIterator_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QIterator*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QIterator*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QObject*>()));

    qScriptRegisterMetaType<QIterator*>(engine, qtscript_QIterator_toScriptValue, 
        qtscript_QIterator_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QIterator_static_call, proto, qtscript_QIterator_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
