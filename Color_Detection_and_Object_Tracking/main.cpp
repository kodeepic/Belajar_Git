#include "mainwindow.h"
#include <QApplication>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    VideoCapture cap(0);
    if (!cap.isOpened()){
        cout<<"Cannot Open the web cam" << endl;
        return -1;
    }
     namedWindow("control",CV_WINDOW_AUTOSIZE);
     int iLowR =0;
     int iHighR =255;

     int iLowG =0;
     int iHighG = 100;

     int iLowB =0;
     int iHighB =100;

     cvCreateTrackbar("LowR","Control",&iLowR,255);
     cvCreateTrackbar("HighR","Control",&iHighR,255);

     cvCreateTrackbar("LowG","Control",&iLowG,100);
     cvCreateTrackbar("HighG","Control",&iHighG,100);

     cvCreateTrackbar("LowB","Control",&iLowB,100);
     cvCreateTrackbar("HighB","Control",&iHighB,100);

     while(true){
         Mat imgOriginal;
         bool bSuccess=cap.read(imgOriginal);
         if(!bSuccess){
             cout<<"Cannot read frame from video stream"<< endl;
             break;
         }


     Mat imgRGB;
     cvtColor(imgOriginal,imgRGB,COLOR_BGR2RGB);
     Mat imgThreshold;
     inRange(imgRGB,Scalar(iLowR,iLowG,iLowB),Scalar(iHighR,iHighG,iHighB),imgThreshold);
     erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
     dilate( imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

     dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
     erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

     imshow("Thresholded Image", imgThreshold); //show the thresholded image
       imshow("Original", imgOriginal); //show the original image
       if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
              {
                   cout << "esc key is pressed by user" << endl;
                   break;
              }
           }

         return 0;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
