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
#include <QTime>
#include <QDate>
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

bool Player :: loadData(String d_filename){
       // int data[160] =atoi(d_filename.c_str());
        //for(i=0;i<=160;i++){ data[]

        //}
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
    while (baris <=totalframe){
        line = stream.readLine();
        QByteArray hhh = line.toLocal8Bit();
        const char *line1= hhh.data();
                   sscanf(line1,"%d ,%d ,%d ,%d, %d,%d,%d,%d",&ko[baris][1],&ko[baris][2],&ko[baris][3],&ko[baris][4],&ko[baris][5],&ko[baris][6],&ko[baris][7],&ko[baris][8]);
                   qDebug() << "baris" << baris <<"hayo ke:" <<line << "jadinya: " <<ko[baris][1]<< " " << ko[baris][2] << " " << ko[baris][3] << " " << ko[baris][4] << " " << ko[baris][5] << " " << ko[baris][6];
                          baris++;

                             }

 }
    else {
        inputfile.close();
    }
   return true;

}
double Player :: nyatuin3waktu(){

    return true;
}
/*
double Player :: ngurutinwaktu(){
    for(int i=0;i<=totalframe;i++){
        for(int j=0;j<=totalframe-i;j++){
            if(ko[j]>ko[j+1]){
                int temp = ko[j];
                ko[j]=ko[j+1];
                ko[j+1]=temp;
            }
        }
    }
    return true;
}
*/
bool Player :: lokasiVideo(String lokasi){
     lokvideo = QString::fromStdString(lokasi);
    //qDebug()<<lokvideo<<endl;
    lokasivideo = lokvideo.toLocal8Bit().constData(); //Qstring to std string
   // cout<<lokasivideo<<endl;
    return true;

}
bool Player :: loadWaktu(String datawaktu){
    QString ok = QString::fromStdString(datawaktu);
  int maka= ok.toInt();
    if (maka >0){
        DataWaktu= "Waktu : ";
        wak =1;
    }
   else {
        DataWaktu= "0";
        wak =0;
    }
    return true;
/*
    waktu = QString ::fromStdString(datawaktu);
    DataWaktu= waktu.toLocal8Bit().constData();

    return true;
    */
}
bool Player :: loadKeceptan(String datakecepatan){
    QString ok1 = QString::fromStdString(datakecepatan);
    int moka = ok1.toInt();;
    if (moka >0){
        DataKecepatan= "Kecepatan: ";
        kec =1;
    }
    else {
        DataKecepatan= "Kecepatan : -";
        kec =0;
    }
    qDebug() << " " <<kec;
     return true;
    /*
    kecepatan =QString ::fromStdString(datakecepatan);
    DataKecepatan = kecepatan.toLocal8Bit().constData();
     return true;
     */
}
bool Player ::loadAltitude(String dataaltitude){
    QString ok2 = QString::fromStdString(dataaltitude);
    int mika = ok2.toInt();;
    if (mika>0){
        DataAltitude= "Altitude: ";
        alt =1;
    }
    else {
        DataAltitude= "Altitude: -";
        alt =0;
    }
    return true;
    /*
    altitude=QString :: fromStdString(dataaltitude);
    DataAltitude = altitude.toLocal8Bit().constData();
    return true;
    */
}
bool Player :: loadRoll(String dataroll){
    /*
    roll=QString :: fromStdString(dataroll);
    DataRoll = roll.toLocal8Bit().constData();
    return true;
    */
    QString ok3 = QString::fromStdString(dataroll);
    int mina = ok3.toInt();;
    if (mina >0){
        DataRoll= "Roll: ";
        rol =1;
    }
    else {
        DataRoll= "Roll: -";
        rol =0;
    }
    return true;
}
bool Player :: loadLongitude(String datalongitude){
    /*
    longitude=QString :: fromStdString(datalongitude);
    DataLongitude = longitude.toLocal8Bit().constData();
    return true;
    */
    QString ok4 = QString::fromStdString(datalongitude);
    int minu = ok4.toInt();;
    if (minu >0){
        DataLongitude= "Longitude: ";
        log =1;
    }
    else {
        DataLongitude= "Longitude: -";
        log =0;
    }
    return true;
}
bool Player :: loadPitch(String datapitch){
    QString ok5 = QString::fromStdString(datapitch);
    int mona = ok5.toInt();;
    if (mona >0){
        DataPitch= "Pitch: ";
        pit =1;
    }
    else {
        DataPitch= "Pitch: -";
        pit =0;
    }
    return true;
    /*
    pitch=QString :: fromStdString(datapitch);
    DataPitch = pitch.toLocal8Bit().constData();
    return true;
    */
}
bool Player :: loadLatitude(String datalatitude){
    QString ok6 = QString::fromStdString(datalatitude);
    int mono = ok6.toInt();;
    if (mono >0){
        DataLatitude= "Latitude: ";
        lat =1;
    }
    else {
        DataLatitude= "Latitude: -";
        lat =0;
    }
    return true;
    /*
    latitude=QString :: fromStdString(datalatitude);
    DataLatitude = latitude.toLocal8Bit().constData();
    return true;
    */

}
bool Player :: loadYaw(String datayaw){
    QString ok7 = QString::fromStdString(datayaw);
    int melu = ok7.toInt();;
    if (melu >0){
        DataYaw= "Yaw: ";
        yaw =1;
    }
    else {
        DataYaw= "Yaw: -";
        yaw =0;
    }
    return true;
    /*
    yaw=QString :: fromStdString(datayaw);
    DataYaw = yaw.toLocal8Bit().constData();
    return true;
    */
}
void Player :: run()
{
     kunci =1;
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
        resize(image4, enlarged, cv::Size(frame.cols-(0.90*frame.cols), frame.rows-(0.15*frame.rows)), cv::INTER_NEAREST);
        resize(image2,image3,Size(),0.50,0.50);
        double angle =-90;
        //mendapatkan matriks rotasi untuk memutar gambar di sekitar pusatnya dalam koordinat piksel
        Point2f center((image3.cols-1)/2.0, (image3.rows-1)/2.0);
        //tentukan bounding rectangle, center tidak relevan
        Mat rot = getRotationMatrix2D(center, angle, 1.0);
        Rect2f bbox = cv::RotatedRect(cv::Point2f(), image3.size(), angle).boundingRect2f();
        //menyesuaikan transformasi matriks
        rot.at<double>(0,2) += bbox.width/2.0 - image3.cols/2.0;
        rot.at<double>(1,2) += bbox.height/2.0 - image3.rows/2.0;
        //wrapsemua kedalam mat tjn
        warpAffine(image3, tjn, rot, bbox.size());
        Rect ROI (0,0,tjn.cols,tjn.rows);
        baru= frame(ROI);
       //grayscale
         cvtColor(tjn,gray,CV_BGR2GRAY);
         double thresh = 10;
         double maxValue = 255;
         threshold(gray,tress, thresh, maxValue, THRESH_BINARY);
          bitwise_not(tress,maskInv);
          bitwise_and(baru,baru,imgbg,maskInv);
          bitwise_and(tjn,tjn,imgfg,tress);
          add(imgbg,imgfg,sum);
            frame=frame.clone();
          for(int i=0;i<tjn.rows;i++){
              for(int j=0;j<tjn.cols;j++){

                  {
                          frame.at<Vec3b>(i,j)[0]= sum.at<Vec3b>(i,j)[0];
                          frame.at<Vec3b>(i,j)[1]= sum.at<Vec3b>(i,j)[1];
                          frame.at<Vec3b>(i,j)[2]= sum.at<Vec3b>(i,j)[2];
              }

          }
        }
          //grafik skala sebelah kanan frame//
          Rect ROI1 (frame.cols-enlarged.cols-20,frame.rows-enlarged.rows-50,enlarged.cols,enlarged.rows);
          Mat baru1= frame(ROI1);
          Mat mask(enlarged);
          enlarged.copyTo(baru1,mask);
          video.write(frame);
          /*
          Mat roi = frame(cv::Rect(110, 370, 500, 200));
          Mat color(roi.size(), CV_8UC3, cv::Scalar(0,0, 0));
        double alpha = 0.4;
        addWeighted(color, alpha, roi, 1.0 - alpha , 0.0, roi);
        */
          // menambahkan background
          int x = frame.cols*0.2 ;
          int y = frame.rows*0.67;
          int lebar = frame.cols*0.6;
          int tinggi= frame.rows*0.3;
          Mat roi =frame(cv::Rect(x,y,lebar,tinggi));
          Mat color (roi.size(),CV_8UC3,cv::Scalar(0,0,0));
          double alpha =0.4;
          addWeighted(color,alpha,roi,1.0 - alpha,0.0,roi);
        //grafik skala sebelah kiri frame//
        flip(enlarged,flip1,+1);
        Rect ROI2(frame.cols-flip1.cols-640,frame.rows-flip1.rows-50,flip1.cols,flip1.rows);
        Mat baru2 = frame(ROI2);
        Mat mask1(flip1);
        flip1.copyTo(baru2,mask1);
        /*
        //grafik skala sebelah atas frame //
        resize(enlarged,enlarged1,Size(),0.8,0.8);
        transpose(enlarged1,gfatas);
        flip(gfatas,grafikatas,0);
        Rect ROI3(frame.cols-555,frame.rows-image4.rows-330,grafikatas.cols,grafikatas.rows);
        Mat baru3 =frame(ROI3);
        Mat mask2(grafikatas);
        grafikatas.copyTo(baru3,mask2);
        */
        QString Time;
        int omo;
        if (wak > 0){
            omo = ko[kunci][1];
            QString angka = QString::number(omo);

             Time = DataWaktu + angka;
        }
        else {
            Time = DataWaktu;
        }
        string waktu1 = Time.toLocal8Bit().constData();
        QString fast;
        if (kec > 0){
            int om1 = ko[kunci][2];
            QString angku = QString::number(om1);
            fast = DataKecepatan + angku;
        }
        else {
            fast = DataKecepatan;
        }
        string kecepatan1 = fast.toLocal8Bit().constData();
        QString ALT;
        if (alt > 0){
            int om2 = ko[kunci][3];
            QString angkk = QString::number(om2);
             ALT = DataAltitude + angkk;
        }
        else {
            ALT = DataAltitude;
        }
        string Altitude1 = ALT.toLocal8Bit().constData();
        QString Rol;
        if (rol > 0){
            int om3 = ko[kunci][4];
            QString angk = QString::number(om3);
             Rol = DataRoll + angk;
        }
        else {
            Rol = DataRoll;
        }
        string Roll1 = Rol.toLocal8Bit().constData();
        QString Long;
        if (log > 0){
            int om4 = ko[kunci][5];
            QString angkl = QString::number(om4);
             Long = DataLongitude + angkl;
        }
        else {
             Long = DataLongitude;
        }

        string Longitude1 = Long.toLocal8Bit().constData();
        QString Pitc;
        if (pit > 0){
            int om5 = ko[kunci][6];
            QString ang = QString::number(om5);
            Pitc = DataPitch + ang;
        }
        else {
            Pitc = DataPitch;
        }
        string Pitch1 = Pitc.toLocal8Bit().constData();
        QString Lat;
        if (lat > 0){
            int om6 = ko[kunci][7];
            QString anka = QString::number(om6);
            Lat = DataLatitude + anka;
        }
        else {
            Lat = DataLatitude;
        }
        string Latitude1 = Lat.toLocal8Bit().constData();
        QString Yaw;
        if (yaw > 0){
            int om7 = ko[kunci][8];
            QString angko = QString::number(om7);
            Yaw = DataYaw + angko;
        }
        else {
            Yaw = DataYaw;
        }
        string Yaw1 = Yaw.toLocal8Bit().constData();
        if(waktu1=="0"){
       putText(frame,"Waktu : -",Point(150, 430),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
        }
        //Posisi
        int x1 = frame.cols*0.2 +10;
        int y1 = frame.rows*0.67 +20;
        int x2 = lebar/2 +x1 +10;
    putText(frame,waktu1,Point(x1,y1),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,kecepatan1,Point2f(x1,y1+40),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,Altitude1,Point2f(x1,y1+80),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,Roll1,Point2f(x1,y1+120),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,Longitude1,Point2f(x2,y1),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,Pitch1,Point2f(x2,y1+40),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,Latitude1,Point2f(x2,y1+80),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,Yaw1 ,Point2f(x2,y1+120),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
        //menambahkan tanggal dan waktu
        QDate cd = QDate::currentDate();
        QTime ct = QTime::currentTime();
          tanggal= cd.toString();
           jam   = ct.toString();
           string tanggalbaru = tanggal.toLocal8Bit().constData();
           string jambaru = jam.toLocal8Bit().constData();
    putText(frame,tanggalbaru+" | "+jambaru,Point2f(frame.cols-300,frame.rows*0.05),FONT_HERSHEY_SIMPLEX,0.6,Scalar(0,0,0),1.6,LINE_AA);
      //konversi BGR ke RGB
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
        emit processedImage(img);
        this->msleep(delay);
   kunci ++;
    }

}
/*
void Player :: ~run(){
    int frame_width1 = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height1 = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    VideoWriter video("outcpp.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width1,frame_height1));
    while(1){
       Mat video1,img1;
       capture>>video1;
       if(video1.empty()){
           break;
       }
       video.write(video1);
       if (video1.channels()==3){
           cv::cvtColor(video1, RGBframe, CV_BGR2RGB);
           img1 = QImage((const unsigned char*)(RGBframe.data),
                        RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
       }
       else
       {
           img1 =QImage((const unsigned char*)(video1.data),
                   video1.cols,video1.rows,QImage::Format_Indexed8);

       }
    }
}

*/
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

