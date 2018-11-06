/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QStringLiteral("SecDialog"));
        SecDialog->resize(686, 495);
        label = new QLabel(SecDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 431, 441));
        label->setAutoFillBackground(true);
        label->setScaledContents(true);
        pushButton = new QPushButton(SecDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 40, 91, 31));
        pushButton_2 = new QPushButton(SecDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 100, 91, 31));
        pushButton_3 = new QPushButton(SecDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(530, 160, 91, 31));
        pushButton_4 = new QPushButton(SecDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(530, 220, 91, 31));

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QApplication::translate("SecDialog", "Dialog", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("SecDialog", "Display", nullptr));
        pushButton_2->setText(QApplication::translate("SecDialog", "Start Processing", nullptr));
        pushButton_3->setText(QApplication::translate("SecDialog", "Get Video", nullptr));
        pushButton_4->setText(QApplication::translate("SecDialog", "Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
