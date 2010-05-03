#ifndef QTSCRIPTSHELL_QEDGE_H
#define QTSCRIPTSHELL_QEDGE_H

#include <QEdge.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QEdge : public QEdge
{
public:
    QtScriptShell_QEdge();
    ~QtScriptShell_QEdge();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QEDGE_H
