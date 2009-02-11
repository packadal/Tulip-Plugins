#include "TulipScriptEngine.h"
#include "Scriptmacros.h"

#include "QNode.h"
#include "QEdge.h"
#include "QGraph.h"
#include "QProperty.h"
#include "QIterator.h"

DECLARE_TYPE_TO_SCRIPT(QGraph)
DECLARE_TYPE_TO_SCRIPT(QProperty)
DECLARE_TYPE_TO_SCRIPT(QNode)
DECLARE_TYPE_TO_SCRIPT(QEdge)
DECLARE_TYPE_TO_SCRIPT(QIterator)


TulipScriptEngine::TulipScriptEngine()
:QScriptEngine()
{
	EXPORT_TYPE_TO_SCRIPT(QNode);
	EXPORT_TYPE_TO_SCRIPT(QEdge);
	EXPORT_TYPE_TO_SCRIPT(QGraph);
	EXPORT_TYPE_TO_SCRIPT(QProperty);
	EXPORT_TYPE_TO_SCRIPT(QIterator);

	addScriptFunction(QGraphFactory, "newGraph");
	addScriptFunction(saveGraph, "saveGraph");
	addScriptFunction(loadGraph, "loadGraph");
}

TulipScriptEngine::~TulipScriptEngine() {

}

void TulipScriptEngine::addScriptFunction(FunctionSignature function, QString functionName) {
	QScriptValue ctor = this->newFunction(function);
	this->globalObject().setProperty(functionName, ctor);
}

void TulipScriptEngine::addQObject(QObject* qobject, QString objectName){
	QScriptValue value = this->newQObject(qobject);
	this->globalObject().setProperty(objectName,value);
}
