#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QView.h>
#include <QGraph.h>
#include <QVariant>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlist.h>
#include <qobject.h>

static const char * const qtscript_QView_function_names[] = {
    "QView"
    // static
    // prototype
    , "toString"
};

static const char * const qtscript_QView_function_signatures[] = {
    ""
    // static
    // prototype
""
};

static const int qtscript_QView_function_lengths[] = {
    0
    // static
    // prototype
    , 0
};

static QScriptValue qtscript_QView_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QView::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QView*)

//
// QView
//

static QScriptValue qtscript_QView_prototype_call(QScriptContext *context, QScriptEngine *)
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
    QView* _q_self = qscriptvalue_cast<QView*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QView.%0(): this object is not a QView")
            .arg(qtscript_QView_function_names[_id+1]));
    }

    switch (_id) {
    case 0: {
    QString result = QString::fromLatin1("QView");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QView_throw_ambiguity_error_helper(context,
        qtscript_QView_function_names[_id+1],
        qtscript_QView_function_signatures[_id+1]);
}

static QScriptValue qtscript_QView_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    return context->throwError(QScriptContext::TypeError,
        QString::fromLatin1("QView cannot be constructed"));
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QView_throw_ambiguity_error_helper(context,
        qtscript_QView_function_names[_id],
        qtscript_QView_function_signatures[_id]);
}

static QScriptValue qtscript_QView_toScriptValue(QScriptEngine *engine, QView* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QView_fromScriptValue(const QScriptValue &value, QView* &out)
{
    out = qobject_cast<QView*>(value.toQObject());
}

QScriptValue qtscript_create_QView_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QView*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QView*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QObject*>()));

    qScriptRegisterMetaType<QView*>(engine, qtscript_QView_toScriptValue, 
        qtscript_QView_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QView_static_call, proto, qtscript_QView_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
