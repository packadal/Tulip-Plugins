#include "qtscriptshell_QStringProperty.h"

#include <QtScript/QScriptEngine>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)


QtScriptShell_QStringProperty::QtScriptShell_QStringProperty(const QGraph*  arg__1)
    : QStringProperty(arg__1) {}

QtScriptShell_QStringProperty::~QtScriptShell_QStringProperty() {}

