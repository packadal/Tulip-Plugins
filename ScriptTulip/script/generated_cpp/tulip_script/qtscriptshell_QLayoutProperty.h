#ifndef QTSCRIPTSHELL_QLAYOUTPROPERTY_H
#define QTSCRIPTSHELL_QLAYOUTPROPERTY_H

#include <QLayoutProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QLayoutProperty : public QLayoutProperty
{
public:
    QtScriptShell_QLayoutProperty(const QGraph*  arg__1);
    ~QtScriptShell_QLayoutProperty();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QLAYOUTPROPERTY_H
