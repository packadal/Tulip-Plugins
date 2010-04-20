#include "qtscriptshell_QGraph.h"

#include <QtScript/QScriptEngine>
#include <QBooleanProperty.h>
#include <QColorProperty.h>
#include <QDoubleProperty.h>
#include <QEdge.h>
#include <QGraph.h>
#include <QGraphProperty.h>
#include <QIntegerProperty.h>
#include <QIterator.h>
#include <QNode.h>
#include <QProperty.h>
#include <QSizeProperty.h>
#include <QStringProperty.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)

Q_DECLARE_METATYPE(QNode*)
Q_DECLARE_METATYPE(QEdge*)
Q_DECLARE_METATYPE(QIterator*)

QtScriptShell_QGraph::QtScriptShell_QGraph()
    : QGraph() {}

QtScriptShell_QGraph::~QtScriptShell_QGraph() {}

bool  QtScriptShell_QGraph::canPop()
{
    QScriptValue _q_function = __qtscript_self.property("canPop");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("canPop") & QScriptValue::QObjectMember)) {
        return QGraph::canPop();
    } else {
        return qscriptvalue_cast<bool >(_q_function.call(__qtscript_self));
    }
}

bool  QtScriptShell_QGraph::canUnpop()
{
    QScriptValue _q_function = __qtscript_self.property("canUnpop");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("canUnpop") & QScriptValue::QObjectMember)) {
        return QGraph::canUnpop();
    } else {
        return qscriptvalue_cast<bool >(_q_function.call(__qtscript_self));
    }
}

unsigned int  QtScriptShell_QGraph::deg(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("deg");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("deg") & QScriptValue::QObjectMember)) {
        return QGraph::deg(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<unsigned int >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

QEdge*  QtScriptShell_QGraph::existEdge(const QNode*  arg__1, const QNode*  arg__2) const
{
    QScriptValue _q_function = __qtscript_self.property("existEdge");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("existEdge") & QScriptValue::QObjectMember)) {
        return QGraph::existEdge(arg__1, arg__2);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QEdge* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__2))));
    }
}

QIterator*  QtScriptShell_QGraph::getEdges() const
{
    QScriptValue _q_function = __qtscript_self.property("getEdges");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getEdges") & QScriptValue::QObjectMember)) {
        return QGraph::getEdges();
    } else {
        return qscriptvalue_cast<QIterator* >(_q_function.call(__qtscript_self));
    }
}

QIterator*  QtScriptShell_QGraph::getInEdges(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("getInEdges");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getInEdges") & QScriptValue::QObjectMember)) {
        return QGraph::getInEdges(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QIterator* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

QNode*  QtScriptShell_QGraph::getInNode(const QNode*  arg__1, unsigned int  arg__2) const
{
    QScriptValue _q_function = __qtscript_self.property("getInNode");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getInNode") & QScriptValue::QObjectMember)) {
        return QGraph::getInNode(arg__1, arg__2);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QNode* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))
            << qScriptValueFromValue(_q_engine, arg__2)));
    }
}

QIterator*  QtScriptShell_QGraph::getInNodes(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("getInNodes");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getInNodes") & QScriptValue::QObjectMember)) {
        return QGraph::getInNodes(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QIterator* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

QIterator*  QtScriptShell_QGraph::getInOutEdges(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("getInOutEdges");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getInOutEdges") & QScriptValue::QObjectMember)) {
        return QGraph::getInOutEdges(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QIterator* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

QIterator*  QtScriptShell_QGraph::getInOutNodes(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("getInOutNodes");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getInOutNodes") & QScriptValue::QObjectMember)) {
        return QGraph::getInOutNodes(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QIterator* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

QIterator*  QtScriptShell_QGraph::getNodes() const
{
    QScriptValue _q_function = __qtscript_self.property("getNodes");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getNodes") & QScriptValue::QObjectMember)) {
        return QGraph::getNodes();
    } else {
        return qscriptvalue_cast<QIterator* >(_q_function.call(__qtscript_self));
    }
}

QEdge*  QtScriptShell_QGraph::getOneEdge() const
{
    QScriptValue _q_function = __qtscript_self.property("getOneEdge");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getOneEdge") & QScriptValue::QObjectMember)) {
        return QGraph::getOneEdge();
    } else {
        return qscriptvalue_cast<QEdge* >(_q_function.call(__qtscript_self));
    }
}

QNode*  QtScriptShell_QGraph::getOneNode() const
{
    QScriptValue _q_function = __qtscript_self.property("getOneNode");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getOneNode") & QScriptValue::QObjectMember)) {
        return QGraph::getOneNode();
    } else {
        return qscriptvalue_cast<QNode* >(_q_function.call(__qtscript_self));
    }
}

QIterator*  QtScriptShell_QGraph::getOutEdges(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("getOutEdges");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getOutEdges") & QScriptValue::QObjectMember)) {
        return QGraph::getOutEdges(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QIterator* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

QNode*  QtScriptShell_QGraph::getOutNode(const QNode*  arg__1, unsigned int  arg__2) const
{
    QScriptValue _q_function = __qtscript_self.property("getOutNode");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getOutNode") & QScriptValue::QObjectMember)) {
        return QGraph::getOutNode(arg__1, arg__2);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QNode* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))
            << qScriptValueFromValue(_q_engine, arg__2)));
    }
}

QIterator*  QtScriptShell_QGraph::getOutNodes(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("getOutNodes");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("getOutNodes") & QScriptValue::QObjectMember)) {
        return QGraph::getOutNodes(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QIterator* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

unsigned int  QtScriptShell_QGraph::indeg(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("indeg");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("indeg") & QScriptValue::QObjectMember)) {
        return QGraph::indeg(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<unsigned int >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

bool  QtScriptShell_QGraph::isElement(const QEdge*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("isElement");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("isElement") & QScriptValue::QObjectMember)) {
        return QGraph::isElement(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<bool >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QEdge *>(arg__1))));
    }
}

bool  QtScriptShell_QGraph::isElement(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("isElement");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("isElement") & QScriptValue::QObjectMember)) {
        return QGraph::isElement(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<bool >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

bool  QtScriptShell_QGraph::isMetaEdge(const QEdge*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("isMetaEdge");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("isMetaEdge") & QScriptValue::QObjectMember)) {
        return QGraph::isMetaEdge(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<bool >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QEdge *>(arg__1))));
    }
}

bool  QtScriptShell_QGraph::isMetaNode(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("isMetaNode");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("isMetaNode") & QScriptValue::QObjectMember)) {
        return QGraph::isMetaNode(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<bool >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

unsigned int  QtScriptShell_QGraph::numberOfEdges() const
{
    QScriptValue _q_function = __qtscript_self.property("numberOfEdges");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("numberOfEdges") & QScriptValue::QObjectMember)) {
        return QGraph::numberOfEdges();
    } else {
        return qscriptvalue_cast<unsigned int >(_q_function.call(__qtscript_self));
    }
}

unsigned int  QtScriptShell_QGraph::numberOfNodes() const
{
    QScriptValue _q_function = __qtscript_self.property("numberOfNodes");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("numberOfNodes") & QScriptValue::QObjectMember)) {
        return QGraph::numberOfNodes();
    } else {
        return qscriptvalue_cast<unsigned int >(_q_function.call(__qtscript_self));
    }
}

QNode*  QtScriptShell_QGraph::opposite(const QEdge*  arg__1, const QNode*  arg__2) const
{
    QScriptValue _q_function = __qtscript_self.property("opposite");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("opposite") & QScriptValue::QObjectMember)) {
        return QGraph::opposite(arg__1, arg__2);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QNode* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QEdge *>(arg__1))
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__2))));
    }
}

unsigned int  QtScriptShell_QGraph::outdeg(const QNode*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("outdeg");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("outdeg") & QScriptValue::QObjectMember)) {
        return QGraph::outdeg(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<unsigned int >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QNode *>(arg__1))));
    }
}

void QtScriptShell_QGraph::pop()
{
    QScriptValue _q_function = __qtscript_self.property("pop");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("pop") & QScriptValue::QObjectMember)) {
        QGraph::pop();
    } else {
        _q_function.call(__qtscript_self);
    }
}

void QtScriptShell_QGraph::push()
{
    QScriptValue _q_function = __qtscript_self.property("push");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("push") & QScriptValue::QObjectMember)) {
        QGraph::push();
    } else {
        _q_function.call(__qtscript_self);
    }
}

QNode*  QtScriptShell_QGraph::source(const QEdge*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("source");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("source") & QScriptValue::QObjectMember)) {
        return QGraph::source(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QNode* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QEdge *>(arg__1))));
    }
}

QNode*  QtScriptShell_QGraph::target(const QEdge*  arg__1) const
{
    QScriptValue _q_function = __qtscript_self.property("target");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("target") & QScriptValue::QObjectMember)) {
        return QGraph::target(arg__1);
    } else {
        QScriptEngine *_q_engine = __qtscript_self.engine();
        return qscriptvalue_cast<QNode* >(_q_function.call(__qtscript_self,
            QScriptValueList()
            << qScriptValueFromValue(_q_engine, const_cast<QEdge *>(arg__1))));
    }
}

void QtScriptShell_QGraph::unpop()
{
    QScriptValue _q_function = __qtscript_self.property("unpop");
    if (!_q_function.isFunction() || QTSCRIPT_IS_GENERATED_FUNCTION(_q_function)
        || (__qtscript_self.propertyFlags("unpop") & QScriptValue::QObjectMember)) {
        QGraph::unpop();
    } else {
        _q_function.call(__qtscript_self);
    }
}

