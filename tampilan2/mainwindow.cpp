#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // player = new QMediaPlayer(this);
   // vw= new QVideoWidget(this);
   // player->setVideoOutput(vw);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString filename= QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.mpg)");

    //int nilai;
    //nilai=ui->pushButton->value();
    //ui->progressBar->setValue(nilai);

}

void MainWindow::on_pushButton_3_clicked()
{
   hide();
   secDialog = new SecDialog(this);
   secDialog->show();
}

void MainWindow::on_pushButton_4_clicked()
{
close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename1 = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.xlsx)");
}
