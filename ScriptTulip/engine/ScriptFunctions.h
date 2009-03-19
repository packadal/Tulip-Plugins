/*
 * ScriptFunctions.h
 *
 *  Created on: 9 mars 2009
 *      Author: chuet
 */

#ifndef SCRIPTFUNCTIONS_H_
#define SCRIPTFUNCTIONS_H_

#include <QtScript/QScriptEngine>
#include <QtCore/QMap>

#define INSERT(ARG) insert(#ARG, ARG)

class ScriptFunctions {
public:
        static ScriptFunctions* getInstance() { if(_instance == 0) _instance = new ScriptFunctions; return _instance; }
        static void kill() { delete _instance; }

        void addFunction(QString name, QScriptEngine::FunctionSignature fun) { _functions.insert(name, fun); }
        QMap<QString, QScriptEngine::FunctionSignature> getFunctions() const { return  _functions; }
private:
        ScriptFunctions() {}
        ~ScriptFunctions() {}

        QMap<QString, QScriptEngine::FunctionSignature> _functions;
        static ScriptFunctions* _instance;
};

#define ADD_FUNCTION(FUN) addFunction scriptFunction_##FUN(#FUN, FUN)

class addFunction {
public:
        addFunction(QString name, QScriptEngine::FunctionSignature fun) {
                ScriptFunctions::getInstance()->addFunction(name, fun);
        }
};

#endif /* SCRIPTFUNCTIONS_H_ */

