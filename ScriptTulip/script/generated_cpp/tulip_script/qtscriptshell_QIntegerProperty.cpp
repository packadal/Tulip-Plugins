#include "qtscriptshell_QIntegerProperty.h"

#include <QtScript/QScriptEngine>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)


QtScriptShell_QIntegerProperty::QtScriptShell_QIntegerProperty(const QGraph*  arg__1)
    : QIntegerProperty(arg__1) {}

QtScriptShell_QIntegerProperty::~QtScriptShell_QIntegerProperty() {}

