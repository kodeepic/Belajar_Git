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
    /*
    Mat frame = imread("D:\\Capture gambar\\gambar.png");
    putText(frame,"10",Point(58, 514),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,"20",Point(58, 489),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,"30",Point(58, 465),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,"40",Point(58, 440),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,"50",Point(74, 418),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,"60",Point(58, 396),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,"70",Point(58, 372),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,"80",Point(58, 347),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
    putText(frame,"90",Point(58, 321),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"100",Point(74, 298),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"110",Point(58, 276),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"120",Point(58, 252),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"130",Point(58, 229),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"140",Point(58, 203),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"150",Point(74, 179),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"160",Point(58, 156),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"170",Point(58, 132),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"180",Point(58, 108),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"190",Point(58,83),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     putText(frame,"200",Point(74, 61),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255, 255, 255),1.6,LINE_AA);
     Rect r=Rect(22,68,70,20);
     Rect s=Rect(22,164,85,20);
     rectangle(frame,r,Scalar(255,255,255),2,8,0);
     rectangle(frame,s,Scalar(255,255,255),2,8,0);
    imshow( "Frame",frame);
    */
    /*
    VideoCapture cap("C:\\Users\\Ariku\\Documents\\MATLAB\\terbang.mp4");

     // Check if camera opened successfully
     if(!cap.isOpened()){
       cout << "Error opening video stream or file" << endl;
       return -1;
     }
     // Default resolution of the frame is obtained.The default resolution is system dependent.
     int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
     int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

     // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
     VideoWriter video("D:\\ujicoba1.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height));
     while(1)
     {
       Mat frame;

       // Capture frame-by-frame
       cap >> frame;

       // If the frame is empty, break immediately
       if (frame.empty())
         break;

       // Write the frame into the file 'outcpp.avi'
       video.write(frame);

       // Display the resulting frame
      imshow( "Frame", frame );

       // Press  ESC on keyboard to  exit
      char c = (char)waitKey(1);
      if( c == 27 )
         break;
     }

     // When everything done, release the video capture and write object
     cap.release();
     video.release();

     // Closes all the windows
     destroyAllWindows();
     return 0;
*/

    /*
    Mat image5gray,mask_ani,mask_ani_inv,image5,dst1;
     Mat image =imread("D:\\Capture gambar\\gambar.png");
     Mat image4 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\unnamed.png");
     resize(image4,image5, Size(),0.8,0.8);
    cvtColor(image5, image5gray, CV_BGR2GRAY);
    threshold(image5gray, mask_ani, 10, 255, 0);
      bitwise_not(mask_ani, mask_ani_inv);
      Mat imgRoi;
          imgRoi = image(Rect(50, 50, image5.cols,image5.rows));
          Mat me_back;
              Mat ani_for;
               bitwise_and(image5, image5, ani_for, mask_ani);
                bitwise_and(imgRoi, imgRoi, me_back, mask_ani_inv);
              Mat dst;
                  add(me_back, ani_for, dst);
              dst.copyTo(imgRoi);


              Mat roi = image(cv::Rect(170, 350, 400, 200));
              Mat color(roi.size(), CV_8UC3, cv::Scalar(0,0, 0));
                  double alpha = 0.4;
              addWeighted(color, alpha, roi, 1.0 - alpha , 0.0, roi);
              putText(image, "Waktu",Point(175, 380),FONT_HERSHEY_SIMPLEX,0.6,Scalar(255, 255, 255),1.6,LINE_AA);
              */
/*

    Mat image =imread("D:\\Capture gambar\\gambar.png");
    Mat image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");
    Mat image5 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\learncorel1.png");
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

Mat mask(image4);
image4.copyTo(baru1,mask);

/*
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
*/

       //namedWindow("image",CV_WINDOW_FREERATIO);
      // imshow("image",image);
       //gray.release(); tress.release();maskInv.release();imgbg.release();
      // imgfg.release(); baru.release(); sum.release();image.release(); image2.release();

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
//  waitKey(0);
  return a.exec();
      }
//












