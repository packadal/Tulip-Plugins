#ifndef QTSCRIPTSHELL_QBOOLEANPROPERTY_H
#define QTSCRIPTSHELL_QBOOLEANPROPERTY_H

#include <QBooleanProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QBooleanProperty : public QBooleanProperty
{
public:
    QtScriptShell_QBooleanProperty(const QGraph*  arg__1);
    ~QtScriptShell_QBooleanProperty();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QBOOLEANPROPERTY_H
