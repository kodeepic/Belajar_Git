#include "player.h"
#include <QPainter>
#include <QDebug>
#include <QtCore>
#include <iostream>
#include <fstream>
#include <QString>
#include <string>
#include <QCheckBox>
#include <QMessageBox>
#include <QAxObject>
using namespace std;

// Variabel Array untuk menampung data penerbangan


Player::Player(QObject *parent) : QThread(parent)
{
    stop =true;

}

bool Player :: loadVideo(String filename){
    capture.open(filename);
    if(capture.isOpened())
    {
        frameRate = (int) capture.get(CV_CAP_PROP_FPS);
        totalframe = (int) capture.get(CV_CAP_PROP_FRAME_COUNT);
        qDebug() << "framerate" <<frameRate << "jmlh:" << totalframe;

        return true;
    } else{
        return false;
    }


}
void Player::Play()
{
    if (!isRunning()){
        if(isStopped()){
            stop=false;
        }
        start(LowPriority);
    }
}

double Player::getCurrentFrame(){
    return capture.get(CV_CAP_PROP_POS_FRAMES);

}
double Player::getNumberOfFrames(){
    return double(capture.get(CV_CAP_PROP_FRAME_COUNT));
}
double Player :: getFrameRate(){
    return frameRate;
}

void Player::setCurrentFrame(int frameNumber){
    capture.set(CV_CAP_PROP_POS_FRAMES,frameNumber);
}

//bool Player :: loadData(String d_filename){
    /*
    QString qstr = QString::fromStdString(d_filename);
    auto excel     = new QAxObject("Excel.Application");
    auto workbooks = excel->querySubObject("Workbooks");
    //QString d_filename = "C:\\Users\\Ariku\\Documents\\Data.xlsx";
    auto workbook  = workbooks->querySubObject("Open(const QString&)",qstr);
    auto sheets    = workbook->querySubObject("Worksheets");
    auto sheet     = sheets->querySubObject("Item(int)", 1);

    // read the first cells in row 1...18177
    for (int r = 1; (r <= 18177); ++r)
    {
        auto cCell = sheet->querySubObject("Cells(int,int)",r,1);
        qDebug() << cCell->dynamicCall("Value()").toInt();
    }
    */
 /*
//    ifstream myfile;
//    myfile.open(d_filename);
//    if (myfile.is_open())
//    {
//        qDebug()<<"berkas telah dibuka"<< endl;
//        while(myfile.good()){
//            // line;
//            getline(myfile,line,',');
//           // cout<<line<<endl;
//        }
//       }
//    else{
//        qDebug()<<"tidak ada file yang dibuka"<<endl;
//    }
QString qstr = QString::fromStdString(d_filename);
// Baca data file CSV dan simpan dalam array (2 dimensi)
    QFile inputfile (qstr);
    inputfile.open(QIODevice::ReadOnly);
    if (!inputfile.isOpen())
        return true;

    QTextStream stream (&inputfile);
    QString line = stream.readLine();
    if (!line.isNull()){
    int baris=1;
    int kolom=1;
    while (kolom < 1001){
        while (baris < 1001){
            line = stream.readLine();
            QByteArray hhh = line.toLocal8Bit();
            const char *line1= hhh.data();
                       sscanf(line1,"%d",&ko[baris][kolom]);
                        qDebug() << "hayo ke:" <<line << "jadinya:%d" << &ko[baris][kolom];
                       baris++;
        }
        kolom++;
    }

 }
    else {
        inputfile.close();
    }
*/
/*
    QCheckBox *checkbox = new QCheckBox();
    //checkbox->setChecked(false);
    if (!checkbox->isChecked()){
        putText(frame,line,Point2f(100,100),FONT_HERSHEY_PLAIN,2,  Scalar(0,0,255), 2 , 8 , false);
    }else{
        QMessageBox msgeBox;
        msgeBox.setText("Anda tidak menampilkan data");
        msgeBox.exec();
    }
*/
  //  return true;

//}
bool Player :: lokasiVideo(String lokasi){
     lokvideo = QString::fromStdString(lokasi);
    //qDebug()<<lokvideo<<endl;
    lokasivideo = lokvideo.toLocal8Bit().constData(); //Qstring to std string
   // cout<<lokasivideo<<endl;
    return true;

}
bool Player :: loadWaktu(String datawaktu){
    waktu = QString ::fromStdString(datawaktu);
    DataWaktu = waktu.toLocal8Bit().constData();
    return true;
}
void Player :: run()
{
    int frame_width = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    video.open(lokasivideo,CV_FOURCC('M','J','P','G'),frameRate,Size(frame_width,frame_height),true);
    if (!video.isOpened()) {
            qDebug() << "Could not open the output video file for write\n"<<endl;
        }
    int delay =(1000/frameRate);
    while (!stop) {
        if(!capture.read(frame))
        {
            stop=true;
            break;

        }

        image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");
        image4 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\unnamed (1).png");
        resize(image4, enlarged, cv::Size(image4.cols*2, image4.rows*2), cv::INTER_NEAREST);
        resize(enlarged,image5,Size(),0.5,0.5);
        resize(image2,image3,Size(),0.50,0.50);
        Rect ROI (0,0,image3.cols,image3.rows);
        baru= frame(ROI);
       //grayscale
         cvtColor(image3,gray,CV_BGR2GRAY);
         double thresh = 10;
         double maxValue = 255;
         threshold(gray,tress, thresh, maxValue, THRESH_BINARY);
          bitwise_not(tress,maskInv);
          bitwise_and(baru,baru,imgbg,maskInv);
          bitwise_and(image3,image3,imgfg,tress);
          add(imgbg,imgfg,sum);
            frame=frame.clone();
          for(int i=0;i<image3.rows;i++){
              for(int j=0;j<image3.cols;j++){

                  {
                          frame.at<Vec3b>(i,j)[0]= sum.at<Vec3b>(i,j)[0];
                          frame.at<Vec3b>(i,j)[1]= sum.at<Vec3b>(i,j)[1];
                          frame.at<Vec3b>(i,j)[2]= sum.at<Vec3b>(i,j)[2];
              }

          }
        }
          Rect ROI1 (frame.cols-image5.cols,image5.rows,image5.cols,image5.rows);
          Mat baru1= frame(ROI1);
          Mat mask(image5);
          image5.copyTo(baru1,mask);
        video.write(frame);
    putText(frame,DataWaktu,Point2f(100,100),FONT_HERSHEY_PLAIN,2,  Scalar(0,0,255), 2 , 8 , false);
        if (frame.channels()==3){
            cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),
                         RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {
            img =QImage((const unsigned char*)(frame.data),
                    frame.cols,frame.rows,QImage::Format_Indexed8);

        }
        /*
        QPainter p(&img);
        p.setPen(QPen(Qt::red));
        p.setFont(QFont("Times",100,QFont::Bold));
        p.drawText(img.rect(),Qt::AlignCenter,qstr);
        */
        emit processedImage(img);
        this->msleep(delay);

    }


}


Player ::~Player()
{
    mutex.lock();
    stop =true;
    capture.release();
    condition.wakeOne();
    mutex.unlock();
    wait();
}
void Player::Stop()
{
    stop = true;
}
void Player ::msleep(int ms){
    struct timespec ts = {ms/1000,(ms % 1000)*1000*1000};
    nanosleep(&ts,NULL);
}
bool Player::isStopped() const{
    return this->stop;
}

