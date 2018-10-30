#include "player.h"
#include <QPainter>
#include <QDebug>
#include <QAxObject>
#include <QSqlQuery>
#include <QtCore>
#include <iostream>
#include <fstream>
#include <QString>
using namespace std;


Player::Player(QObject *parent) : QThread(parent)
{
    stop =true;
}

bool Player :: loadVideo(String filename){
    capture.open(filename);
    if(capture.isOpened())
    {
        frameRate = (int) capture.get(CV_CAP_PROP_FPS);
        return true;
    }
    else
        return false;
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
    ifstream myfile;
    myfile.open(d_filename);
    if (myfile.is_open())
    {
        qDebug()<<"berkas telah dibuka"<< endl;
        while(myfile.good()){
            string line;
            getline(myfile,line,';');
            cout<<line<<endl;
        }
       }
    else{
        qDebug()<<"tidak ada file yang dibuka"<<endl;
    }
    return true;
}

void Player :: run()
{

    int delay =(1000/frameRate);
    while (!stop) {
        if(!capture.read(frame))
        {
            stop=true;

        }
         image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");
         Rect ROI (0,0,image2.cols,image2.rows);
         baru= frame(ROI);
       //grayscale
         cvtColor(image2,gray,CV_BGR2GRAY);
         double thresh = 10;
         double maxValue = 255;
         threshold(gray,tress, thresh, maxValue, THRESH_BINARY);
          bitwise_not(tress,maskInv);
          bitwise_and(baru,baru,imgbg,maskInv);
          bitwise_and(image2,image2,imgfg,tress);
          add(imgbg,imgfg,sum);
            frame=frame.clone();
          for(int i=0;i<image2.rows;i++){
              for(int j=0;j<image2.cols;j++){

                  {
                          frame.at<Vec3b>(i,j)[0]= sum.at<Vec3b>(i,j)[0];
                          frame.at<Vec3b>(i,j)[1]= sum.at<Vec3b>(i,j)[1];
                          frame.at<Vec3b>(i,j)[2]= sum.at<Vec3b>(i,j)[2];
              }

          }
        }
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
        p.drawText(img.rect(),Qt::AlignCenter,"Text");
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
