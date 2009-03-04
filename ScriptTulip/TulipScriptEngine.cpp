#include "TulipScriptEngine.h"

#include <QtPlugin>

#include <tulip/QtProgress.h>

#include "Scriptmacros.h"

#include "QNode.h"
#include "QEdge.h"
#include "QGraph.h"
#include "QProperty.h"
#include "QIterator.h"

DECLARE_TYPE_TO_SCRIPT(QGraph)

//Q_IMPORT_PLUGIN(qtscript_tulip_script)

TulipScriptEngine::TulipScriptEngine()
:QScriptEngine()
{
	QCoreApplication::addLibraryPath("/net/cremi/chuet/liens/travail/cppProjects/lib");

	importExtension("tulip.script");
	if(hasUncaughtException())
		std::cout << "an error occured when trying to load the module" << qPrintable(uncaughtException().toString()) << std::endl;


	addScriptFunction(applyAlgorithm, "applyAlgorithm");

	addScriptFunction(QGraphFactory, "newGraph");
	addScriptFunction(saveGraph, "saveGraph");
	addScriptFunction(loadGraph, "loadGraph");
}

TulipScriptEngine::~TulipScriptEngine() {

}

void TulipScriptEngine::addScriptFunction(const FunctionSignature &function, const QString &functionName) {
	QScriptValue ctor = this->newFunction(function);
	this->globalObject().setProperty(functionName, ctor);
}

void TulipScriptEngine::addQObject(QObject* qobject, const QString &objectName){
	QScriptValue value = this->newQObject(qobject);
	this->globalObject().setProperty(objectName,value);
}
