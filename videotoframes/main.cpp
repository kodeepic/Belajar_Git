#include "mainwindow.h"
#include <QApplication>

#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp> //header yang direkomendasikan saat menggunakan C++ API
#include <opencv2/highgui/highgui.hpp> //(tulisan header versi lama) highui untuk mengakses imgcodec,videoio, dll
#include <iostream>   //header file untuk input ouput C++ programming language

using namespace std; //operasi input output
using namespace cv; //Namespace tempat semua fungsi C++ OpenCV berada

int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   VideoCapture cap("C:/Users/Ariku/Downloads/terbang.mpg");
   //cap adalah objek kelas dari videocapture yang akan meng-capture video terbang.mpg
   if(!cap.isOpened()) //akan bernilai benar jika capturing telah terinisialisasi
   {
       cout<<"cannot open this file"<<endl ;
       return -1;
   }
   double fps = cap.get(CV_CAP_PROP_FPS); //mendapatkan fps dari video
   namedWindow("gambar",CV_WINDOW_AUTOSIZE); //membuat window bernama gambar
   cout << "Frames per second using video.get(CV_CAP_PROP_FPS) : " << fps << endl;

  while(true)
  {
       Mat frame; //Mat object adalah wadah dasar gambar
       if(!cap.read(frame)) //jika tidak sukses loop berhenti
           // read digunakan untuk mengkode dan membaca dari frame ke frame berikutnya
       {
           cout<<"cannot read the file"<<endl;
       }
       imshow("gambar",frame); //play gambar
       imwrite("D:/Capture gambar/gambar.png",frame); //menyimpan gambar

       if(waitKey(30)==27) //keluar jika tekan ESC (kode ascii esc adalah 27)
       {
           break;
       }

   }

   return 0;

    return a.exec();
}
