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
#include "QGraph.h"

static QGraph* _graph = 0;

static QScriptValue storeGraph(QScriptContext *context, QScriptEngine*)
{
	_graph = qobject_cast<QGraph*>(context->argument(0).toQObject());
	return QScriptValue();
}
#endif /* UTILSTEST_H_ */
