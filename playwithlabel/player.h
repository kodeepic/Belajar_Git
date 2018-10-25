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
using namespace cv;

class Player : public QThread
{
    Q_OBJECT
private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
    int frameRate;
    VideoCapture capture;
    Mat RGBframe;
    QImage img;
    QImage gambar;
    Mat gray,tress,maskInv,imgbg,imgfg,sum,image2,baru;

public:
    //explicit Player(QWidget *parent = nullptr);
    Player(QObject *parent = 0);
    ~Player();
    bool loadVideo(String filename);
    bool loadData (String d_filename);
    void Play();
    void Stop();
    bool isStopped() const;
    void setCurrentFrame(int frameNumber);
    double getFrameRate();
    double getCurrentFrame();
    double getNumberOfFrames();
signals:
void processedImage(const QImage &image);
protected:
  //  void paintEvent(QPaintEvent *);
void run();
void msleep(int ms);
};
#endif // PLAYER_H
