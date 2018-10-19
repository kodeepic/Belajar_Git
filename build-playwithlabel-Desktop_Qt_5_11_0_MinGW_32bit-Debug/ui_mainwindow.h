/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 700));
        MainWindow->setStyleSheet(QLatin1String("#centralWidget { background:rgba(0,0,0,220);}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 180, 701, 321));
        label->setStyleSheet(QStringLiteral("Background-color: #000;"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 510, 90, 50));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(90, 50));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 8px;\n"
"border: 1px solid;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon_control_paly.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(23, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 721, 151));
        groupBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 20px;\n"
" border: 1px solid black;\n"
"}"));
        groupBox->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 80, 90, 50));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(90, 50));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 8px;\n"
"border: 1px solid;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icon_folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(23, 23));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 90, 50));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(90, 50));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 8px;\n"
"border: 1px solid;\n"
"}"));
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(23, 23));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 20, 101, 16));
        label_2->setStyleSheet(QStringLiteral("color :white;"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 40, 501, 21));
        lineEdit->setStyleSheet(QStringLiteral("border-radius: 8px;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 80, 91, 16));
        label_3->setStyleSheet(QStringLiteral("color :white;"));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 100, 501, 20));
        lineEdit_2->setStyleSheet(QStringLiteral("border-radius: 8px;"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(660, 590, 90, 50));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(90, 50));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 10px;\n"
"border: 1px solid;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(23, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Putar Video", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Unggah Berkas", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Buka Data", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Buka Video", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Lokasi Berkas Video</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Lokasi Berkas Data", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Keluar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
