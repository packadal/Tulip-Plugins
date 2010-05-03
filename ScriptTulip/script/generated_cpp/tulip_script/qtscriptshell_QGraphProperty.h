#ifndef QTSCRIPTSHELL_QGRAPHPROPERTY_H
#define QTSCRIPTSHELL_QGRAPHPROPERTY_H

#include <QGraphProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QGraphProperty : public QGraphProperty
{
public:
    QtScriptShell_QGraphProperty(const QGraph*  arg__1);
    ~QtScriptShell_QGraphProperty();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QGRAPHPROPERTY_H
