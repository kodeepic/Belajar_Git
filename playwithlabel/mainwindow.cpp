#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myPlayer =new Player();
    QObject ::connect(myPlayer, SIGNAL(processedImage(QImage)),
                      this,SLOT(updatePlayerUI(QImage)));
    ui->setupUi(this);
    /*
    ui->setupUi(this);
    QPixmap pix(gambar);
    int w=ui->label->width();
    int h=ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
*/
    ui->pushButton_2->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);
}
/*
void MainWindow :: setProgressBarValue()
{
    bar=new QProgressBar (this);
    button =new QPushButton(this);
    connect(button,SIGNAL(clicked()),this,SLOT(setProgressBarValue()));
    int value = 50;
    bar->setValue(value);
}
*/
void MainWindow::updatePlayerUI(QImage img)
{
    if(!img.isNull()){
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),Qt::KeepAspectRatio,Qt::FastTransformation));
        ui->horizontalSlider->setValue(myPlayer->getCurrentFrame());
        ui->label_2->setText(getFormattedTime((int)myPlayer->getCurrentFrame()/(int)myPlayer->getFrameRate()));
    }
}

MainWindow::~MainWindow()
{
    delete myPlayer;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Video"),".",
                                                    tr("Video Files(*.avi *.mpg *.mp4)"));
    QFileInfo name = filename;
    if(!filename.isEmpty()){
        if(!myPlayer->loadVideo(filename.toLatin1().data()))
        {
        QMessageBox msgBox;
        msgBox.setText("The selected video could not be opened");
        msgBox.exec();
        }
        else{
            this->setWindowTitle(name.fileName());
            ui->pushButton_2->setEnabled(true);
            ui->horizontalSlider->setEnabled(true);
            ui->horizontalSlider->setMaximum(myPlayer->getNumberOfFrames());
            ui->label_3->setText(getFormattedTime((int)myPlayer->getNumberOfFrames()));
        }
       ui->lineEdit->setText(filename);
    }
}
void MainWindow :: on_pushButton_2_clicked()
{
    if(myPlayer->isStopped())
    {
        myPlayer->Play();
        ui->pushButton_2->setText(tr("Stop"));
    }else
    {
        myPlayer->Stop();
        ui->pushButton_2->setText(tr("Play"));
    }

}

QString MainWindow::getFormattedTime(int timeInSeconds){
    int seconds =(int)(timeInSeconds)%60;
    int minutes = (int)((timeInSeconds/60)%60);
    int hours = (int)((timeInSeconds/(60*60))%24);
    QTime t(hours,minutes,seconds);
    if(hours ==0)
        return t.toString("mm:ss");
    else
        return t.toString("h:mm:ss");
}
void MainWindow::on_pushButton_3_clicked()
{

    QString d_filename = QFileDialog::getOpenFileName(this,tr("Open Data"),".",
                                                    tr("Video Files(*.m *.xlsx)"));
    ui->lineEdit_2->setText(d_filename);
    /*
    auto excel     = new QAxObject("Excel.Application");
    auto workbooks = excel->querySubObject("Workbooks");
    auto workbook  = workbooks->querySubObject("Open(const QString&)",d_filename);
    auto sheets    = workbook->querySubObject("Worksheets");
    auto sheet     = sheets->querySubObject("Item(int)", 1);
    for (int r = 1; (r <= 5); ++r)
    {
        auto cCell = sheet->querySubObject("Cells(int,int)",r,1);
        qDebug() << cCell->dynamicCall("Value()").toInt();
    }
*/
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}

void MainWindow::on_horizontalSlider_sliderPressed()
{
    myPlayer->Stop();
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    myPlayer->Play();
}
void MainWindow::on_horizontalSlider_sliderMoved(int position){
    myPlayer->setCurrentFrame(position);
    ui->label_2->setText(getFormattedTime(position/(int)myPlayer->getFrameRate()));
}
