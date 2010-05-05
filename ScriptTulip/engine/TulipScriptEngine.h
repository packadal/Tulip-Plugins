#ifndef TULIPSCRIPTENGINE_H_
#define TULIPSCRIPTENGINE_H_

#include <QtScript/QScriptEngine>
#include <QtCore/QObject>

#include <tulip/Graph.h>
#include "QGraph.h"

#include "profiler.h"

class TulipScriptEngine : public QScriptEngine {
public:
	TulipScriptEngine();
	virtual ~TulipScriptEngine();
	void addScriptFunction(const FunctionSignature &function, const QString &functionName);
	void addQObject(QObject* qobject, const QString &objectName);
	void setGraph(tlp::Graph* arg1);
	QGraph* getGraph();
  private:
    Profiler* _agent;
    QGraph* _graph;
};

void qtscript_initialize_com_trolltech_qt_core_bindings(QScriptValue &);
void qtscript_initialize_com_trolltech_qt_gui_bindings(QScriptValue &);
void qtscript_initialize_tulip_script_bindings(QScriptValue &);

#endif /* TULIPSCRIPTENGINE_H_ */
