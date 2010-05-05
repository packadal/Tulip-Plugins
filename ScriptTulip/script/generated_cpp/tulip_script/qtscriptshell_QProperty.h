#ifndef QTSCRIPTSHELL_QPROPERTY_H
#define QTSCRIPTSHELL_QPROPERTY_H

#include <QProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QProperty : public QProperty
{
public:
    QtScriptShell_QProperty();
    ~QtScriptShell_QProperty();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QPROPERTY_H
