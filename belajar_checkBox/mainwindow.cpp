#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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

void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked()){
        QMessageBox::information(this,"title","berhasil");
    }else{
        QMessageBox::information(this,"title","belum berhasil");
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        QMessageBox::information(this,"title"," benar berhasil");
    }else{
        QMessageBox::information(this,"title","benar belum berhasil");
    }
}
