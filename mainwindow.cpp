#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <iostream>
#include <stdio.h>
#include <QVector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <QMainWindow>
#include <QPixmap>
#include <QArrayData>
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QAxObject>
#include <QSqlQuery>
#include <string.h>
//#include <mat.h>

int MainWindow::iki;
Mat MainWindow::masuk[10000];
int MainWindow::aku;
//int MainWindow::panjang;
int MainWindow::lebar;
using namespace std;
using namespace cv;
QTimer *timerku;
QTimer *mytimer;
Mat frame;
VideoCapture cap ("C:/Users/User/Documents/MATLAB/terbang.mp4");
int MainWindow::data1 [1000];

//MATFILE *pmat;
//const char* name=NULL;
//mxArray *pa;



int panjangok;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix ("C:/Users/User/Documents/QT AYE/pengolahangambar/doraemon.jpg");
    ui->label->setPixmap(pix);

    // settig Timer
    const int periodevgambar = 1000/25;
    timerku = new QTimer (this);
    timerku->setInterval (periodevgambar);
    connect(timerku, SIGNAL(timeout()),this,SLOT(showVideo()));

}

MainWindow::~MainWindow()
{
    delete ui;

}

// untuk memulai proses pembacaan dan display video

void MainWindow::on_loadvideo_clicked()
{

    timerku-> start(10);
    iki =1;
}

// fungsi untuk display video awal
void MainWindow::showVideo()
{

    cap.read(frame);

    if (!frame.empty()){
        panjangok = frame.cols;
        lebar   = frame.rows;
        Mat imgfix;
        cvtColor (frame,imgfix,CV_BGR2RGB);
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        const unsigned char *qImageBuffer= (const unsigned char*)imgfix.data;
        QImage gambarku= QImage(qImageBuffer,imgfix.cols,imgfix.rows,imgfix.step,QImage::Format_RGB888);
        gambarku.setColorTable (colorTable);
        ui->label->setPixmap(QPixmap::fromImage(gambarku, Qt::AutoColor));

       }
    else{
     timerku->stop();}
            iki++;
             qDebug() << "panjangdr: "<< panjangok ;


}


// push button untuk mengaktifkan proses modifikasi gambar
void MainWindow::on_pushButton_2_clicked()
{
//   Opsi 2
//   Tahap 1: Baca Video dan deklarasi variabel untuk video baru
    VideoCapture cap ("C:/Users/User/Documents/MATLAB/terbang.mp4");
    double fps = cap.get(CV_CAP_PROP_FPS);
    VideoWriter Video("C:/Users/User/Documents/QTAYE/ayocobakterus/bismillah.avi",CV_FOURCC('M','J','P','G'),fps, Size(720,576),true);
    int panjang1;
    int lebar1;
    int pjg;
    int lbr;
    Mat imgfix; // Matrikx untuk frame

//  Proses Modifikasi video
   for (int i=0; i< 7950;i++){
//  Pembacaan frame video
       cap.read(frame);
       if (!frame.empty()){
           //Konversi matriks frame dari kode BGR menjadi Kode RGB
           Mat img2;
           cvtColor (frame,img2,CV_BGR2RGB);
           pjg = img2.rows;
           lbr = img2.cols;
           //Matriks gambar Baterai;
           Mat img1;
           Mat img0;
           img1= imread ("C:/Users/User/Documents/QTAYE/ayocobakterus/B100(2).png");
           cv::resize(img1,img0,cv::Size(img2.cols*0.125,img2.rows*0.0625),0,0);
//                      Point2f center(img0.cols/2.0F,img0.rows/2.0F);
//                      Mat rot = getRotationMatrix2D(center,90,1.0);
//                      Rect2f bbox = RotatedRect(Point2f(),img0.size(),90).boundingRect2f();
//                      rot.at<double>(0,2) +=bbox.width/2.0 - img0.cols/2.0;
//                      rot.at<double>(1,2) +=bbox.height/2.0 - img0.rows/2.0;

//                      Mat img10;
//                      warpAffine (img0,img10,rot,bbox.size());

//                      Point2f src_center(img0.cols/2.0F, img0.rows/2.0F);
//                      Mat rot_matrix = getRotationMatrix2D(src_center,90,1.0);

//                      Mat img10 (Size(img0.size().height,img0.size().width),img0.type());

//                      warpAffine(img0,img10,rot_matrix,img0.size());

          Mat img10;
           cvtColor (img0,img10,CV_BGR2RGB);

//    Proses Modifikasi frame dengan gambar Baterai
           panjang1 = img10.rows;
           lebar1   = img10.cols;
           for (int i=0;i<=panjang1;++i){
           for(int j=0; j<=lebar1; ++j){
               int j0= j+ (img2.cols * 0.875);
               int a =img10.at<Vec3b>(i,j)[0];
               int b =img10.at<Vec3b>(i,j)[1];
               int c =img10.at<Vec3b>(i,j)[2];
               int d =a+b+c;
               if (d==0)
                   {
                    img2.at<Vec3b>(i,j0)[0]= img2.at<Vec3b>(i,j0)[0];
                    img2.at<Vec3b>(i,j0)[1]= img2.at<Vec3b>(i,j0)[1];
                    img2.at<Vec3b>(i,j0)[2]= img2.at<Vec3b>(i,j0)[2];
                   }
               else {
                    img2.at<Vec3b>(i,j0)[0]= img0.at<Vec3b>(i,j)[0];
                    img2.at<Vec3b>(i,j0)[1] =img0.at<Vec3b>(i,j)[1];
                    img2.at<Vec3b>(i,j0)[2] =img0.at<Vec3b>(i,j)[2];
                    }
            }
        }

//     Pembacaan Gambar Skala
            Mat skala;
            Mat sknew;
            documentMode();
            skala = imread("C:/Users/User/Documents/QTAYE/ayocobakterus/skala.png");
            cvtColor (skala,sknew,CV_BGR2RGB);
            // Merubah ukuran skala
            cv::resize(sknew,sknew,cv::Size(img2.cols*0.025,img2.rows*0.94),0,0);
            for (int a1=0; a1<sknew.rows;a1++){
                int a10 = a1 + (img2.rows*0.056);
                for (int b1=0; b1<sknew.cols;b1++){
                    int c1 =sknew.at<Vec3b>(a1,b1)[0];
                    int e1 =sknew.at<Vec3b>(a1,b1)[1];
                    int d1 =sknew.at<Vec3b>(a1,b1)[2];
                    int f1 =c1+e1+d1;
                    if (f1==765){
                        img2.at<Vec3b>(a10,b1)[0]= img2.at<Vec3b>(a10,b1)[0];
                        img2.at<Vec3b>(a10,b1)[1]= img2.at<Vec3b>(a10,b1)[1];
                        img2.at<Vec3b>(a10,b1)[2]= img2.at<Vec3b>(a10,b1)[2];
                    }

                    else {
                        img2.at<Vec3b>(a10,b1)[0]= sknew.at<Vec3b>(a1,b1)[0];
                        img2.at<Vec3b>(a10,b1)[1] =sknew.at<Vec3b>(a1,b1)[1];
                        img2.at<Vec3b>(a10,b1)[2] =img0.at<Vec3b>(a1,b1)[2];
                    }

                }

            }
           int fontface  = cv::FONT_HERSHEY_SIMPLEX;
           double scale  = 0.8;
           int thickness = 1  ;
           int baseline  = 0  ;

           cv::Size text = cv::getTextSize("Kecepatan",fontface,scale,thickness,&baseline);
           Mat roi =img2(Rect(Point(300,300) + cv::Point(0,baseline), Point(310,300) + cv::Point (text.width, -text.height)));
           Mat color (roi.size(),CV_8UC3,cv::Scalar(0,125,125));
           double alpha =0.3;
           addWeighted(color,alpha,roi,1.0 - alpha,0.0,roi);
//           cv::Size text = cv::getTextSize("Kecepatan",fontface,scale,thickness,&baseline);
//           img2.convertTo(img2,CV_8UC4);
//           rectangle(img2,Rect(Point(300,290) + cv::Point(0,baseline), Point(310,300) + cv::Point (text.width, -text.height)),cv::Scalar(0,80,80,0),CV_FILLED);
           putText(img2,data1 [i],Point (300,300),fontface,scale,cv:: Scalar(255,255,255,0),thickness,8);

           cvtColor (img2,imgfix,CV_BGR2RGB);
           Video.write(imgfix);
}
   qDebug() << "frame: "<< i << "total: " << iki << "panjang:" << pjg << "lebar1:" << lebar1 << "panjangdr: "<< lbr ;
 }
   cvtColor (imgfix,imgfix,CV_BGR2RGB);
   QVector<QRgb> colorTable;
   for (int i=0; i<256; i++)
       colorTable.push_back(qRgb(i,i,i));
   const unsigned char *qImageBuffer= (const unsigned char*)imgfix.data;
   QImage gambarku= QImage(qImageBuffer,imgfix.cols,imgfix.rows,imgfix.step,QImage::Format_RGB888);
   gambarku.setColorTable (colorTable);
   ui->label->setPixmap(QPixmap::fromImage(gambarku, Qt::AutoColor));
}


// Untuk display hasil modifikasi frame
void MainWindow::on_takeframe_clicked()
{
     VideoCapture cap("C:/Users/User/Documents/QTAYE/ayocobakterus/bismillah.avi");
     Mat img2;
     cap.read(img2);
     Mat img3;
     cvtColor (img2,img3,CV_BGR2RGB);
     QVector<QRgb> colorTable;
     for (int i=0; i<256; i++)
         colorTable.push_back(qRgb(i,i,i));
     const unsigned char *qImageBuffer= (const unsigned char*)img3.data;
     QImage gambarku= QImage(qImageBuffer,img3.cols,img3.rows,img3.step,QImage::Format_RGB888);
     gambarku.setColorTable (colorTable);
      qDebug() << "panjang: " << panjangok;
     ui->label->setPixmap(QPixmap::fromImage(gambarku, Qt::AutoColor));
}

// untuk fungsi menampilkan potongan frame video menggunakan QLabel serta menyimpan data frame dalam array
//void MainWindow::on_lihat_clicked()
//{
//    Mat imgnew;
//    cvtColor (masuk[iki-1],imgnew,CV_BGR2RGB);
//    QVector<QRgb> colorTable;
//    for (int i=0; i<256; i++)
//        colorTable.push_back(qRgb(i,i,i));
//    const unsigned char *qImageBuffer= (const unsigned char*)imgnew.data;
//    QImage gambarku= QImage(qImageBuffer,imgnew.cols,imgnew.rows,imgnew.step,QImage::Format_RGB888);
//    gambarku.setColorTable (colorTable);
//    ui->label->setPixmap(QPixmap::fromImage(gambarku, Qt::AutoColor));
//}

// fungsi untuk menampilkan gambar baterai gabungan
void MainWindow::on_pushButton_clicked()
{
    Mat img1;
    img1= imread ("C:/users/user/documents/101.png");
    Mat img2;
    img2= imread ("C:/users/user/documents/Gray_image.jpg");
    Mat img3;
    addWeighted(img1,0.1,img2,0.7,0,img3);
    Mat imgfix;
    cvtColor (img3,imgfix,CV_BGR2RGB);
    QVector<QRgb> colorTable;
    for (int i=0; i<256; i++)
        colorTable.push_back(qRgb(i,i,i));
    const unsigned char *qImageBuffer= (const unsigned char*)imgfix.data;
    QImage gambarku= QImage(qImageBuffer,imgfix.cols,imgfix.rows,imgfix.step,QImage::Format_RGB888);
    gambarku.setColorTable (colorTable);
    ui->label->setPixmap(QPixmap::fromImage(gambarku, Qt::AutoColor));
}

void MainWindow::on_dataprocess_clicked()
{
//    qDebug << "Open Excel ..." << endl;
//    QSqlDatabase excel = QSqlDatabase::addDatabase("QODBC");
//    excel.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xls)};DBQ=" + QString (getSettings ("C:\Users\User\Documents\QTAYE\ayocobakterus\semogalancar.mat") + '/' + file));

//    if (excel.open()){
//        int cont =0;
//        QSqlQuery query ("select * from [Sheet1" + "$]");
//        while (query.next())
//        {
//            QString column1 =query.value(0).toString();
//            QString column2 =query.value(1).toString();
//            QString column3 =query.value(2).toString();
//            QString column4 =query.value(3).toString();
//            QString column5 =query.value(4).toString();

//            qDebug ("('',%d, %d, %d, \"%s\"),",
//                    column2.toInt(),
//                    column3.toInt(),
//                    column4.toInt(),
//                    column5.toStdString().c_str());
//            cont++;

//        }
//        QString reg ="Regs:" + cont;
//        qDebug() << reg;
//    }
//else
//    {
//        qDebug() << "Can't Open file (Excel)" << endl;

//    }

    auto excel     = new QAxObject("Excel.Application");
    auto workbooks = excel->querySubObject("Workbooks");
    QString d_filename = "C:\\Users\\User\\Documents\\QTAYE\\ayocobakterus\\alhamdullilah.xlsx";
    auto workbook  = workbooks->querySubObject("Open(const QString&)",d_filename);
    auto sheets    = workbook->querySubObject("Worksheets");
    auto sheet     = sheets->querySubObject("Item(int)", 1);

    // read the first cells in row 1...18177
    for (int r = 1; (r <= 18177); ++r)
    {
        auto cCell = sheet->querySubObject("Cells(int,int)",r,1);
        qDebug() << cCell->dynamicCall("Value()").toInt();
        //data1[r] = cCell->dynamicCall("Value()").toInt();
        std::string str = cCell;
        std::istringstream ss(str);
        ss >> data1[r];





    }
}
