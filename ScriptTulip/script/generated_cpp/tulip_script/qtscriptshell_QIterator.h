#ifndef QTSCRIPTSHELL_QITERATOR_H
#define QTSCRIPTSHELL_QITERATOR_H

#include <QIterator.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QIterator : public QIterator
{
public:
    ~QtScriptShell_QIterator();


    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QITERATOR_H
