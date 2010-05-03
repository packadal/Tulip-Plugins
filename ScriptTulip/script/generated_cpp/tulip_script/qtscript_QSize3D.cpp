#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QSize3D.h>
#include <QVariant>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlist.h>
#include <qobject.h>

#include "qtscriptshell_QSize3D.h"

static const char * const qtscript_QSize3D_function_names[] = {
    "QSize3D"
    // static
    // prototype
    , "toString"
};

static const char * const qtscript_QSize3D_function_signatures[] = {
    "\nfloat w, float h, float d"
    // static
    // prototype
""
};

static const int qtscript_QSize3D_function_lengths[] = {
    3
    // static
    // prototype
    , 0
};

static QScriptValue qtscript_QSize3D_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QSize3D::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QSize3D*)
Q_DECLARE_METATYPE(QtScriptShell_QSize3D*)

//
// QSize3D
//

static QScriptValue qtscript_QSize3D_prototype_call(QScriptContext *context, QScriptEngine *)
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
    QSize3D* _q_self = qscriptvalue_cast<QSize3D*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QSize3D.%0(): this object is not a QSize3D")
            .arg(qtscript_QSize3D_function_names[_id+1]));
    }

    switch (_id) {
    case 0: {
    QString result = QString::fromLatin1("QSize3D");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QSize3D_throw_ambiguity_error_helper(context,
        qtscript_QSize3D_function_names[_id+1],
        qtscript_QSize3D_function_signatures[_id+1]);
}

static QScriptValue qtscript_QSize3D_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    if (context->thisObject().strictlyEquals(context->engine()->globalObject())) {
        return context->throwError(QString::fromLatin1("QSize3D(): Did you forget to construct with 'new'?"));
    }
    if (context->argumentCount() == 0) {
        QtScriptShell_QSize3D* _q_cpp_result = new QtScriptShell_QSize3D();
        QScriptValue _q_result = context->engine()->newQObject(context->thisObject(), (QSize3D*)_q_cpp_result, QScriptEngine::AutoOwnership);
        _q_cpp_result->__qtscript_self = _q_result;
        return _q_result;
    } else if (context->argumentCount() == 3) {
        float _q_arg0 = qscriptvalue_cast<float>(context->argument(0));
        float _q_arg1 = qscriptvalue_cast<float>(context->argument(1));
        float _q_arg2 = qscriptvalue_cast<float>(context->argument(2));
        QtScriptShell_QSize3D* _q_cpp_result = new QtScriptShell_QSize3D(_q_arg0, _q_arg1, _q_arg2);
        QScriptValue _q_result = context->engine()->newQObject(context->thisObject(), (QSize3D*)_q_cpp_result, QScriptEngine::AutoOwnership);
        _q_cpp_result->__qtscript_self = _q_result;
        return _q_result;
    }
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QSize3D_throw_ambiguity_error_helper(context,
        qtscript_QSize3D_function_names[_id],
        qtscript_QSize3D_function_signatures[_id]);
}

static QScriptValue qtscript_QSize3D_toScriptValue(QScriptEngine *engine, QSize3D* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QSize3D_fromScriptValue(const QScriptValue &value, QSize3D* &out)
{
    out = qobject_cast<QSize3D*>(value.toQObject());
}

QScriptValue qtscript_create_QSize3D_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QSize3D*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QSize3D*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QObject*>()));

    qScriptRegisterMetaType<QSize3D*>(engine, qtscript_QSize3D_toScriptValue, 
        qtscript_QSize3D_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QSize3D_static_call, proto, qtscript_QSize3D_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
