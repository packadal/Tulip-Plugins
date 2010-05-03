#ifndef QTSCRIPTSHELL_QSIZE3D_H
#define QTSCRIPTSHELL_QSIZE3D_H

#include <QSize3D.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QSize3D : public QSize3D
{
public:
    QtScriptShell_QSize3D();
    QtScriptShell_QSize3D(float  w, float  h, float  d);
    ~QtScriptShell_QSize3D();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QSIZE3D_H
