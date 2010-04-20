#include "qtscriptshell_QNode.h"

#include <QtScript/QScriptEngine>
#include <QNode.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)


QtScriptShell_QNode::QtScriptShell_QNode()
    : QNode() {}

QtScriptShell_QNode::~QtScriptShell_QNode() {}

