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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QSlider *horizontalSlider;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(814, 700);
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
        label->setGeometry(QRect(20, 170, 691, 281));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color: #000000;\n"
"\n"
"}"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 460, 90, 50));
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
        groupBox->setGeometry(QRect(20, 10, 671, 141));
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
        pushButton_4->setGeometry(QRect(710, 590, 90, 50));
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
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(150, 460, 511, 22));
        horizontalSlider->setStyleSheet(QStringLiteral(""));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 460, 41, 16));
        label_4->setStyleSheet(QStringLiteral("color :white;"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(670, 460, 41, 16));
        label_5->setStyleSheet(QStringLiteral("color :white;"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 520, 361, 81));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 3px;\n"
" border: 1px solid black;\n"
"}\n"
""));
        groupBox_2->setAlignment(Qt::AlignCenter);
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 20, 70, 17));
        checkBox->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 50, 70, 17));
        checkBox_2->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(100, 20, 70, 17));
        checkBox_3->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(190, 20, 70, 17));
        checkBox_4->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(290, 20, 70, 17));
        checkBox_5->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(100, 50, 70, 17));
        checkBox_6->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_7 = new QCheckBox(groupBox_2);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));
        checkBox_7->setGeometry(QRect(190, 50, 70, 17));
        checkBox_7->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));
        checkBox_8->setGeometry(QRect(290, 50, 70, 17));
        checkBox_8->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(390, 520, 301, 81));
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 3px;\n"
" border: 1px solid black;\n"
"}\n"
""));
        groupBox_3->setAlignment(Qt::AlignCenter);
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 20, 71, 41));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(70, 30));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 8px;\n"
"border: 1px solid;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icon_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(23, 23));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 40, 201, 20));
        lineEdit_3->setStyleSheet(QStringLiteral("border-radius: 8px;"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 20, 71, 16));
        label_6->setStyleSheet(QStringLiteral("color :white;"));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(670, 450, 51, 41));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;;\n"
"border: 1px solid;\n"
"}\n"
"QToolTip { color: #fff; background-color: #000; border: none; }"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/full-screen-icon-png-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon4);
        pushButton_6->setIconSize(QSize(50, 50));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 814, 21));
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
        label_4->setText(QString());
        label_5->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Data Penerbangan", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Waktu", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "Kecepatan", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow", "Altitude", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow", "Longitude", nullptr));
        checkBox_5->setText(QApplication::translate("MainWindow", "Latitude", nullptr));
        checkBox_6->setText(QApplication::translate("MainWindow", "Roll", nullptr));
        checkBox_7->setText(QApplication::translate("MainWindow", "Pitch", nullptr));
        checkBox_8->setText(QApplication::translate("MainWindow", "Yaw", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Simpan Video", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Save", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Lokasi Berkas", nullptr));
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
