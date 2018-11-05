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
    Mat image5 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\.png");
    Mat image3,image4;
    Mat tjn;
    resize(image2,image3,Size(),0.43,0.35);
    resize(image5,image4, Size(),0.20,0.20);
    double angle = 90;
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
    //memanggil mat tjn dan diukur
    Rect ROI (0,0,tjn.cols,tjn.rows);
     Mat baru= image(ROI);
    //grayscale
     Mat gray,tress,maskInv,imgbg,imgfg,sum,dst;
      cvtColor(tjn,gray,CV_BGR2GRAY);
      double thresh = 10;
      double maxValue = 255;
      threshold(gray,tress, thresh, maxValue, THRESH_BINARY);
       bitwise_not(tress,maskInv);
       bitwise_and(baru,baru,imgbg,maskInv);
       bitwise_and(tjn,tjn,imgfg,tress);
       add(imgbg,imgfg,sum);
         dst=image.clone();
       for(int i=0;i<tjn.rows;i++){
           for(int j=0;j<tjn.cols;j++){

               {
                       dst.at<Vec3b>(i,j)[0]= sum.at<Vec3b>(i,j)[0];
                       dst.at<Vec3b>(i,j)[1]= sum.at<Vec3b>(i,j)[1];
                       dst.at<Vec3b>(i,j)[2]= sum.at<Vec3b>(i,j)[2];
           }

       }
     }
// const int x = 100;
// const int y = 100;

Rect ROI1 (dst.cols-image4.cols,dst.rows-image4.rows,image4.cols,image4.rows);
Mat baru1= dst(ROI1);
/*
Mat mask(image4);
image4.copyTo(baru1,mask);
*/

Mat gray1,tress1,maskInv1,imgbg1,imgfg1,sum1,dst1;
cvtColor(image4,gray1,CV_BGR2GRAY);
double thresh1 = 10;
double maxValue1 =255;
threshold(gray1,tress1, thresh1, maxValue1, THRESH_BINARY);
bitwise_not(tress1,maskInv1);
bitwise_and(baru1,baru1,imgbg1,maskInv1);
bitwise_and(image4,image4,imgfg1,tress1);
add(imgbg1,imgfg1,sum1);
dst1= dst.clone();
for(int i=0;i<image4.rows;i++){
    for(int j=0;j<-image4.cols;j++){

        {
                dst1.at<Vec3b>(i,j)[0]= sum1.at<Vec3b>(i,j)[0];
                dst1.at<Vec3b>(i,j)[1]= sum1.at<Vec3b>(i,j)[1];
                dst1.at<Vec3b>(i,j)[2]= sum1.at<Vec3b>(i,j)[2];
    }

}
}

       namedWindow("image",CV_WINDOW_FREERATIO);
       imshow("image",dst);
       gray.release(); tress.release();maskInv.release();imgbg.release();
       imgfg.release(); baru.release(); sum.release();image.release(); image2.release();

        // cvtColor(dst, fix, CV_BGR2RGB);
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












