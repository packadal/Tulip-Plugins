#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptValue>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <qmetaobject.h>

#include <QGraph.h>
#include <QBooleanProperty.h>
#include <QColorProperty.h>
#include <QDoubleProperty.h>
#include <QEdge.h>
#include <QGraph.h>
#include <QGraphProperty.h>
#include <QIntegerProperty.h>
#include <QIterator.h>
#include <QLayoutProperty.h>
#include <QNode.h>
#include <QProperty.h>
#include <QSizeProperty.h>
#include <QStringProperty.h>
#include <QVariant>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlist.h>
#include <qobject.h>

#include "qtscriptshell_QGraph.h"

static const char * const qtscript_QGraph_function_names[] = {
    "QGraph"
    // static
    // prototype
    , "clone"
    , "toString"
};

static const char * const qtscript_QGraph_function_signatures[] = {
    ""
    // static
    // prototype
    , ""
""
};

static const int qtscript_QGraph_function_lengths[] = {
    0
    // static
    // prototype
    , 0
    , 0
};

static QScriptValue qtscript_QGraph_throw_ambiguity_error_helper(
    QScriptContext *context, const char *functionName, const char *signatures)
{
    QStringList lines = QString::fromLatin1(signatures).split(QLatin1Char('\n'));
    QStringList fullSignatures;
    for (int i = 0; i < lines.size(); ++i)
        fullSignatures.append(QString::fromLatin1("%0(%1)").arg(functionName).arg(lines.at(i)));
    return context->throwError(QString::fromLatin1("QGraph::%0(): could not find a function match; candidates are:\n%1")
        .arg(functionName).arg(fullSignatures.join(QLatin1String("\n"))));
}

Q_DECLARE_METATYPE(QGraph*)
Q_DECLARE_METATYPE(QtScriptShell_QGraph*)

//
// QGraph
//

static QScriptValue qtscript_QGraph_prototype_call(QScriptContext *context, QScriptEngine *)
{
#if QT_VERSION > 0x040400
    Q_ASSERT(context->callee().isFunction());
    uint _id = context->callee().data().toUInt32();
#else
    uint _id;
    if (context->callee().isFunction())
        _id = context->callee().data().toUInt32();
    else
        _id = 0xBABE0000 + 1;
#endif
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    QGraph* _q_self = qscriptvalue_cast<QGraph*>(context->thisObject());
    if (!_q_self) {
        return context->throwError(QScriptContext::TypeError,
            QString::fromLatin1("QGraph.%0(): this object is not a QGraph")
            .arg(qtscript_QGraph_function_names[_id+1]));
    }

    switch (_id) {
    case 0:
    if (context->argumentCount() == 0) {
        QGraph* _q_result = _q_self->clone();
        return qScriptValueFromValue(context->engine(), _q_result);
    }
    break;

    case 1: {
    QString result = QString::fromLatin1("QGraph");
    return QScriptValue(context->engine(), result);
    }

    default:
    Q_ASSERT(false);
    }
    return qtscript_QGraph_throw_ambiguity_error_helper(context,
        qtscript_QGraph_function_names[_id+1],
        qtscript_QGraph_function_signatures[_id+1]);
}

static QScriptValue qtscript_QGraph_static_call(QScriptContext *context, QScriptEngine *)
{
    uint _id = context->callee().data().toUInt32();
    Q_ASSERT((_id & 0xFFFF0000) == 0xBABE0000);
    _id &= 0x0000FFFF;
    switch (_id) {
    case 0:
    if (context->thisObject().strictlyEquals(context->engine()->globalObject())) {
        return context->throwError(QString::fromLatin1("QGraph(): Did you forget to construct with 'new'?"));
    }
    if (context->argumentCount() == 0) {
        QtScriptShell_QGraph* _q_cpp_result = new QtScriptShell_QGraph();
        QScriptValue _q_result = context->engine()->newQObject(context->thisObject(), (QGraph*)_q_cpp_result, QScriptEngine::AutoOwnership);
        _q_cpp_result->__qtscript_self = _q_result;
        return _q_result;
    }
    break;

    default:
    Q_ASSERT(false);
    }
    return qtscript_QGraph_throw_ambiguity_error_helper(context,
        qtscript_QGraph_function_names[_id],
        qtscript_QGraph_function_signatures[_id]);
}

static QScriptValue qtscript_QGraph_toScriptValue(QScriptEngine *engine, QGraph* const &in)
{
    return engine->newQObject(in, QScriptEngine::QtOwnership, QScriptEngine::PreferExistingWrapperObject);
}

static void qtscript_QGraph_fromScriptValue(const QScriptValue &value, QGraph* &out)
{
    out = qobject_cast<QGraph*>(value.toQObject());
}

QScriptValue qtscript_create_QGraph_class(QScriptEngine *engine)
{
    engine->setDefaultPrototype(qMetaTypeId<QGraph*>(), QScriptValue());
    QScriptValue proto = engine->newVariant(qVariantFromValue((QGraph*)0));
    proto.setPrototype(engine->defaultPrototype(qMetaTypeId<QObject*>()));
    for (int i = 0; i < 2; ++i) {
        QScriptValue fun = engine->newFunction(qtscript_QGraph_prototype_call, qtscript_QGraph_function_lengths[i+1]);
        fun.setData(QScriptValue(engine, uint(0xBABE0000 + i)));
        proto.setProperty(QString::fromLatin1(qtscript_QGraph_function_names[i+1]),
            fun, QScriptValue::SkipInEnumeration);
    }

    qScriptRegisterMetaType<QGraph*>(engine, qtscript_QGraph_toScriptValue, 
        qtscript_QGraph_fromScriptValue, proto);

    QScriptValue ctor = engine->newFunction(qtscript_QGraph_static_call, proto, qtscript_QGraph_function_lengths[0]);
    ctor.setData(QScriptValue(engine, uint(0xBABE0000 + 0)));

    return ctor;
}
