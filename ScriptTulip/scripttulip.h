#ifndef SCRIPTTULIP_H
#define SCRIPTTULIP_H

#include <QtGui/QWidget>
#include "ui_scripttulip.h"

class ScriptTulip : public QWidget
{
    Q_OBJECT

public:
    ScriptTulip(QWidget *parent = 0);
    ~ScriptTulip();

private:
    Ui::ScriptTulipClass ui;
};

#endif // SCRIPTTULIP_H
