#include "TulipScriptEngine.h"

#include <QtPlugin>

#include <tulip/QtProgress.h>

#include "Scriptmacros.h"
#include "ScriptFunctions.h"

#include "QNode.h"
#include "QEdge.h"
#include "QGraph.h"
#include "QProperty.h"
#include "QIterator.h"

DECLARE_TYPE_TO_SCRIPT(QGraph)

ScriptFunctions* ScriptFunctions::_instance = 0;

//Q_IMPORT_PLUGIN(qtscript_tulip_script);

TulipScriptEngine::TulipScriptEngine()
:QScriptEngine()
{
	QCoreApplication::addLibraryPath("/net/cremi/chuet/liens/travail/cppProjects/lib");
/*
	QStringList list = availableExtensions();
	foreach(QString s, list)
		std::cout << s.toStdString() << std::endl;*/

	importExtension("tulip.script");
	if(hasUncaughtException())
		std::cout << qPrintable(uncaughtException().toString()) << std::endl;

	std::cout << "coucou1" << std::endl;
	QMap<QString, QScriptEngine::FunctionSignature> functions = ScriptFunctions::getInstance()->getFunctions();
	std::cout << "coucou2" << std::endl;

	QMap<QString, QScriptEngine::FunctionSignature>::const_iterator it = functions.begin();
	while(it != functions.end()) {
		addScriptFunction(it.value(), it.key());
		++it;
	}
	std::cout << "coucou3" << std::endl;

	std::cout << "coucou4" << std::endl;


//	addScriptFunction(loadGraph, "loadGraph");
//	addScriptFunction(saveGraph, "saveGraph");
//	addScriptFunction(applyAlgorithm, "applyAlgorithm");

	addScriptFunction(QGraphFactory, "newGraph");
}

TulipScriptEngine::~TulipScriptEngine() {
	ScriptFunctions::kill();
}

void TulipScriptEngine::addScriptFunction(const FunctionSignature &function, const QString &functionName) {
	QScriptValue ctor = this->newFunction(function);
	this->globalObject().setProperty(functionName, ctor);
}

void TulipScriptEngine::addQObject(QObject* qobject, const QString &objectName){
	QScriptValue value = this->newQObject(qobject);
	this->globalObject().setProperty(objectName,value);
}
