#ifndef QTSCRIPTSHELL_QSTRINGPROPERTY_H
#define QTSCRIPTSHELL_QSTRINGPROPERTY_H

#include <QStringProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QStringProperty : public QStringProperty
{
public:
    QtScriptShell_QStringProperty(const QGraph*  arg__1);
    ~QtScriptShell_QStringProperty();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QSTRINGPROPERTY_H
