/*
 * utilsTest.h
 *
 *  Created on: 11 déc. 2008
 *      Author: chuet
 */

#ifndef UTILSTEST_H_
#define UTILSTEST_H_

#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptContext>

class QGraph;
class QNode;
class QEdge;

static QGraph* _graph = 0;
static QString _string = 0;
static QNode* _testNode = 0;
static QEdge* _testEdge = 0;


static QScriptValue storeGraph(QScriptContext *context, QScriptEngine*)
{
	_graph = qobject_cast<QGraph*>(context->argument(0).toQObject());
	return QScriptValue();
}

static QScriptValue storeNode(QScriptContext *context, QScriptEngine*)
{
	_testNode = qobject_cast<QNode*>(context->argument(0).toQObject());
	return QScriptValue();
}

static QScriptValue storeEdge(QScriptContext *context, QScriptEngine*)
{
	_testEdge = qobject_cast<QEdge*>(context->argument(0).toQObject());
	return QScriptValue();
}

static QScriptValue storeString(QScriptContext *context, QScriptEngine*)
{
	_string = context->argument(0).toString();
	return QScriptValue();
}

#endif /* UTILSTEST_H_ */
