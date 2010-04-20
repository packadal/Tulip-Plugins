#include "qtscriptshell_QGraphProperty.h"

#include <QtScript/QScriptEngine>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)


QtScriptShell_QGraphProperty::QtScriptShell_QGraphProperty(const QGraph*  arg__1)
    : QGraphProperty(arg__1) {}

QtScriptShell_QGraphProperty::~QtScriptShell_QGraphProperty() {}

