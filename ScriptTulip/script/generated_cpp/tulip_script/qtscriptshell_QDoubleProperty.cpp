#include "qtscriptshell_QDoubleProperty.h"

#include <QtScript/QScriptEngine>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)


QtScriptShell_QDoubleProperty::QtScriptShell_QDoubleProperty(const QGraph*  g)
    : QDoubleProperty(g) {}

QtScriptShell_QDoubleProperty::~QtScriptShell_QDoubleProperty() {}

