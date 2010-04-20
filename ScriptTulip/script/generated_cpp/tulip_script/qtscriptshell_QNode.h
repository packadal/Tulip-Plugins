#ifndef QTSCRIPTSHELL_QNODE_H
#define QTSCRIPTSHELL_QNODE_H

#include <QNode.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QNode : public QNode
{
public:
    QtScriptShell_QNode();
    ~QtScriptShell_QNode();


    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QNODE_H
