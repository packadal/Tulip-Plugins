/*
 * utilsTest.h
 *
 *  Created on: 11 déc. 2008
 *      Author: chuet
 */

#ifndef UTILSTEST_H_
#define UTILSTEST_H_

class QGraph;
class QScriptContext;
class QScriptEngine;
class QScriptValue;

static QGraph *_graph;

QScriptValue storeGraph(QScriptContext*, QScriptEngine*);

#endif /* UTILSTEST_H_ */
