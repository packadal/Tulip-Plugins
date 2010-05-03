#ifndef QTSCRIPTSHELL_QSIZEPROPERTY_H
#define QTSCRIPTSHELL_QSIZEPROPERTY_H

#include <QSizeProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QSizeProperty : public QSizeProperty
{
public:
    QtScriptShell_QSizeProperty(const QGraph*  arg__1);
    ~QtScriptShell_QSizeProperty();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QSIZEPROPERTY_H
