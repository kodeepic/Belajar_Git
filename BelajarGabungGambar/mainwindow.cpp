#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2\core\core.hpp"
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    isMaximized = false;
   // widget = new QWidget(this);
    ui->label->installEventFilter(this);
    //ui->label->setAutoFillBackground(true);
    //ui->label->setPalette(QPalette(Qt::black));

    //setCentralWidget(ui->label);
    connect(this,SIGNAL(doubleClicked()),SLOT(onDoubleClicked()));
    }

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onDoubleClicked()
{
if ((ui->label->windowState() == Qt::WindowFullScreen) && isMaximized)
{  qDebug("Parent");
 // ui->label->setParent(this);
  // setCentralWidget(ui->label);
 ui->label->setWindowFlags(Qt::Widget);
 // ui->label->setWindowState(ui->label->windowState() | Qt::WindowNoState);
 // ui->label->windowState()==Qt::WindowNoState;
   isMaximized =false;
  ui->label->showNormal();

}else{
    qDebug("Maximize");
        isMaximized = true;
       //ui->label->setParent(NULL);
      ui->label->setWindowFlags(Qt::Window);
      ui->label->setWindowState(ui->label->windowState() | Qt::WindowFullScreen);
     ui->label->show();
}
}
bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
if (target == ui->label)
{
if (event->type() == QEvent::MouseButtonDblClick)
{
QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
if (mouseEvent->button() == Qt::LeftButton )
{
emit doubleClicked();
return QMainWindow::eventFilter(target,event);
}
}
}
return QMainWindow::eventFilter(target,event);
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
    ui->label->setWindowFlags(Qt::Window);
    ui->label->setWindowState(ui->label->windowState() | Qt::WindowFullScreen);
   ui->label->show();
}
