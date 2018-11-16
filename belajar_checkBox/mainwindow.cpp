#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QKeyEvent>
#include <QtGui>
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
void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked()){
        QMessageBox::information(this,"title","berhasil");
    }else{
        QMessageBox::information(this,"title","belum berhasil");
    }
}
*/
void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        QMessageBox::information(this,"title"," benar berhasil");
    }else{
        QMessageBox::information(this,"title","benar belum berhasil");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("menyimpan video"),"",tr("video penerbangan(*.avi);;All File"
                                                                                    "(*)"));
    ui->lineEdit->setText(filename);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setWindowFlags(Qt::Window);
    ui->label->showMaximized();

}

void MainWindow::on_pushButton_4_clicked()
{

}
/*
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        ui->label->setWindowFlags(Qt::Widget);
        ui->label->show();

}
}
*/
bool MainWindow::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);



        if (keyEvent->key() == Qt::Key_Escape)
        {
            ui->centralWidget->setEnabled(true);
            ui->label->setWindowFlags(Qt::Widget);
            ui->label->show();
                }
         }
    return true;
}
