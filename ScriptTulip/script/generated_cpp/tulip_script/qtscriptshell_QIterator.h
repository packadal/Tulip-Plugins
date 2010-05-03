#ifndef QTSCRIPTSHELL_QITERATOR_H
#define QTSCRIPTSHELL_QITERATOR_H

#include <QIterator.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QIterator : public QIterator
{
public:
    ~QtScriptShell_QIterator();

    void childEvent(QChildEvent*  arg__1);
    void customEvent(QEvent*  arg__1);
    bool  event(QEvent*  arg__1);
    bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
    void timerEvent(QTimerEvent*  arg__1);

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QITERATOR_H
