#ifndef QTSCRIPTSHELL_QPROPERTY_H
#define QTSCRIPTSHELL_QPROPERTY_H

#include <QProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QProperty : public QProperty
{
public:
    ~QtScriptShell_QProperty();


    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QPROPERTY_H
