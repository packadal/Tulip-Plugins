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
#include <QtScript/QScriptValueIterator>

ScriptFunctions* ScriptFunctions::_instance = 0;

TulipScriptEngine::TulipScriptEngine()
:QScriptEngine(), _graph(new QGraph(tlp::newGraph()))
{
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
  delete _graph;
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

tlp::DataSet TulipScriptEngine::DataSetFromQScriptValue(const QScriptValue& dataSet) {
  tlp::DataSet set;
  QScriptValueIterator it(dataSet);
  while(it.hasNext()) {
    it.next();
    //std::cout << it.name().toStdString() << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;borderWidth
    std::string name(it.name().toStdString());
    QVariant value = it.value().toVariant();
    
    if(it.value().isBool()) {
      set.set<bool>(name, value.toBool());
//       std::cout << "setting : " << name << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
    }
    else if(it.value().isString()) {
//       std::cout << "setting : " << name << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      set.set<std::string>(name, it.value().toString().toStdString());
    }
    else if(it.value().isNumber()) {
//       std::cout << "setting : " << name << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      set.set<int>(name, value.toInt());
    }
    else if(it.value().isArray()) {
      QList<QVariant> list = it.value().toVariant().toList();
      if(list.at(0).type() == QVariant::String)
      {
	tlp::StringCollection stringCollection;
	foreach(QVariant var, list)
	{
	  stringCollection.push_back(var.toString().toStdString());
	}
	set.set<tlp::StringCollection>(name, stringCollection);
      }
    }
    else if(it.value().isQObject()) {
//       std::cout << name << ": QObject." << std::endl;
      QObject* object = it.value().toQObject();
//       std::cout << object->metaObject()->className() << std::endl;
      
      if(object->metaObject()->className() == "QProperty") {
// 	std::cout << "not setting anything : " << name << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      }
      else if(object->metaObject()->className() == QString("QDoubleProperty")) {
	tlp::DoubleProperty* prop = qobject_cast<QDoubleProperty*>(object)->asProperty();
	set.set<tlp::DoubleProperty*>(name, prop);
// 	std::cout << "setting : " << name << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      }
    }
    else if(it.value().isObject()) {
//       std::cout << name << ": object(" << it.flags() << ")." << std::endl;
      if(value.type() == QVariant::Color) {
	QColor c = value.value<QColor>();
	tlp::Color col = tlp::Color(c.red(), c.green(), c.blue(), c.alpha());
	set.set<tlp::Color>(name, col);
	std::cout << "setting : " << name << ": (" << c.red() << "," << c.green() << "," <<  c.blue() << "," << c.alpha() << ")" << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      }
//       else if(value.type() == QVariant::String)
//       {
// 	QString str = value.value<QString>();
// 	set.set<std::string>(name.toStdString(), str.toStdString());
// 	std::cout << "setting : " << it.name().toStdString() << ": " << str.toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
//       }
      else {
	tlp::DataSet innerSet(DataSetFromQScriptValue(it.value()));
	set.set<tlp::DataSet>(name, innerSet);
// 	std::cout << "setting : " << name << ": (dataSet)" << std::endl;
      }
    }
    else {
      std::cout << name << ": unknown type when importing from DataSet." << std::endl;
    }
  }

  return set;
}
