#include "mainwindow.h"
#include <QApplication>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"
#include "iostream"
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    Mat image =imread("D:\\Capture gambar\\gambar.png");
    Mat image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");
    Mat image3;
    resize(image2,image3,Size(),0.50,0.50);
    Rect ROI (0,0,image3.cols,image3.rows);
     Mat baru= image(ROI);
    //grayscale
     Mat gray,tress,maskInv,imgbg,imgfg,sum,dst,fix;
      cvtColor(image3,gray,CV_BGR2GRAY);
      double thresh = 10;
      double maxValue = 255;
      threshold(gray,tress, thresh, maxValue, THRESH_BINARY);
       bitwise_not(tress,maskInv);
       bitwise_and(baru,baru,imgbg,maskInv);
       bitwise_and(image3,image3,imgfg,tress);
       add(imgbg,imgfg,sum);
         dst=image.clone();
       for(int i=0;i<image3.rows;i++){
           for(int j=0;j<image3.cols;j++){

               {
                       dst.at<Vec3b>(i,j)[0]= sum.at<Vec3b>(i,j)[0];
                       dst.at<Vec3b>(i,j)[1]= sum.at<Vec3b>(i,j)[1];
                       dst.at<Vec3b>(i,j)[2]= sum.at<Vec3b>(i,j)[2];
           }

       }
     }

       namedWindow("image",CV_WINDOW_FREERATIO);
       imshow("image",dst);
       gray.release(); tress.release();maskInv.release();imgbg.release();
       imgfg.release(); baru.release(); sum.release();image.release(); image2.release();
         cvtColor(dst, fix, CV_BGR2RGB);
/*

    Mat gray;
    Mat mask;
    Mat dst;
    cvtColor(image2,gray,CV_BGR2GRAY);
    double thresh = 0;
    double maxValue = 255;
    threshold(gray,mask, thresh, maxValue, THRESH_BINARY);
    bitwise_not(mask,dst);
    bitwise_and(baru,baru,mask=dst);
    bitwise_and(image2,image2,mask=mask);
    add()
    namedWindow("image",CV_WINDOW_FREERATIO);
     imshow("image",mask);









    Mat new_image1;

    if (image.empty()) {
                      cout << "Error" << endl;
                      return -1;
             }
    if (image1.empty()){
            cout << "Error"<< endl;
            return -1;
    }
    int m=400; int n=200;
   resize(image1, new_image1, cvSize(250, 75));
   image2.copyTo(image(cv::Rect(m,n,image2.cols,image2.rows)));
    Rect Roi (0,0);
    cout << "image1 channels: " << image1.channels()<< endl;
    cout << "image channels: " << image.channels() <<  endl;
    for (int i=0;i<image.rows;i++){
        for (int j=0;j<image.cols;j++){
            if(image.at<Vec3b>(i,j)[0]==0 && image.at<Vec3b>(i,j)[1]==0 && image.at<Vec3b>(i,j)[2]==0){
                image.at<Vec3b>(i,j)[0]=225;
                image.at<Vec3b>(i,j)[1]=225;
                image.at<Vec3b>(i,j)[2]=225;
            }

            else{
                image.at<Vec3b>(i,j)[0]=image.at<Vec3b>(i,j)[0];
                image.at<Vec3b>(i,j)[1]=image.at<Vec3b>(i,j)[1];
                image.at<Vec3b>(i,j)[2]=image.at<Vec3b>(i,j)[2];
            }

           }
        }
    namedWindow("image",CV_WINDOW_FREERATIO);
     imshow("image",image);
    cout <<"pixcel value:"<<endl;
      //waitKey(0);

      if (image.channels() == 1) {
          for (int y = 0; y < image.cols; y++) {
                                       for (int x = 0; x < image.rows; x++) {
                                                Scalar pixel = image.at<uchar>(x, y);
                                                cout << pixel.val[0] << ",";
                                       }
                                       cout << endl;
                             }
                         //Scalar pixel = image.at<uchar>(10, 10);
                         //cout << "Pixel value at 5,6 cordinate : " << pixel.val[0] << endl;
                }
      else if (image.channels() == 3) {
          for (int i=0;i<image.cols;i++){
              for (int j=0;j<image.rows;j++){
                  Vec3b pixel = image.at<Vec3b>(j,i );
                                                        int blue = pixel.val[0];
                                                        int green = pixel.val[1];
                                                        int red = pixel.val[2];
                                                       cout << "[" << blue << " " << green << " " << red << "],";

                                               }
             cout << endl;
              }
          }


      else {
               cout << "this is not a single channel image" << endl;
      }

      waitKey(0);
    for (int i=0;i<image.rows;i++){
        for (int j=0;j<image.cols;j++){
            if(image.at<Vec3b>(i,j)[0]==52 && image.at<Vec3b>(i,j)[1]==152 && image.at<Vec3b>(i,j)[2]==219){
                image.at<Vec3b>(i,j)[0]=0;
                image.at<Vec3b>(i,j)[1]=0;
                image.at<Vec3b>(i,j)[2]=0;
            }

            else{
                image.at<Vec3b>(i,j)[0]=225;
                image.at<Vec3b>(i,j)[1]=225;
                image.at<Vec3b>(i,j)[2]=225;
            }

           }
        }

    namedWindow("output",CV_WINDOW_FREERATIO);
    imshow("output",image);
    */
  waitKey(0);
  return a.exec();
      }
//












