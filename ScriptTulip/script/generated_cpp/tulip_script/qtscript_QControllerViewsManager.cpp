#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QControllerViewsManager.h>
#include <QGraph.h>
#include <QVariant>
#include <QView.h>
#include <qbytearray.h>
#include <qlist.h>
#include <qobject.h>
#include <qvector.h>

static const char * const qtscript_QControllerViewsManager_function_names[] = {
    "QControllerViewsManager"
    // static
    // prototype
    , "toString"
};

static const char * const qtscript_QControllerViewsManager_function_signatures[] = {
    ""
    // static
    // prototype
""
};

static const int qtscript_QControllerViewsManager_function_lengths[] = {
    0
    // static
    // prototype
    , 0
};

static QScriptValue qtscript_QControllerViewsManager_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QControllerViewsManager::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QControllerViewsManager*)

//
// QControllerViewsManager
//

static QScriptValue qtscript_QControllerViewsManager_prototype_call(QScriptContext *context, QScriptEngine *)
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
    QControllerViewsManager* _q_self = qscriptvalue_cast<QControllerViewsManager*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QControllerViewsManager.%0(): this object is not a QControllerViewsManager")
            .arg(qtscript_QControllerViewsManager_function_names[_id+1]));
    }

    switch (_id) {
    case 0: {
    QString result = QString::fromLatin1("QControllerViewsManager");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QControllerViewsManager_throw_ambiguity_error_helper(context,
        qtscript_QControllerViewsManager_function_names[_id+1],
        qtscript_QControllerViewsManager_function_signatures[_id+1]);
}

static QScriptValue qtscript_QControllerViewsManager_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    return context->throwError(QScriptContext::TypeError,
        QString::fromLatin1("QControllerViewsManager cannot be constructed"));
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QControllerViewsManager_throw_ambiguity_error_helper(context,
        qtscript_QControllerViewsManager_function_names[_id],
        qtscript_QControllerViewsManager_function_signatures[_id]);
}

static QScriptValue qtscript_QControllerViewsManager_toScriptValue(QScriptEngine *engine, QControllerViewsManager* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QControllerViewsManager_fromScriptValue(const QScriptValue &value, QControllerViewsManager* &out)
{
    out = qobject_cast<QControllerViewsManager*>(value.toQObject());
}

QScriptValue qtscript_create_QControllerViewsManager_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QControllerViewsManager*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QControllerViewsManager*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QObject*>()));

    qScriptRegisterMetaType<QControllerViewsManager*>(engine, qtscript_QControllerViewsManager_toScriptValue, 
        qtscript_QControllerViewsManager_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QControllerViewsManager_static_call, proto, qtscript_QControllerViewsManager_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
