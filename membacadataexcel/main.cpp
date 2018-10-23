#include "mainwindow.h"
#include <QApplication>
#include <QAxObject>
#include <QSqlQuery>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    auto excel     = new QAxObject("Excel.Application");
    auto workbooks = excel->querySubObject("Workbooks");
    QString d_filename = "C:\\Users\\Ariku\\Documents\\Data.xlsx";
    auto workbook  = workbooks->querySubObject("Open(const QString&)",d_filename);
    auto sheets    = workbook->querySubObject("Worksheets");
    auto sheet     = sheets->querySubObject("Item(int)", 1);

    // read the first cells in row 1...18177
    for (int r = 1; (r <= 18177); ++r)
    {
        auto cCell = sheet->querySubObject("Cells(int,int)",r,1);
        qDebug() << cCell->dynamicCall("Value()").toInt();
    }
    return a.exec();

}
