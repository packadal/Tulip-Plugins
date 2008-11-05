/********************************************************************************
** Form generated from reading ui file 'ScriptViewer.ui'
**
** Created: Wed Nov 5 15:11:19 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SCRIPTVIEWER_H
#define UI_SCRIPTVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tulip_pluginsClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *tulip_pluginsClass)
    {
    if (tulip_pluginsClass->objectName().isEmpty())
        tulip_pluginsClass->setObjectName(QString::fromUtf8("tulip_pluginsClass"));
    tulip_pluginsClass->resize(538, 525);
    verticalLayout_3 = new QVBoxLayout(tulip_pluginsClass);
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setMargin(11);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    frame = new QFrame(tulip_pluginsClass);
    frame->setObjectName(QString::fromUtf8("frame"));
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
    frame->setSizePolicy(sizePolicy);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    verticalLayout_2 = new QVBoxLayout(frame);
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setMargin(11);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

    verticalLayout_2->addLayout(verticalLayout);


    verticalLayout_3->addWidget(frame);

    textEdit = new QTextEdit(tulip_pluginsClass);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));

    verticalLayout_3->addWidget(textEdit);

    label = new QLabel(tulip_pluginsClass);
    label->setObjectName(QString::fromUtf8("label"));
    QPalette palette;
    QBrush brush(QColor(255, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(239, 0, 0, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    QBrush brush2(QColor(255, 103, 103, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Light, brush2);
    QBrush brush3(QColor(247, 51, 51, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
    QBrush brush4(QColor(119, 0, 0, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
    QBrush brush5(QColor(159, 0, 0, 255));
    brush5.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    QBrush brush6(QColor(255, 255, 255, 255));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Active, QPalette::Base, brush6);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    QBrush brush7(QColor(0, 0, 0, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
    QBrush brush8(QColor(247, 127, 127, 255));
    brush8.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
    QBrush brush9(QColor(255, 255, 220, 255));
    brush9.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
    palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
    palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
    palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
    label->setPalette(palette);

    verticalLayout_3->addWidget(label);

    pushButton = new QPushButton(tulip_pluginsClass);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    verticalLayout_3->addWidget(pushButton);


    retranslateUi(tulip_pluginsClass);

    QMetaObject::connectSlotsByName(tulip_pluginsClass);
    } // setupUi

    void retranslateUi(QWidget *tulip_pluginsClass)
    {
    tulip_pluginsClass->setWindowTitle(QApplication::translate("tulip_pluginsClass", "tulip_plugins", 0, QApplication::UnicodeUTF8));
    label->setText(QString());
    pushButton->setText(QApplication::translate("tulip_pluginsClass", "PushButton", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tulip_pluginsClass);
    } // retranslateUi

};

namespace Ui {
    class tulip_pluginsClass: public Ui_tulip_pluginsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTVIEWER_H
