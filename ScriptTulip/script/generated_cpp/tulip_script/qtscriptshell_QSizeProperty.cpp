#include "qtscriptshell_QSizeProperty.h"

#include <QtScript/QScriptEngine>
#include <QEdge.h>
#include <QGraph.h>
#include <QNode.h>
#include <QProperty.h>
#include <QSize3D.h>
#include <QVariant>

#define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)


QtScriptShell_QSizeProperty::QtScriptShell_QSizeProperty(const QGraph*  arg__1)
    : QSizeProperty(arg__1) {}

QtScriptShell_QSizeProperty::~QtScriptShell_QSizeProperty() {}

