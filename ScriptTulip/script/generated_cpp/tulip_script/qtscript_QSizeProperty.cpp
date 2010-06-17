#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QSizeProperty.h>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QSize3D.h>
#include <QVariant>
#include <qbytearray.h>
#include <qlist.h>
#include <qobject.h>

#include "qtscriptshell_QSizeProperty.h"

static const char * const qtscript_QSizeProperty_function_names[] = {
    "QSizeProperty"
    // static
    // prototype
    , "toString"
};

static const char * const qtscript_QSizeProperty_function_signatures[] = {
    "QGraph arg__1"
    // static
    // prototype
""
};

static const int qtscript_QSizeProperty_function_lengths[] = {
    1
    // static
    // prototype
    , 0
};

static QScriptValue qtscript_QSizeProperty_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QSizeProperty::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QSizeProperty*)
Q_DECLARE_METATYPE(QtScriptShell_QSizeProperty*)
Q_DECLARE_METATYPE(QGraph*)
Q_DECLARE_METATYPE(QProperty*)

//
// QSizeProperty
//

static QScriptValue qtscript_QSizeProperty_prototype_call(QScriptContext *context, QScriptEngine *)
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
    QSizeProperty* _q_self = qscriptvalue_cast<QSizeProperty*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QSizeProperty.%0(): this object is not a QSizeProperty")
            .arg(qtscript_QSizeProperty_function_names[_id+1]));
    }

    switch (_id) {
    case 0: {
    QString result = QString::fromLatin1("QSizeProperty");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QSizeProperty_throw_ambiguity_error_helper(context,
        qtscript_QSizeProperty_function_names[_id+1],
        qtscript_QSizeProperty_function_signatures[_id+1]);
}

static QScriptValue qtscript_QSizeProperty_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    if (context->thisObject().strictlyEquals(context->engine()->globalObject())) {
        return context->throwError(QString::fromLatin1("QSizeProperty(): Did you forget to construct with 'new'?"));
    }
    if (context->argumentCount() == 1) {
        QGraph* _q_arg0 = qscriptvalue_cast<QGraph*>(context->argument(0));
        QtScriptShell_QSizeProperty* _q_cpp_result = new QtScriptShell_QSizeProperty(_q_arg0);
        QScriptValue _q_result = context->engine()->newQObject(context->thisObject(), (QSizeProperty*)_q_cpp_result, QScriptEngine::AutoOwnership);
        _q_cpp_result->__qtscript_self = _q_result;
        return _q_result;
    }
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QSizeProperty_throw_ambiguity_error_helper(context,
        qtscript_QSizeProperty_function_names[_id],
        qtscript_QSizeProperty_function_signatures[_id]);
}

static QScriptValue qtscript_QSizeProperty_toScriptValue(QScriptEngine *engine, QSizeProperty* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QSizeProperty_fromScriptValue(const QScriptValue &value, QSizeProperty* &out)
{
    out = qobject_cast<QSizeProperty*>(value.toQObject());
}

QScriptValue qtscript_create_QSizeProperty_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QSizeProperty*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QSizeProperty*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QProperty*>()));

    qScriptRegisterMetaType<QSizeProperty*>(engine, qtscript_QSizeProperty_toScriptValue, 
        qtscript_QSizeProperty_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QSizeProperty_static_call, proto, qtscript_QSizeProperty_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
