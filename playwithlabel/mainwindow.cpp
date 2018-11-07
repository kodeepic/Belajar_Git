#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>
#include <QPainter>
#include <QAxObject>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myPlayer =new Player();
    QObject ::connect(myPlayer, SIGNAL(processedImage(QImage)),
                      this,SLOT(updatePlayerUI(QImage)));
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false); //pushbutton tidak aktif jika tidak file yang diunggah
    ui->horizontalSlider->setEnabled(false); //horizontal tidak aktif jika tidak file yang diunggah
}

void MainWindow::updatePlayerUI(QImage img)
{
    if(!img.isNull()){
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),Qt::KeepAspectRatio,Qt::FastTransformation));
        ui->horizontalSlider->setValue(myPlayer->getCurrentFrame());
        ui->label_4->setText(getFormattedTime((int)myPlayer->getCurrentFrame()/(int)myPlayer->getFrameRate()));
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
                                                    tr("Video Files(*.avi *.mpg *.mp4)")); //membuka dokumen untuk memilih video yang sesuai ekstensi
    QFileInfo name = filename;
    //pesan dibawah ini akan keluar video tidak sesuai
    if(!filename.isEmpty()){
        if(!myPlayer->loadVideo(filename.toLatin1().data()))
        {
        QMessageBox msgBox;
        msgBox.setText("The selected video could not be opened");
        msgBox.exec();
        }
        //kalau ada video hal dibawah ini akan dilakukan
        else{
            this->setWindowTitle(name.fileName());
            ui->pushButton_2->setEnabled(true); //pushbutton menjadi aktif
            ui->horizontalSlider->setEnabled(true); //horizontal akan aktif
            ui->horizontalSlider->setMaximum(myPlayer->getNumberOfFrames()); //akan berjalan sampai ukuran max video
            ui->label_5->setText(getFormattedTime((int)myPlayer->getNumberOfFrames()/(int)myPlayer->getFrameRate()) ); //mencatat dan menampilkan durasi video
        }
       ui->lineEdit->setText(filename); //menampilkan alamat filename di lineedit (lokasi video)
    }
}
void MainWindow :: on_pushButton_2_clicked() //kalau pushbutton 2 sudah diklik maka hal dibawah ini akan terjadi
{
    if(myPlayer->isStopped())
    {
        myPlayer->Play(); //jika mplayer berputar
        ui->pushButton_2->setText(tr("Stop")); //tulisan pushbutton jadi stop
    }else
    {
        myPlayer->Stop(); //jika mplayer berhenti
        ui->pushButton_2->setText(tr("Play")); //tulisan puhbutton jadi play
    }

}

QString MainWindow::getFormattedTime(int timeInSeconds){
    int seconds =(int)(timeInSeconds)% 60;
    int minutes = (int)((timeInSeconds/60)% 60);
    int hours = (int)((timeInSeconds/3600)% 24);
    QTime t(hours,minutes,seconds);
    if(hours ==0)
        return t.toString("mm:ss");
    else
        return t.toString("hh:mm:ss");
}
void MainWindow::on_pushButton_3_clicked() //kalau di klik, hal dibawah ini akan dilakukan
{

    d_filename = QFileDialog::getOpenFileName(this,tr("Open Data"),".",
                                                  tr("Video Files(*.m *.xlsx *.csv)")); //membuka dokumen untuk memilih file yang tersedia(sesuai ekstensi)
/*
    //kalau gak ada file pesan dibawah ini akan keluar
    if(!d_filename.isEmpty()){
        if(!myPlayer->loadData(d_filename.toLatin1().data())){
            QMessageBox msgBox;
            msgBox.setText("The selected data could not be opened");
            msgBox.exec();
                }
            }

*/
    ui->lineEdit_2->setText(d_filename); //mencatat lokasi file d_filename di lineedit (lokasi berkas)
    QAxObject* excel     = new QAxObject("Excel.Application");
    QAxObject* workbooks = excel->querySubObject("Workbooks");

    QAxObject* workbook  = workbooks->querySubObject("Open(const QString&)",d_filename);
    QAxObject* sheets    = workbook->querySubObject("Worksheets");
    QAxObject* sheet     = sheets->querySubObject("Item(int)", 1);

    // read the first cells in row 1...18177
    for (int r = 1; (r <= 1); ++r)
    {
        QAxObject* cCell = sheet->querySubObject("Cells(int,int)",r,1);
        Data = cCell->dynamicCall("Value()").toInt();
    }
    for(int j= 1;(j<=1); ++j){
        QAxObject* kecepatan =sheet->querySubObject("Cells(int,int)",j,2);
        Data1 =kecepatan->dynamicCall("Value()").toInt();
    }
    for(int i=1;(i<=1);++i){
        QAxObject* altitude =sheet->querySubObject("Cells(int,int)",i,3);
        Data2 =altitude->dynamicCall("Value()").toInt();
    }

    for(int k=1;(k<=1);++k){
        QAxObject* roll =sheet->querySubObject("Cells(int,int)",k,4);
        Data3 =roll->dynamicCall("Value()").toInt();
    }
    for(int p=1;(p<=1);++p){
        QAxObject* longitude =sheet->querySubObject("Cells(int,int)",p,5);
        Data4 =longitude->dynamicCall("Value()").toInt();
    }
    for(int q=1;(q<=1);++q){
        QAxObject* pitch =sheet->querySubObject("Cells(int,int)",q,6);
        Data5 =pitch->dynamicCall("Value()").toInt();
    }
    for(int m=1;(m<=1);++m){
        QAxObject* latitude =sheet->querySubObject("Cells(int,int)",m,7);
        Data6 =latitude->dynamicCall("Value()").toInt();
    }
    for(int n=1;(n<=1);++n){
        QAxObject* yaw=sheet->querySubObject("Cells(int,int)",n,8);
        Data7 =yaw->dynamicCall("Value()").toInt();
    }
}

void MainWindow::on_pushButton_4_clicked() //kalau diklik akan keluar dari ui
{
    close();
}

void MainWindow::on_horizontalSlider_sliderPressed() //kalau di press video akan berhenti
{
    myPlayer->Stop();
}

void MainWindow::on_horizontalSlider_sliderReleased() //kalau ngk dipress video akan berjalan
{
    myPlayer->Play();
}
void MainWindow::on_horizontalSlider_sliderMoved(int position){
    myPlayer->setCurrentFrame(position);
    ui->label_4->setText(getFormattedTime(position/(int)myPlayer->getFrameRate()));
}



void MainWindow::on_pushButton_5_clicked()
{
QString lokasi = QString("D:\\Magang\\videohasil.avi");
if(!myPlayer->lokasiVideo(lokasi.toLatin1().data())){
    QMessageBox msgBox;
    msgBox.setText("The selected data could not be opened");
    msgBox.exec();
        }
ui->lineEdit_3->setText(lokasi);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
         datawaktu = QString::number(Data);
    } else{
        qDebug()<<"Data waktu tidak ada"<<endl;
    }
    if(!myPlayer->loadWaktu(datawaktu.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1){
        datakecepatan = QString::number(Data1);
    }else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
    }
    if(!myPlayer->loadKeceptan(datakecepatan.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1){
        dataaltitude = QString::number(Data2);
    }else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
    }
    if(!myPlayer->loadAltitude(dataaltitude.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}

void MainWindow::on_checkBox_6_stateChanged(int arg1)
{
    if(arg1){
        dataroll = QString::number(Data3);
    }else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
    }
    if(!myPlayer->loadRoll(dataroll.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1){
        datalongitude = QString::number(Data4);
    }else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
    }
    if(!myPlayer->loadLongitude(datalongitude.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}

void MainWindow::on_checkBox_7_stateChanged(int arg1)
{
    if(arg1){
        datapitch = QString::number(Data5);
    }else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
    }
    if(!myPlayer->loadPitch(datapitch.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    if(arg1){
        datalatitude = QString::number(Data6);
    }else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
    }
    if(!myPlayer->loadLatitude(datalatitude.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}

void MainWindow::on_checkBox_8_stateChanged(int arg1)
{
    if(arg1){
        datayaw = QString::number(Data7);
    }else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
    }
    if(!myPlayer->loadYaw(datayaw.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}
