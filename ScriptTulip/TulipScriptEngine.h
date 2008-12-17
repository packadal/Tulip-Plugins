#ifndef TULIPSCRIPTENGINE_H_
#define TULIPSCRIPTENGINE_H_

#include <QScriptEngine>

class TulipScriptEngine : public QScriptEngine {
public:
	TulipScriptEngine();
	virtual ~TulipScriptEngine();
	void addScriptFunction(FunctionSignature function, QString functionName);
};

#endif /* TULIPSCRIPTENGINE_H_ */
