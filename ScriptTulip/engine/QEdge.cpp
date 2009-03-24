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
:_edge(tlp::edge())
{
}

QEdge::QEdge(tlp::edge e)
:_edge(e)
{
}

QEdge::~QEdge() {
}
