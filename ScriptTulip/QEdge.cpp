/*
 * QEdge.cpp
 *
 *  Created on: 10-déc-08
 *      Author: dmothes
 */

#include "QEdge.h"

#include <QtScript/QScriptValue>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptEngine>

QEdge::QEdge()
:_edge(new tlp::edge())
{
}

QEdge::QEdge(const tlp::edge& e)
:QObject(new QObject())
{
	tlp::edge* e2 = new tlp::edge();
	e2->id = e.id;
	_edge = e2;
}

QEdge::~QEdge() {
}

QScriptValue edgeFactory(QScriptContext*, QScriptEngine *engine)
{
    QObject *edge = new QEdge();
    return engine->newQObject(edge);
}
