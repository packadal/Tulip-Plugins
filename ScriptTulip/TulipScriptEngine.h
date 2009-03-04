#ifndef TULIPSCRIPTENGINE_H_
#define TULIPSCRIPTENGINE_H_

#include <QScriptEngine>
#include <QObject>

class TulipScriptEngine : public QScriptEngine {
public:
	TulipScriptEngine();
	virtual ~TulipScriptEngine();
	void addScriptFunction(const FunctionSignature &function, const QString &functionName);
	void addQObject(QObject* qobject, const QString &objectName);
};

#endif /* TULIPSCRIPTENGINE_H_ */
