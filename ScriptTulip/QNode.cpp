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
:_node(new tlp::node())
{
}

QNode::QNode(const tlp::node& n)
{
	tlp::node* n2 = new tlp::node();
	n2->id = n.id;
	_node = n2;
}

QNode::~QNode() {
}

QScriptValue nodeFactory(QScriptContext*, QScriptEngine *engine)
{
    QObject *node = new QNode();
    return engine->newQObject(node, QScriptEngine::ScriptOwnership);
}
