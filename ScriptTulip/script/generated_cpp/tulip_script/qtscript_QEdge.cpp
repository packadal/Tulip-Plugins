#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QEdge.h>
#include <QEdge.h>
#include <QVariant>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlist.h>
#include <qobject.h>

#include "qtscriptshell_QEdge.h"

static const char * const qtscript_QEdge_function_names[] = {
    "QEdge"
    // static
    // prototype
    , "toString"
};

static const char * const qtscript_QEdge_function_signatures[] = {
    ""
    // static
    // prototype
""
};

static const int qtscript_QEdge_function_lengths[] = {
    0
    // static
    // prototype
    , 0
};

static QScriptValue qtscript_QEdge_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QEdge::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QEdge*)
Q_DECLARE_METATYPE(QtScriptShell_QEdge*)

//
// QEdge
//

static QScriptValue qtscript_QEdge_prototype_call(QScriptContext *context, QScriptEngine *)
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
    QEdge* _q_self = qscriptvalue_cast<QEdge*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QEdge.%0(): this object is not a QEdge")
            .arg(qtscript_QEdge_function_names[_id+1]));
    }

    switch (_id) {
    case 0: {
    QString result = QString::fromLatin1("QEdge");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QEdge_throw_ambiguity_error_helper(context,
        qtscript_QEdge_function_names[_id+1],
        qtscript_QEdge_function_signatures[_id+1]);
}

static QScriptValue qtscript_QEdge_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    if (context->thisObject().strictlyEquals(context->engine()->globalObject())) {
        return context->throwError(QString::fromLatin1("QEdge(): Did you forget to construct with 'new'?"));
    }
    if (context->argumentCount() == 0) {
        QtScriptShell_QEdge* _q_cpp_result = new QtScriptShell_QEdge();
        QScriptValue _q_result = context->engine()->newQObject(context->thisObject(), (QEdge*)_q_cpp_result, QScriptEngine::AutoOwnership);
        _q_cpp_result->__qtscript_self = _q_result;
        return _q_result;
    }
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QEdge_throw_ambiguity_error_helper(context,
        qtscript_QEdge_function_names[_id],
        qtscript_QEdge_function_signatures[_id]);
}

static QScriptValue qtscript_QEdge_toScriptValue(QScriptEngine *engine, QEdge* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QEdge_fromScriptValue(const QScriptValue &value, QEdge* &out)
{
    out = qobject_cast<QEdge*>(value.toQObject());
}

QScriptValue qtscript_create_QEdge_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QEdge*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QEdge*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QObject*>()));

    qScriptRegisterMetaType<QEdge*>(engine, qtscript_QEdge_toScriptValue, 
        qtscript_QEdge_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QEdge_static_call, proto, qtscript_QEdge_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
