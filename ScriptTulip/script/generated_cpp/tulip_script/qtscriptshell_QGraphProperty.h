#ifndef QTSCRIPTSHELL_QGRAPHPROPERTY_H
#define QTSCRIPTSHELL_QGRAPHPROPERTY_H

#include <QGraphProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QGraphProperty : public QGraphProperty
{
public:
    QtScriptShell_QGraphProperty(const QGraph*  arg__1);
    ~QtScriptShell_QGraphProperty();


    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QGRAPHPROPERTY_H
