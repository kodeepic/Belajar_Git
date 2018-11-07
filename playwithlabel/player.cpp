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
//#include <math.h>
using namespace std;

// Variabel Array untuk menampung data penerbangan


Player::Player(QObject *parent) : QThread(parent)
{
    stop =true;

}

bool Player :: loadVideo(String filename){
    capture.open(filename);
    if(capture.isOpened())
        //frame_width = int(capture.get(3));
        //frame_height = int(capture.get(4));
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
//MATFILE *pmat;
//matOpen();
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

        while (baris <= 1001){
            line = stream.readLine();
            QByteArray hhh = line.toLocal8Bit();
            const char *line1= hhh.data();
                       sscanf(line1,"%f ,%f ,%f ,%f, \"%f\",%d,%d,%d",&ko[baris][1],&ko[baris][2],&ko[baris][3],&ko[baris][4],&ko[baris][5],&ko[baris][6],&ko[baris][7],&ko[baris][8]);
                       qDebug() << "baris" << baris <<"hayo ke:" <<line << "jadinya: " <<ko[baris][1]<< " " << ko[baris][2] << " " << ko[baris][3] << " " << ko[baris][4] << " " << ko[baris][5] << " " << ko[baris][6];

                       baris++;
        }

 }
    else {
        inputfile.close();
    }
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


    return true;

}

void Player :: run()
{

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
        resize(enlarged,image5,Size(),0.7,0.7);
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
    putText(frame,line,Point2f(100,100),FONT_HERSHEY_PLAIN,2,  Scalar(0,0,255), 2 , 8 , false);
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

//hahahahah
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

