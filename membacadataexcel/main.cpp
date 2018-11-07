#include "mainwindow.h"
#include <QApplication>
#include <QAxObject>
#include <QSqlQuery>
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Mat image =imread("D:\\Capture gambar\\gambar.png");
    QAxObject* excel     = new QAxObject("Excel.Application");
    QAxObject* workbooks = excel->querySubObject("Workbooks");
    QString d_filename = "C:\\Users\\Ariku\\Documents\\Data.xlsx";
    QAxObject* workbook  = workbooks->querySubObject("Open(const QString&)",d_filename);
    QAxObject* sheets    = workbook->querySubObject("Worksheets");
    QAxObject* sheet     = sheets->querySubObject("Item(int)", 1);

    // read the first cells in row 1...18177
    for (int r = 1; (r <= 1); ++r)
    {
        QAxObject* cCell = sheet->querySubObject("Cells(int,int)",r,1);
        int data = cCell->dynamicCall("Value()").toInt();
        QString s = QString::number(data);
        qDebug()<<s<<endl;

    }

    putText(image,"a",Point2f(100,100),FONT_HERSHEY_PLAIN,2,  Scalar(0,0,255), 2 , 8 ,false);
  namedWindow("Image Window image",CV_WINDOW_AUTOSIZE);
   imshow("Image Window image",image);
    return a.exec();

}
