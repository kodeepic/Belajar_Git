#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>
#include <QPainter>
#include <QAxObject>
#include <QDebug>
#include <QToolTip>
#include <QSize>
#include <QIcon>
#include <QGridLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    isMaximized = false;
    myPlayer =new Player();
    QObject ::connect(myPlayer, SIGNAL(processedImage(QImage)),
                      this,SLOT(updatePlayerUI(QImage)));
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false); //pushbutton tidak aktif jika tidak file yang diunggah
    ui->horizontalSlider->setEnabled(false); //horizontal tidak aktif jika tidak file yang diunggah
    ui->pushButton_6->setToolTip("<font color=white>Layar Penuh</font>");
    ui->label_4->setToolTip("<font color=white>Pergerakan Waktu</font>");
    ui->label_5->setToolTip("<font color=white>Total Waktu</font>");
    ui->label->installEventFilter(this);
    connect(this,SIGNAL(doubleClicked()),SLOT(onDoubleClicked()));
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),this,SLOT(on_horizontalSlider_sliderMoved(int)));
    QPixmap logo(":/logos/logo.png");
    ui->label->setPixmap(logo);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->pushButton_6->setEnabled(false);
   ui->progressBar->setValue(0);
   connect(myPlayer,SIGNAL(urutan(int)),this,SLOT(on_progressBar_valueChanged(int)));

}
void MainWindow::onDoubleClicked()
{
if ((ui->label->windowState() == Qt::WindowFullScreen) && isMaximized)
{  qDebug("Parent");
 ui->label->setWindowFlags(Qt::Widget);
 ui->label->setToolTip(QString());
   isMaximized =false;
  ui->label->showNormal();

}else{
    qDebug("Maximize");
        isMaximized = true;
      ui->label->setToolTip("<font color=white>Klik 2 Kali untuk keluar layar Penuh </font>");
      ui->label->setWindowFlags(Qt::Window);
      ui->label->setWindowState(ui->label->windowState() | Qt::WindowFullScreen);
     ui->label->show();
}
}
bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
if (target == ui->label)
{
if (event->type() == QEvent::MouseButtonDblClick )
{
QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
if (mouseEvent->button() == Qt::LeftButton)
{
emit doubleClicked();
return QMainWindow::eventFilter(target,event);
}
}
}
return QMainWindow::eventFilter(target,event);
}



void MainWindow::updatePlayerUI(QImage img)
{
    if(!img.isNull()){
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),Qt::KeepAspectRatio,Qt::FastTransformation));
        ui->horizontalSlider->setValue(myPlayer->getCurrentFrame());
        ui->label_4->setText(getFormattedTime((int)myPlayer->getCurrentFrame()/(int)myPlayer->getFrameRate()));
        ui->horizontalSlider->setToolTip(getFormattedTime((int)myPlayer->getCurrentFrame()/(int)myPlayer->getFrameRate()));
    }else{
        ui->pushButton_2->setEnabled(false);
        ui->horizontalSlider->setEnabled(false);
    }
    //tampilan saat video bearkhir diputar
     Waktumasimum = getFormattedTime((int)myPlayer->getNumberOfFrames()/(int)myPlayer->getFrameRate());
     Waktujalan = getFormattedTime((int)myPlayer->getCurrentFrame()/(int)myPlayer->getFrameRate());
    if(Waktumasimum==Waktujalan){
        QPixmap logo(":/logos/logo.png");
        myPlayer->setCurrentFrame(1);
        ui->label->setPixmap(logo);
        ui->label->setAlignment(Qt::AlignCenter);
        ui->pushButton_2->setToolTip("<font color=white>Play</font>"); //tulisan pushbutton jadi stop
        ui->pushButton_2->setIcon(QIcon(":/icons/icon_control_play1.png"));
        ui->pushButton_2->setIconSize(QSize(50,50));
        ui->label_4->setText("--:--");
        ui->label_5->setText("--:--");
        ui->pushButton_6->setEnabled(false);
        ui->horizontalSlider->setValue(1);
        myPlayer->Stop();
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
                                                    tr("Video Files(*.avi *.mpg *.mp4 *.mkv)")); //membuka dokumen untuk memilih video yang sesuai ekstensi
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
            ui->label_5->setText(getFormattedTime((int)myPlayer->getNumberOfFrames()/(int)myPlayer->getFrameRate()) );
            //mencatat dan menampilkan durasi video

        }
       ui->pushButton_2->setToolTip("<font color=white>Play</font>"); //tulisan pushbutton jadi stop
       ui->pushButton_2->setIcon(QIcon(":/icons/icon_control_play1.png"));
       ui->pushButton_2->setIconSize(QSize(50,50));
       ui->lineEdit->setText(filename); //menampilkan alamat filename di lineedit (lokasi video)
    }
}
void MainWindow :: on_pushButton_2_clicked() //kalau pushbutton 2 sudah diklik maka hal dibawah ini akan terjadi
{
    if(myPlayer->isStopped())
    {
        myPlayer->Play(); //jika mplayer berputar
        ui->pushButton_2->setIcon(QIcon(":/icons/icon_control_pause.png"));
        ui->pushButton_2->setIconSize(QSize(50,50));
        ui->pushButton_2->setToolTip("<font color=white>Pause the playback</font>"); //tulisan puhbutton jadi pause
        ui->pushButton_6->setEnabled(true);
    }else
    {
        myPlayer->Stop(); //jika mplayer berhenti
        ui->pushButton_2->setToolTip("<font color=white>Play</font>"); //tulisan pushbutton jadi play
        ui->pushButton_2->setIcon(QIcon(":/icons/icon_control_play1.png"));
        ui->pushButton_2->setIconSize(QSize(50,50));
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
                                                  tr("Video Files(*.mat *.xlsx *.csv)")); //membuka dokumen untuk memilih file yang tersedia(sesuai ekstensi)

    //kalau gak ada file pesan dibawah ini akan keluar
    if(!d_filename.isEmpty()){
        if(!myPlayer->loadData(d_filename.toLatin1().data())){
            QMessageBox msgBox;
            msgBox.setText("The selected data could not be opened");
            msgBox.exec();
                }
            }

    ui->lineEdit_2->setText(d_filename); //mencatat lokasi file d_filename di lineedit (lokasi berkas)

    /*
    QAxObject* excel     = new QAxObject("Excel.Application");
    QAxObject* workbooks = excel->querySubObject("Workbooks");

    QAxObject* workbook  = workbooks->querySubObject("Open(const QString&)",d_filename);
    QAxObject* sheets    = workbook->querySubObject("Worksheets");
    QAxObject* sheet     = sheets->querySubObject("Item(int)", 1);

    // read the first cells in row 1...18177
    for (int r = 1; (r <=2); ++r)
    {
        QAxObject* cCell = sheet->querySubObject("Cells(int,int)",r,1);
        Data= cCell->dynamicCall("Value()").toInt();
    }
    for(int r = 1; (r <= 1); ++r){
        QAxObject* kecepatan =sheet->querySubObject("Cells(int,int)",r,2);
        Data1 =kecepatan->dynamicCall("Value()").toInt();
        QAxObject* altitude =sheet->querySubObject("Cells(int,int)",r,3);
        Data2 =altitude->dynamicCall("Value()").toInt();
        QAxObject* roll =sheet->querySubObject("Cells(int,int)",r,4);
        Data3 =roll->dynamicCall("Value()").toInt();
        QAxObject* longitude =sheet->querySubObject("Cells(int,int)",r,5);
        Data4 =longitude->dynamicCall("Value()").toInt();
        QAxObject* pitch =sheet->querySubObject("Cells(int,int)",r,6);
        Data5 =pitch->dynamicCall("Value()").toInt();
        QAxObject* latitude =sheet->querySubObject("Cells(int,int)",r,7);
        Data6 =latitude->dynamicCall("Value()").toInt();
        QAxObject* yaw=sheet->querySubObject("Cells(int,int)",r,8);
        Data7 =yaw->dynamicCall("Value()").toInt();
    }
  */
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
    ui->horizontalSlider->setToolTip("<font color=white></font>"+getFormattedTime(position/(int)myPlayer->getFrameRate()));

}

void MainWindow::on_pushButton_5_clicked()
{
    myPlayer->setCurrentFrame(1);
    ui->pushButton_2->setToolTip("<font color=white>Play</font>"); //tulisan pushbutton jadi stop
    ui->pushButton_2->setIcon(QIcon(":/icons/icon_control_play1.png"));
    ui->pushButton_2->setIconSize(QSize(50,50));
    myPlayer->Stop();
QString lokasi = QFileDialog::getSaveFileName(this,tr("menyimpan video"),"",tr("video penerbangan(*.avi);;All File"
                                                                               "(*)"));
if(!myPlayer->lokasiVideo(lokasi.toLatin1().data())){
    QMessageBox msgBox;
    msgBox.setText("The selected data could not be opened");
    msgBox.exec();
        }
ui->lineEdit_3->setText(lokasi);
myPlayer->Play();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    int alma;;
    if(arg1){
        alma =1;
    }
    else{
            alma =0;
 //       qDebug()<<"Data waktu tidak ada"<<endl;

    }
    datawaktu = QString::number(alma);
    qDebug() << " " << datawaktu;
    if(!myPlayer->loadWaktu(datawaktu.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
    /*
    if(arg1){
         datawaktu= QString::number(Data);

    } else{
        qDebug()<<"Data waktu tidak ada"<<endl;
    }
    if(!myPlayer->loadWaktu(datawaktu.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();

    }
*/
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    int omo;
    if(arg1){
        omo = 1;
    }
    else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
        omo = 0;
    }
    datakecepatan = QString::number(omo);
    if(!myPlayer->loadKeceptan( datakecepatan.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
/*
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
    */
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    int ini;
    if(arg1){
        ini = 1;
    }
    else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
        ini = 0;
    }
    dataaltitude = QString::number(ini);
    if(!myPlayer->loadAltitude(dataaltitude.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
    /*
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
            */
}

void MainWindow::on_checkBox_6_stateChanged(int arg1)
{
    int imu;
    if(arg1){
        imu = 1;
    }
    else{
        qDebug()<<"Data kecepatan tidak ada"<<endl;
        imu = 0;
    }
    dataroll = QString::number(imu);
    if(!myPlayer->loadRoll(dataroll.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
    /*
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
            */
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    int ina;
    if(arg1){
       ina = 1;
    }
    else{
        qDebug()<<"Data longitude tidak ada"<<endl;
        ina = 0;
    }
    datalongitude = QString::number(ina);
    if(!myPlayer->loadLongitude(datalongitude.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
    /*
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
            */
}

void MainWindow::on_checkBox_7_stateChanged(int arg1)
{
    int iny;
    if(arg1){
        iny = 1;
    }
    else{
        qDebug()<<"Data pitch tidak ada"<<endl;
        iny = 0;
    }
    datapitch = QString::number(iny);
    if(!myPlayer->loadPitch(datapitch.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
    /*
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
            */
}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    int inl;
    if(arg1){
        inl = 1;
    }
    else{
        qDebug()<<"Data altitude tidak ada"<<endl;
        inl = 0;
    }
    dataaltitude = QString::number(inl);
    if(!myPlayer->loadLatitude(datalatitude.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
    /*
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
            */
}

void MainWindow::on_checkBox_8_stateChanged(int arg1)
{
    int loh;
    if(arg1){
        loh = 1;
    }else{
        qDebug()<<"Data yaw tidak ada"<<endl;
        loh= 0;
    }
    datayaw = QString::number(loh);
    if(!myPlayer->loadYaw(datayaw.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
    /*
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
    */
}

void MainWindow::on_pushButton_6_clicked()
{
    isMaximized = true;
    ui->label->setToolTip("<font color=white>Klik 2 Kali untuk keluar layar Penuh </font>");
  ui->label->setWindowFlags(Qt::Window);
  ui->label->setWindowState(ui->label->windowState() | Qt::WindowFullScreen);
 ui->label->show();
        //ui->label->setWindowFlags(Qt::Window|Qt::WindowMaximizeButtonHint);
        //ui->label->showMaximized();
        //ui->pushButton_6->setEnabled(false);
        //ui->pushButton_6->setToolTip("<font color=white>Keluar dari layar penuh</font>");

           // ui->pushButton_6->setIcon(QIcon(":/icons/exit-fullscreen-512.png"));
            //ui->pushButton_6->setIconSize(QSize(45,45));

            //ui->pushButton_6->setIcon(QIcon(":/icons/full-screen-icon-11.png"));
            //ui->pushButton_6->setIconSize(QSize(50,50));
}

/*
void MainWindow::keyPressEvent(QKeyEvent *e)
{
     Qt::WindowFlags flags=windowFlags();
        if(isFullScreen()){
            if (e->key()==Qt::Key_Escape){
                setWindowFlags(flags|Qt::Widget);
            }
        }

       ui->label->setWindowFlags(flags);
       ui->label->show();
 }
*/

void MainWindow::on_checkBox_9_stateChanged(int arg1)
{
    int bat;
    if(arg1){
        bat = 1;
    }
    else{
        qDebug()<<"Data baterai tidak ada"<<endl;
        bat = 0;
    }
    databaterai = QString::number(bat);
    if(!myPlayer->loadBaterai(databaterai.toLatin1().data())){
        QMessageBox msgBox;
        msgBox.setText("The selected data could not be opened");
        msgBox.exec();
            }
}
/*
void MainWindow :: keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Escape){
            ui->label->setWindowFlag(Qt::Window, false);
           ui->label->setWindowFlags(Qt::Widget);
            ui->label->show();
        }
    else{
        QWidget::keyPressEvent(e);

    }
}
*/
void MainWindow::on_pushButton_8_clicked()
{
    QString str = ui->lineEdit_4->text();
    KDS = str;
    if (!myPlayer->SetPoint(KDS.toLatin1().data())){
        QMessageBox  msgBox;
        msgBox.setText("Data tida keluar");
        msgBox.exec();
    }
}

void MainWindow::on_progressBar_valueChanged(int kunci)
{
    ui->progressBar->setRange(1,(myPlayer->getNumberOfFrames()));
    ui->progressBar->setValue(kunci);
}
