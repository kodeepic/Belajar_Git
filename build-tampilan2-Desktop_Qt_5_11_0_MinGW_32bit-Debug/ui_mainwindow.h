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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QProgressBar *progressBar;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QProgressBar *progressBar_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(757, 538);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(700, 520));
        MainWindow->setStyleSheet(QLatin1String("#centralWidget { background:rgba(0,0,0,220);}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(700, 150));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 3px;\n"
" border: 1px solid black;\n"
"}"));
        groupBox->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 40, 91, 41));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 3px;\n"
"border: 1px solid;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon_folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(25, 25));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 50, 361, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 30, 61, 16));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"color: white;}"));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(580, 50, 118, 21));
        progressBar->setValue(0);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 100, 91, 41));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 3px;\n"
"border: 1px solid;\n"
"}"));
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(25, 25));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 80, 61, 16));
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"color: white;}"));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 110, 361, 21));
        progressBar_2 = new QProgressBar(groupBox);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(580, 110, 118, 21));
        progressBar_2->setValue(0);

        horizontalLayout->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(700, 150));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 3px;\n"
" border: 1px solid black;\n"
"}"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(60, 30, 70, 17));
        checkBox->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(60, 60, 70, 17));
        checkBox_2->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(60, 90, 70, 17));
        checkBox_3->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(220, 30, 70, 17));
        checkBox_4->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(220, 60, 70, 17));
        checkBox_5->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(220, 90, 70, 17));
        checkBox_6->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_7 = new QCheckBox(groupBox_2);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));
        checkBox_7->setGeometry(QRect(370, 30, 70, 17));
        checkBox_7->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));
        checkBox_8->setGeometry(QRect(370, 60, 70, 17));
        checkBox_8->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_9 = new QCheckBox(groupBox_2);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));
        checkBox_9->setGeometry(QRect(370, 90, 70, 17));
        checkBox_9->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_10 = new QCheckBox(groupBox_2);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));
        checkBox_10->setGeometry(QRect(520, 30, 81, 17));
        checkBox_10->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_11 = new QCheckBox(groupBox_2);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));
        checkBox_11->setGeometry(QRect(520, 60, 91, 17));
        checkBox_11->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));
        checkBox_12 = new QCheckBox(groupBox_2);
        checkBox_12->setObjectName(QStringLiteral("checkBox_12"));
        checkBox_12->setGeometry(QRect(520, 90, 70, 17));
        checkBox_12->setStyleSheet(QStringLiteral("QCheckBox{color:white;}"));

        horizontalLayout_2->addWidget(groupBox_2);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(70, 50));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 3px;\n"
"border: 1px solid;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(23, 23));

        horizontalLayout_3->addWidget(pushButton_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(70, 50));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: #333333;\n"
"border-width: 0px;\n"
"border-radius: 3px;\n"
"border: 1px solid;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icon_next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(23, 23));

        horizontalLayout_3->addWidget(pushButton_3);

        horizontalSpacer_7 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 757, 21));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "Data Uploading", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Open Video", nullptr));
        label->setText(QApplication::translate("MainWindow", "File Location", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Open Data", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "File Location", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Select Data", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Time", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "Velocity", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow", "Battery", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow", "Altitude", nullptr));
        checkBox_5->setText(QApplication::translate("MainWindow", "Latitude", nullptr));
        checkBox_6->setText(QApplication::translate("MainWindow", "Longitude", nullptr));
        checkBox_7->setText(QApplication::translate("MainWindow", "Roll", nullptr));
        checkBox_8->setText(QApplication::translate("MainWindow", "Pitch", nullptr));
        checkBox_9->setText(QApplication::translate("MainWindow", "Yaw", nullptr));
        checkBox_10->setText(QApplication::translate("MainWindow", "Checklist All", nullptr));
        checkBox_11->setText(QApplication::translate("MainWindow", "Unchecklist All", nullptr));
        checkBox_12->setText(QApplication::translate("MainWindow", "Not Sure", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
