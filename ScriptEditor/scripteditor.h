#ifndef SCRIPTEDITOR_H
#define SCRIPTEDITOR_H

#include <QtGui/QWidget>
#include <QtScript>

#include "ui_scripteditor.h"
#include <iostream>

class ScriptEditor : public QWidget
{
    Q_OBJECT

public:
    ScriptEditor(QWidget *parent = 0);
    ~ScriptEditor();

    void show() { QWidget::show(); }
    inline QScriptEngine* getEngine() { return _engine; }

public slots:
    void evaluate();
    void check();
    void refresh();

private:
    Ui::ScriptEditorClass ui;
    QScriptEngine* _engine;
    //QWidget* _view;
};

#endif // SCRIPTEDITOR_H
