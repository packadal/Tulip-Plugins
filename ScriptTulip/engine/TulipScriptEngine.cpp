#include "TulipScriptEngine.h"

//#include <QtPlugin>

//#include <tulip/QtProgress.h>

#include "Scriptmacros.h"
#include "ScriptFunctions.h"

#include "QNode.h"
#include "QEdge.h"
#include "QGraph.h"
#include "QProperty.h"
#include "QIterator.h"
// #include "TulipScriptEngineAgent.h"

// DECLARE_TYPE_TO_SCRIPT(QGraph)

ScriptFunctions* ScriptFunctions::_instance = 0;

TulipScriptEngine::TulipScriptEngine()
:QScriptEngine()
{
	_agent = new Profiler(this);
	this->setAgent(_agent);
	QScriptValue v = globalObject();
// 	qScriptRegisterMetaType<QProperty>(this, QPropertyToScriptValue, QPropertyFromScriptValue);

	qtscript_initialize_com_trolltech_qt_core_bindings(v);
	qtscript_initialize_com_trolltech_qt_gui_bindings(v);
	qtscript_initialize_tulip_script_bindings(v);
	
	if(this->hasUncaughtException())
		std::cout << qPrintable(uncaughtException().toString()) << std::endl;

	QMap<QString, QScriptEngine::FunctionSignature> functions = ScriptFunctions::getInstance()->getFunctions();

	QMap<QString, QScriptEngine::FunctionSignature>::const_iterator it = functions.begin();
	while(it != functions.end()) {
		addScriptFunction(it.value(), it.key());
		++it;
	}

// 	addScriptFunction(QGraphFactory, "newGraph");
}

TulipScriptEngine::~TulipScriptEngine() {
	delete _agent;
}

void TulipScriptEngine::addScriptFunction(const FunctionSignature &function, const QString &functionName) {
	QScriptValue ctor = this->newFunction(function);
	this->globalObject().setProperty(functionName, ctor);
}

void TulipScriptEngine::addQObject(QObject* qobject, const QString &objectName){
	QScriptValue value = this->newQObject(qobject);
	this->globalObject().setProperty(objectName,value);
}


void TulipScriptEngine::setGraph(tlp::Graph* arg1)
{
	this->_graph = new QGraph(arg1);
	this->addQObject(_graph, "graph");
}

QGraph* TulipScriptEngine::getGraph()
{
  return this->_graph;
}

