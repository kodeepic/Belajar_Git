#include "mainwindow.h"
#include <QApplication>
#include <QAxObject>
#include <QDebug>
#include <QSqlQuery>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
int data[100][100];
using namespace cv;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   // Mat image =imread("D:\\Capture gambar\\gambar.png");
    QAxObject* excel     = new QAxObject("Excel.Application");
    QAxObject* workbooks = excel->querySubObject("Workbooks");
  QString d_filename = "D:\\contoh.xlsx"; //hapus coment kalau mau run
    QAxObject* workbook  = workbooks->querySubObject("Open(const QString&)",d_filename);
    QAxObject* sheets    = workbook->querySubObject("Worksheets");
    QAxObject* sheet     = sheets->querySubObject("Item(int)", 1);
    QAxObject * range = sheet->querySubObject("UsedRange");
    QAxObject * rows = range->querySubObject( "Rows" );
    int rowCount = rows->dynamicCall( "Count()" ).toInt();
   QAxObject* columns = range->querySubObject( "Columns" );
    int columnCount = columns->property("Count").toInt();
   // qDebug()<<rowCount*columnCount<<endl;
    // read the first cells in row 1...18177
    for (int r = 1; (r <= rowCount*columnCount); ++r)
    {
        if(r<=rowCount){
            QAxObject* cCell = sheet->querySubObject("Cells(int,int)",r,1);
             data[r][1]= cCell->dynamicCall("Value()").toInt();
            QAxObject* cCell1 = sheet->querySubObject("Cells(int,int)",r,4);
             data[r][2]=cCell1->dynamicCall("Value()").toInt();
             data[r][3]=1;
             data[r][4]=1;
        }else if((r>rowCount)&&(r<=rowCount*2)){
             QAxObject* cCell = sheet->querySubObject("Cells(int,int)",r-(rowCount),2);
             data[r][1]= cCell->dynamicCall("Value()").toInt();
             QAxObject* cCell2 = sheet->querySubObject("Cells(int,int)",r-(rowCount),5);
              data[r][3]=cCell2->dynamicCall("Value()").toInt();
             data[r][2]=1;
             data[r][4]=1;
        }else{
            QAxObject* cCell = sheet->querySubObject("Cells(int,int)",r-(rowCount*2),3);
             data[r][1]= cCell->dynamicCall("Value()").toInt();
             QAxObject* cCell3 = sheet->querySubObject("Cells(int,int)",r-(rowCount*2),6);
              data[r][4]= cCell3->dynamicCall("Value()").toInt();
             data[r][2]=1;
             data[r][3]=1;
             if(data[r][1]==0){
                 break;
             }
        }
       // QString s = QString::number(data);
        qDebug()<<data[r][1]<<data[r][2]<<data[r][3]<<data[r][4]<<endl;
    }


    //putText(image,"a",Point2f(100,100),FONT_HERSHEY_PLAIN,2,  Scalar(0,0,255), 2 , 8 ,false);
  //namedWindow("Image Window image",CV_WINDOW_AUTOSIZE);
   //imshow("Image Window image",image);
    return a.exec();

}
