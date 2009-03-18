#include "scripttulip.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScriptTulip w;
    w.show();
    return a.exec();
}
