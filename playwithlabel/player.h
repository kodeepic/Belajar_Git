#ifndef PLAYER_H
#define PLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QPaintEvent>
#include <iostream>
#include <fstream>
#include <QString>
#include <string>

using namespace cv;
using namespace std;

class Player : public QThread
{
    Q_OBJECT
private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
   // int fps;
    int frameRate;
    int totalframe;
    VideoCapture capture;
    VideoWriter video;
    Mat RGBframe;
    QImage img;
    QImage gambar;
    Mat gray,tress,maskInv,imgbg,imgfg,sum,image2,baru,vect,image3,image4,enlarged,image5,tjn,flip1,gfatas,grafikatas,enlarged1;
  // string line; //jika ingin menggunakan putText via opencv
   // QString qstr = QString::fromStdString(line); //jika ingin ditampilkan dalam Drawtext via QPainter
    float ko[100000][20];
    float ko1[100000][20];
    float ko2[100000][20];
    float lo[100000][20];
        float lo1[100000][20];
        float ko3[100000][20];
        int JML;
        int JML1;
        int ini=1;
   //int golwaktu [10000][10000];
    //int ini=1;
   // QString lokvideo,waktu,kecepatan,altitude,roll,longitude,pitch,latitude,yaw;
    //string lokasivideo,DataWaktu,DataKecepatan,DataAltitude,DataRoll,DataLongitude,DataPitch,DataLatitude,DataYaw;
    QString lokvideo,DataWaktu,DataKecepatan,DataAltitude,DataRoll,DataLongitude,DataPitch,DataLatitude,DataYaw,tanggal_tercipta,tanggal_modifikasi;
    QString infovideo;
    string lokasivideo;
     int keadaan,keadaan1;
public:
    //explicit Player(QWidget *parent = nullptr);
    Player(QObject *parent = 0);
    ~Player();
    bool loadVideo(String filename);    //memanggil filename dari mainwindow.cpp
    bool loadData (String d_filename); //memanggil d_filename dari mainwindow.cpp
    bool loadWaktu (String datawaktu);
    bool loadKeceptan(String datakecepatan);
    bool loadAltitude (String dataaltitude);
    bool loadRoll(String dataroll);
    bool loadLongitude(String datalongitude);
    bool loadPitch(String datapitch);
    bool loadLatitude(String datalatitude);
    bool loadYaw(String datayaw);
    bool lokasiVideo(String lokasi);
    bool loadBaterai(String databaterai);
    void Play();
    void Stop();
    bool isStopped() const;
    void setCurrentFrame(int frameNumber);
    bool SetPoint (String KDS);
    double getFrameRate();
    double getCurrentFrame();
    double getNumberOfFrames();
    //bool MengurutkanData();
    int wak =0 ;
    int kec, alt,bat,rol,pit,yaw,log,lat,Baterai;
    int columnCount;
    int rowCount;
    int lk;
    int kunci;
    //int data[100][100];
    //bool pengurutan;
signals:
void processedImage(const QImage &image);
void urutan (int kunci);
protected:
void run();
void msleep(int ms);
};
#endif // PLAYER_H
