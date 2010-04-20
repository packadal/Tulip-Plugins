#include "qtscriptshell_QColorProperty.h"

#include <QtScript/QScriptEngine>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)


QtScriptShell_QColorProperty::QtScriptShell_QColorProperty(const QGraph*  arg__1)
    : QColorProperty(arg__1) {}

QtScriptShell_QColorProperty::~QtScriptShell_QColorProperty() {}

