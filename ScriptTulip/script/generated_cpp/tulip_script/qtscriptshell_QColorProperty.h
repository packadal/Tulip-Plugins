#ifndef QTSCRIPTSHELL_QCOLORPROPERTY_H
#define QTSCRIPTSHELL_QCOLORPROPERTY_H

#include <QColorProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QColorProperty : public QColorProperty
{
public:
    QtScriptShell_QColorProperty(const QGraph*  arg__1);
    ~QtScriptShell_QColorProperty();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QCOLORPROPERTY_H
