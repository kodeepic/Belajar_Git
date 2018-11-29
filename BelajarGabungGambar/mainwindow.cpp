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
    widget = new QWidget(this);
    widget->installEventFilter(this);
    widget->setAutoFillBackground(true);
    widget->setPalette(QPalette(Qt::black));

    setCentralWidget(widget);
    connect(this,SIGNAL(doubleClicked()),SLOT(onDoubleClicked()));
    }

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onDoubleClicked()
{
if ((widget->windowState() == Qt::WindowFullScreen) && isMaximized)
{qDebug("Parent");
    widget->setParent(this);
    setCentralWidget(widget);
    isMaximized = false;

}else{
    qDebug("Maximize");
        isMaximized = true;
        widget->setParent(NULL);
        widget->setWindowFlags(widget->windowFlags() | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
        widget->setWindowState(widget->windowState() | Qt::WindowFullScreen);
        widget->show();
}
}
bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
if (target == widget)
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

}
