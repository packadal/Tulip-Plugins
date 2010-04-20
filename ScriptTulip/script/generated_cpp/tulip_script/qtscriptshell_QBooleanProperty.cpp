#include "qtscriptshell_QBooleanProperty.h"

#include <QtScript/QScriptEngine>
#include <QEdge.h>
#include <QGraph.h>
#include <QIterator.h>
#include <QNode.h>
#include <QProperty.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)


QtScriptShell_QBooleanProperty::QtScriptShell_QBooleanProperty(const QGraph*  arg__1)
    : QBooleanProperty(arg__1) {}

QtScriptShell_QBooleanProperty::~QtScriptShell_QBooleanProperty() {}

