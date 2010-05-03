#ifndef QTSCRIPTSHELL_QNODE_H
#define QTSCRIPTSHELL_QNODE_H

#include <QNode.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QNode : public QNode
{
public:
    QtScriptShell_QNode();
    ~QtScriptShell_QNode();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QNODE_H
