#ifndef QTSCRIPTSHELL_QDOUBLEPROPERTY_H
#define QTSCRIPTSHELL_QDOUBLEPROPERTY_H

#include <QDoubleProperty.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QDoubleProperty : public QDoubleProperty
{
public:
    QtScriptShell_QDoubleProperty(const QGraph*  g);
    ~QtScriptShell_QDoubleProperty();


    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QDOUBLEPROPERTY_H
