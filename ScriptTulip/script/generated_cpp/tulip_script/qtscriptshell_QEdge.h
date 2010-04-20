#ifndef QTSCRIPTSHELL_QEDGE_H
#define QTSCRIPTSHELL_QEDGE_H

#include <QEdge.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QEdge : public QEdge
{
public:
    QtScriptShell_QEdge();
    ~QtScriptShell_QEdge();


    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QEDGE_H
