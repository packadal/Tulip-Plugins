#ifndef QTSCRIPTSHELL_QINTEGERPROPERTY_H
#define QTSCRIPTSHELL_QINTEGERPROPERTY_H

#include <QIntegerProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QIntegerProperty : public QIntegerProperty
{
public:
    QtScriptShell_QIntegerProperty(const QGraph*  arg__1);
    ~QtScriptShell_QIntegerProperty();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QINTEGERPROPERTY_H
