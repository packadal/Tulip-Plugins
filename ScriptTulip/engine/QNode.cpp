/*
 * QNode.cpp
 *
 *  Created on: 10-déc-08
 *      Author: dmothes
 */

#include "QNode.h"

#include <QtScript/QScriptValue>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptEngine>

QNode::QNode()
:_node(tlp::node())
{
}

QNode::QNode(tlp::node n)
:_node(n)
{
}

QNode::~QNode() {
}

QScriptValue nodeFactory(QScriptContext*, QScriptEngine *engine)
{
    QObject *node = new QNode();
    return engine->newQObject(node, QScriptEngine::ScriptOwnership);
}