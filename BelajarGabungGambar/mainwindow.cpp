#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2\core\core.hpp"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    }

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow :: PemutarGambar()
{
    cv::resize(image,image,Size(512,384),0,0,INTER_LINEAR);
    cv::cvtColor(image,image,CV_BGR2RGB);
    QImage imdisplay((uchar*)image.data,image.cols,image.rows,image.step,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(imdisplay));
}
*/

void MainWindow::on_pushButton_clicked()
{

}
