#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include<string>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>
#include<QDebug>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
