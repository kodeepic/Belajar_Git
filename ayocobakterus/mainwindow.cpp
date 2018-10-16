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

int MainWindow::iki;
Mat MainWindow::masuk[100000];
using namespace std;
using namespace cv;
QTimer *timerku;
Mat frame;
VideoCapture cap ("C:/Users/User/Documents/MATLAB/terbang.mp4");


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

// gabung data RGB
void MainWindow::on_pushButton_2_clicked()
{
    Mat img1;
    img1= imread ("C:/users/user/documents/101.png");
 int r,g,b;
     unsigned char *input1 = (unsigned char*)(img1.data);
       unsigned char *input2 = (unsigned char*)(masuk[1].data);
    for (int i=1;i<masuk[1].rows;i++){
        for(int j=1; j<masuk[1].cols; j++){
            if (j<=50){
                b = input1[img1.step  * j+i];
                g = input1[img1.step  * j+i+1];
                r = input1[img1.step * j+i+2];
            }
            b = input2[masuk[1].step * j+i];
            g = input2[masuk[1].step * j+i+1];
            r = input2[masuk[1].step  * j+i+2];}
    }
    for (int i=1;i<masuk[1].rows;i++){
        for(int j=1; j<masuk[1].cols; j++){
        input2[masuk[1].step * j+i]  = b;
        input2[masuk[1].step * j+i+1] = g;
        input2[masuk[1].step * j+i+2] = r;}
    }
    Mat imgfix;
    cvtColor (masuk[1],imgfix,CV_BGR2RGB);
    QVector<QRgb> colorTable;
    for (int i=0; i<256; i++)
        colorTable.push_back(qRgb(i,i,i));
    const unsigned char *qImageBuffer= (const unsigned char*)imgfix.data;
    QImage gambarku= QImage(qImageBuffer,imgfix.cols,imgfix.rows,imgfix.step,QImage::Format_RGB888);
    gambarku.setColorTable (colorTable);
    ui->label->setPixmap(QPixmap::fromImage(gambarku, Qt::AutoColor));}

void MainWindow::on_loadvideo_clicked()
{
//    iki=1;
    timerku-> start(10);

    iki=1;
}

void MainWindow::on_takeframe_clicked()
{
//    timerku->stop();
    cap.open("C:/Users/User/Documents/MATLAB/alhamdullilah.avi");
}

// untuk fungsi menampilkan potongan frame video menggunakan QLabel serta menyimpan data fram dalam array
void MainWindow::showVideo()
{
    cap.read(frame);
    if (!frame.empty()){

        Mat imgfix;
        cvtColor (frame,imgfix,CV_BGR2RGB);
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        masuk [iki]= frame;
        const unsigned char *qImageBuffer= (const unsigned char*)imgfix.data;
        QImage gambarku= QImage(qImageBuffer,imgfix.cols,imgfix.rows,imgfix.step,QImage::Format_RGB888);
        gambarku.setColorTable (colorTable);
        ui->label->setPixmap(QPixmap::fromImage(gambarku, Qt::AutoColor));
        this->update();
        iki ++;}
    else{
     timerku->stop();}
}

void MainWindow::on_lihat_clicked()
{
    Mat imgnew;
    cvtColor (masuk[1],imgnew,CV_BGR2RGB);
    QVector<QRgb> colorTable;
    for (int i=0; i<256; i++)
        colorTable.push_back(qRgb(i,i,i));
    const unsigned char *qImageBuffer= (const unsigned char*)imgnew.data;
    QImage gambarku= QImage(qImageBuffer,imgnew.cols,imgnew.rows,imgnew.step,QImage::Format_RGB888);
    gambarku.setColorTable (colorTable);
    ui->label->setPixmap(QPixmap::fromImage(gambarku, Qt::AutoColor));
}
