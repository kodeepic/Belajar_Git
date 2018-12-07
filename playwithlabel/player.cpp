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
#include <QImage>
using namespace std;

// Variabel Array untuk menampung data penerbangan


Player::Player(QObject *parent) : QThread(parent)
{
    stop =true;
}

bool Player :: loadVideo(String filename){
    infovideo = QString::fromStdString(filename);
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
            keadaan =keadaan+1;
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
    lk = frameNumber;
}

bool Player :: loadData(String d_filename){
    QString qstr = QString::fromStdString(d_filename);
// Baca data file CSV dan simpan dalam array (2 dimensi)
    QFile inputfile (qstr);
    inputfile.open(QIODevice::ReadOnly);
     QTextStream stream (&inputfile);
    if (!inputfile.isOpen())
        return true;
    int baris =1;int wow=2;int ATT;int BAT;int GPS;
                  JML =0;JML1 =0;

                  while (baris <wow){
                    QString line = stream.readLine();
                    if (!line.isNull()){
                        QByteArray hhh = line.toLocal8Bit();
                        const char *line1= hhh.data();
                        sscanf(line1,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",&lo[baris][1],&lo[baris][2],&lo[baris][3],&lo[baris][4],&lo[baris][5],&lo[baris][6],&lo[baris][7],&lo[baris][8],&lo[baris][9],&lo[baris][10]);
                        qDebug() << "baris" << baris <<"hayo ke:" <<line << "jadinya: " <<lo[baris][1]<< " " << lo[baris][10];
                        if(lo[baris][1]==0){ATT=0;} else {ATT=1;}
                        if(lo[baris][7]==0){GPS=0;} else {GPS=1;}
                        if(lo[baris][5]==0){BAT=0;} else {BAT=1;}
                        int KDS = ATT + GPS +BAT;
                               if(KDS==3){JML=JML+3;JML1=JML1+2;}
                                   else if (KDS==2){JML=JML+2;JML1=JML1+2;}
                                       else {JML=JML+1;JML1=JML1+1;}
                                  qDebug() << "" << JML << " " << JML1;
                                  baris++;wow++;}
                                   else {wow =0;}
                    }
                  // Proses pengurutan data
                          //Pengurutan
                          //Tahap1
                          int x1=1;int x2=1;
                         int kl;
                          int kw;
                  for (int i=1; i<=JML1; i++)
                  {
                      if(!lo[x2][5]==0){
                                         kl = lo[x1][1];//Data ATT
                                         kw = lo[x2][5];//Data BAT
                                         if (kl>kw){
                                             for (int j=2;j<9;j++){
                                                 if (j<5){ko[i][j]=0;}
                                                 else if (j==5){ko[i][j]=lo[x2][6];}
                                                 else {ko[i][j]=0;}
                                             }
                                             ko[i][1]= lo [x2][5];
                                             ko[i][9]=0;ko[i][10]=2;
                                             x2=x2+1;
                                         }
                                         else if (kl<kw){
                                             for (int j=2; j<9 ; j++){
                                                 if (j<5) {ko[i][j]=lo[x1][j];}
                                                 else {ko[i][j]=0;}
                                             }
                                             ko[i][1]=lo[x1][1];
                                             ko[i][9]=1;ko[i][10]=0;
                                             x1=x1+1;}

                                         else {
                                             for (int j=1;j<9;j++){
                                                     if (j<5){ko[i][j]=lo[x1][j];}
                                                     else if (j==5){ko[i][5]=lo[x2][6];}
                                                     else {ko[i][j]=0;}
                                                 }
                                                 x1=x1+1;x2=x2+1;
                                                 ko[i][9]=1;ko[i][10]=2;
                                             }

                                         }
                                     else {
                                         for(int n=1;n<9;n++){
                                                 if (n<5){ko[i][n]=lo[x1][n];}
                                                 else {ko[i][n]=0;}
                                         }
                                         ko[i][9]=1;ko[i][10]=0;
                                         x1 =x1+1;
                                     }


                    }
                  // Tahap2
                             int x10=1;int x20=1;
                             for (int i=1; i<=JML; i++)
                             {
                                 if(!lo[x20][7]==0){
                                                    int kl =ko[x10][1];//Data Tahap1
                                                    int kw =lo[x20][7];//Data GPS
                                                    if (kl<kw){
                                                        for (int j=1;j<9;j++){
                                                            if (j<6) {
                                                                ko1[i][j]=ko[x10][j];
                                                            }
                                                            else {
                                                              ko1[i][j]=0;
                                                            }
                                                        }
                                                        ko1[i][9]=ko[x10][9];ko1[i][10]=ko[x10][10];ko1[i][11]=0;
                                                        x10=x10+1;
                                                    }
                                                    else if (kl>kw){
                                                    for (int ik=1;ik<9;ik++){
                                                        if (ik<6){
                                                            ko1[i][ik]=0;
                                                        }
                                                        else {

                                                            ko1[i][ik]=lo[x20][ik+2];
                                                        }
                                                    }
                                                        ko1[i][1]=lo[x20][7];
                                                        ko1[i][9]=0;ko1[i][10]=0;ko1[i][11]=3;
                                                        x20=x20+1;
                                                    }
                                                    else {
                                                        for (int j=1;j<9;j++){
                                                            if (j<6){
                                                                ko1[i][j]=ko[x10][j];
                                                              }
                                                            else {
                                                                ko1[i][j]=lo[x20][j+2];
                                                            }
                                                           }
                                                            x10=x10+1;x20=x20+1;
                                                            ko1[i][9]=ko[i][9];ko1[i][10]=ko[i][10];ko1[i][11]=3;
                                                        }
                                                    }
                                                else {
                                                    for(int n=1;n<9;n++){
                                                        if(n<6){
                                                            ko1[i][n]=ko[x10][n];
                                                        }
                                                        else {
                                                            ko1[i][n]=0;
                                                        }
                                                    }
                                                    ko1[i][9]=ko[x10][9];ko1[i][10]=ko[x10][10];ko1[i][11]=0;
                                                    x10 =x10+1;
                                                }
                             }
                             //for (int kl = 1; kl<=JML ; kl++){

                                // qDebug()<< " "<< ko1[kl][1] << " "<< ko1[kl][5] << " " << ko1[kl][10];

                                //}
                             // Linearisasi
                                    int x100= 1; int xk=1    ;int x300  ;
                                    int jml1= 1; int jml2=1  ;int jml3=1;
                                    float skala; float skala2;int skala3;
                                    float kr;  float kr2; float kr3;
                                    float aman; float aman2; float aman3;
                                    // Data waktu
                                            for (int k= 1; k<= JML;k++){
                                                ko2[k][1]= ko1[k][1];
                                            }
                                            // Data ATT
                                                    for (int oj=2; oj<5 ;oj++){
                                                      for (int i=1;i<=JML;i++){
                                                          int LokRoll = ko1[i][9];
                                                                                float Roll    = ko1[i][oj];
                                                                                if (LokRoll==0){
                                                                                jml1     = jml1 + 1 ; // jumlah data bernilai 0 pada data waktu
                                                                                x100     = i   + 1  ;
                                                                                    if(ko1[x100][9]==0){
                                                                                        jml1=jml1;

                                                                                         }
                                                                                    else {
                                                                                        kr = ko1[x100][1]- ko1[i-jml1+1][1];
                                                                                        skala= (ko1[x100][oj]-ko1[i-jml1+1][oj]);
                                                                                        for(int a= 0; a<(jml1-1);a++){
                                                                                            aman= ko1[i-a][1]-ko1[i-jml1+1][1];
                                                                                              ko2[i-a][oj]=ko1[i-jml1+1][oj]+(skala*aman/kr);
                                                                                        }
                                                                                        x100=1;
                                                                                        jml1=1;
                                                                                    }
                                                                            }
                                                                                else{
                                                                                     ko2[i][oj]= Roll;
                                                                                     x100=1;
                                                                                     jml1=1;
                                                                                }

                                                                         }// oj ==5

                                                                     }
                                                    // Data BAT
                                                         int f=0;
                                                         int c;
                                                              if (ko1[1][10]==0)
                                                              {while (ko1[1+f][5]==0){
                                                                  ko2[1+f][5]=ko1[1+f][5];
                                                                  ko2[1+f][1]=ko1[1+f][1];
                                                                  f++;
                                                                  }
                                                                }
                                                              for (int i=1+f; i<=JML;i++){
                                                                                 int LoKBAT = ko1[i][10];
                                                                                 float BAT    = ko1[i][5];
                                                                                 if (LoKBAT==0){
                                                                                     jml2   = jml2 + 1 ; // jumlah data bernilai 0 pada data waktu
                                                                                     xk     = i   + 1;
                                                                                     if(ko1[xk][10]==0){
                                                                                         jml2=jml2;
                                                                                         ko2[i][5]=0;
                                                                                         }
                                                                                     else if (ko1[xk][10]==2)  {
                                                                                         kr2 = ko1[xk][1]- ko1[i-jml2+1][1];
                                                                                         skala2= (ko1[xk][5]-ko1[i-jml2+1][5]);
                                                                                         for(int a= 0; a<(jml2-1);a++){
                                                                                             aman2= ko1[i-a][1]-ko1[i-jml2+1][1];
                                                                                               ko2[i-a][5]=ko1[i-jml2+1][5]+(skala2*aman2/kr2);
                                                                                         }
                                                                                         xk=1;
                                                                                         jml2=1;
                                                                                     }
                                                                                 }
                                                                                     else{
                                                                                          ko2[i][5]= BAT;
                                                                                          xk=1;
                                                                                          jml2=1;
                                                                 //                         qDebug() << "nilai: " <<ko2[i][5]<< "data ke "<< i;
                                                                                     }
                                                                                  }
                                                              // Data GPS
                                                                                 for (int oj =6; oj<9;oj++){
                                                                                      int fp=0;
                                                                                      if (ko1[1][11]==0)
                                                                                      {while (ko1[1+fp][oj]==0){
                                                                                          ko2[1+fp][oj]=ko1[1+fp][oj];
                                                                                          fp++;
                                                                                          }
                                                                                        }
                                                                                            for (int i=1+fp; i<=JML;i++){
                                                                                            int LoKGPS = ko1[i][11];
                                                                                            float GPS  = ko1[i][oj];
                                                                                            if (LoKGPS==0){
                                                                                                jml3     = jml3 + 1 ; // jumlah data bernilai 0 pada data waktu
                                                                                                x300     = i   + 1;
                                                                                                if(ko1[x300][11]==0){
                                                                                                    jml3=jml3;
                                                                                                    ko2[i][oj]=0;
                                                                                                    }
                                                                                                else if (ko1[x300][11]==3)  {
                                                                                                    kr3    =  ko1[x300][1] -ko1[i-jml3+1][1];
                                                                                                    skala3 = (ko1[x300][oj]-ko1[i-jml3+1][oj]);
                                                                                                    for(int a= 0; a<(jml3-1);a++){
                                                                                                        aman3= ko1[i-a][1]-ko1[i-jml3+1][1];
                                                                                                          ko2[i-a][oj]=ko1[i-jml3+1][oj]+(skala3*aman3/kr3);
                                                                 //                                         qDebug() << " data ke:" << i-a << " " << ko2[i-a][oj];
                                                                                                    }
                                                                                                    x300=1;
                                                                                                    jml3=1;
                                                                                                }
                                                                                            }
                                                                                                else{
                                                                                                     ko2[i][oj]= GPS;
                                                                                                     x300=1;
                                                                                                     jml3=1;

                                                                                                }
                                                                 //                                                      qDebug() << "nilai: " <<ko2[i][oj]<< "data ke "<< i;
                                                                                             }

                                                                                         }
                                                                 //                for (int j=6;j<9;j++){
                                                                 //                         for (int i = 1; i<=JML; i++){
                                                                 //                                  qDebug() <<  " dari :" << ko2[i][j] << " " << i << " " << j;
                                                                 //                         }
                                                                 //                }
                                                                                 // Tahap 1 penyempurnaan nilai data waktu
                                                                                            float awal = ko1[1][1]/1000000;
                                                                                            int pembagi = 1000000;
                                                                                            for (int i=1; i <= JML ;i++){
                                                                                                float al=ko1[i][1]/pembagi;
                                                                                                 lo1[i][1]= al-awal;
                                                                                                     qDebug() << " " << lo1[i][1]<< " awal" << awal << " al " << al;
                                                                                            }
                                                                                       return true;



    }
bool Player:: SetPoint (String KDS){
    QString op1 = QString::fromStdString(KDS);
    int mop1= op1.toInt();
               //      Tahap pengurutan data waktu berdasarkan nilai frame rate video
                          float ak=1/frameRate;
                          float durasi = 0.04;

                          float total; float jarak; float nilai; float kali;
//                       qDebug() << " " << durasi << " " << frameRate;
                       //Data sudut Roll
                          int data = (mop1-1)*25+1;
                          int u1=data;int u2 =data;
                       for (int ik=data; ik<=(data-1+totalframe);ik++){
                           float a= lo1[1][1]+(durasi*(u2-1));
                           float b= lo1[u1][1];
                           int i=(ik-data)+1;
                                  if (b==a){
                                      ko3[i][1]=a;
                                      for (int j=2; j<9;j++){
                                       ko3[i][j]=ko2[u1][j];
                                      }
                                      u1=u1+1;
                                      u2=u2+1;
                                  }

                                  else if (b>a){
                                      ko3[i][1]=a;
                                      total = lo1[u1][1]-lo1[u1-1][1];
                                      jarak = a - lo1[u1-1][1];
                                      for (int j=2; j<9;j++){
                                      nilai = ko2[u1][j]-ko2[u1-1][j];
                                          kali = (jarak/total)*nilai;
                                          ko3[i][j]= kali + ko2[u1-1][j];}
                                       u2=u2+1;
                                  }
                                  else {
                                      u1=u1+1;
                                      int banding = lo1[u1][1];
                                          while (banding<a){
                                              u1=u1+1;
                                              banding = lo1[u1][1];
                                              ko3[i][1]=a;
                                          }
                                          if (banding==a){
                                              ko3[i][1]=a;
                                              for (int j=2;j<9;j++){
                                              ko3[i][j]=ko2[u1][j];}
                                              u1=u1+1;
                                              u2=u2+1;
                                          }
                                          else{
                                              ko3[i][1]=a;
                                              total = lo1[u1][1]-lo1[u1-1][1];
                                              jarak = a - lo1[u1-1][1];
                                              for (int j=2;j<9;j++){
                                              nilai = ko2[u1][j]-ko2[u1-1][j];
                                                  kali = (jarak/total)*nilai;
                                                  ko3[i][j]= kali + ko2[u1-1][j];}
                                              u2=u2+1;
                                          }
                                      }

                                  qDebug() << " " << ko3[i][1] << "a:" << a << "b:" << b << " hasil:  "<< ko3[i][2] <<   "hasil2: " << ko3[i][5]<< "hasil3: " << ko3[i][6] ;
                              }

return true;

//    for (int i =1; i<=totalframe;i++ ){
//        qDebug() << "dari: " << ko2[i][2] << "  "<< ko3[i][2] <<   " " << i;
//    }
}
   /*
bool Player :: MengurutkanData(){
    int jbaris=1;
    for(int bris=1;bris<=(totalframe*2);bris++){
        if(totalframe){


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
    if (!lokasivideo.empty()){
            keadaan1 =2;
            stop =false;
            kunci =1;
        }else {keadaan1=0;}
    qDebug() << "k: " <<keadaan << "posisi data" << kunci;
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
        DataKecepatan= "0";
        kec =0;
    }
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
        DataAltitude= "0";
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
        DataRoll= "0";
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
        DataLongitude= "0";
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
        DataPitch= "0";
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
        DataLatitude= "0";
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
        DataYaw= "0";
        yaw =0;
    }
    return true;
    /*
    yaw=QString :: fromStdString(datayaw);
    DataYaw = yaw.toLocal8Bit().constData();
    return true;
    */
}
bool Player :: loadBaterai(String databaterai){
    QString ok8 =QString::fromStdString(databaterai);
    int bate =ok8.toInt();;
    if(bate>0){
        Baterai=1;
    }else{
        Baterai=0;
    }
    return true;
}
void Player :: run()
{
    int theme = keadaan +keadaan1;
    kunci=lk;
    int frame_width = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    if (theme==2){
    video.open(lokasivideo,CV_FOURCC('M','J','P','G'),frameRate,Size(frame_width,frame_height),true);}
    if (!video.isOpened()) {
            qDebug() << "Could not open the output video file for write\n"<<endl;
        }
    int delay =(1000/frameRate);
    while (stop==false) {
        if(!capture.read(frame))
        {
            stop=true;
            break;
        }
        if(Baterai>0){
            float ok = ko3[kunci][5];
                       float alam=(ok-12)/2;
                       alam= alam *100;
                       if (alam >90)     {image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");}
                       else if (alam >70){image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");}
                       else if (alam >50){image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");}
                       else if (alam >30){image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");}
                       else if (alam >10){image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");}
                       else if (alam >5) {image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");}
                       else {image2 = imread("D:\\DataRachmaProgram\\baru2\\playwithlabel\\B0.png");}



            //image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");
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
    }

          image4 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\unnamed (1).png");
          resize(image4, enlarged, cv::Size(frame.cols-(0.90*frame.cols), frame.rows-(0.15*frame.rows)), cv::INTER_NEAREST);
          //grafik skala sebelah kanan frame//
          Rect ROI1 (frame.cols-enlarged.cols-20,frame.rows-enlarged.rows-50,enlarged.cols,enlarged.rows);
          Mat baru1= frame(ROI1);
          Mat mask(enlarged);
          enlarged.copyTo(baru1,mask);

              QString KEC;QString angkc;QString angkc1;QString angkc2;QString angkc3;QString angkc4;QString angkc5;QString angkc6;QString angkc7;QString angkc8;QString angkc9;
              QString angkc10;QString angkc12;QString angkc13;QString angkc14;QString angkc15;QString angkc16;QString angkc17;QString angkc18;QString angkc19;QString angkc20;
              QString fast;
              if (kec > 0){
                           float om1 = ko3[kunci][9];
                           QString angku = QString::number(om1);
                           fast = DataKecepatan + angku;
                           KEC =angku;
                          float onc1= om1; float onc2 = onc1+1; float onc3= onc1+2; float onc4 = onc1+3; float onc5 = onc1+4; float onc6 = onc1+5; float onc7 = onc1+6; float onc8 = onc1+7; float onc9 = onc1+8;float onc10 = onc1+9;
                           float onc11= om1-1;float onc20= om1-2;float onc30= om1-3;float onc40= om1-4;float onc50= om1-5;float onc60= om1-6;float onc70= om1-7;float onc80= om1-8;float onc90= om1-9;
                           angkc = QString::number(onc1);angkc1 = QString::number(onc2);angkc2 = QString::number(onc3);angkc3 = QString::number(onc4);angkc4 = QString::number(onc5);angkc5 = QString::number(onc6);angkc6 = QString::number(onc7);
                           angkc7 = QString::number(onc7); angkc8 = QString::number(onc8); angkc9 = QString::number(onc9); angkc10 = QString::number(onc10);angkc12 = QString::number(onc11);angkc13 = QString::number(onc20);angkc14 = QString::number(onc30);
                           angkc15 = QString::number(onc40);angkc16 = QString::number(onc50);angkc17 = QString::number(onc60);angkc18 = QString::number(onc70);angkc19 = QString::number(onc80);angkc20 = QString::number(onc90);

                       }else {
                  fast = DataKecepatan;
                  KEC="";
              }
              string kecepatan1 = fast.toLocal8Bit().constData();
              string kcptn   = KEC.toLocal8Bit().constData()    ;
              string kcptn1  = angkc1.toLocal8Bit().constData() ;string kcptn2  = angkc2.toLocal8Bit().constData() ;string kcptn3  = angkc3.toLocal8Bit().constData() ;string kcptn4  = angkc4.toLocal8Bit().constData() ;string kcptn5  = angkc5.toLocal8Bit().constData();
              string kcptn6  = angkc6.toLocal8Bit().constData() ;string kcptn7  = angkc7.toLocal8Bit().constData() ;string kcptn8  = angkc8.toLocal8Bit().constData() ;string kcptn9  = angkc9.toLocal8Bit().constData() ;string kcptn10 = angkc9.toLocal8Bit().constData();
              string kcptn12 = angkc12.toLocal8Bit().constData();string kcptn13 = angkc13.toLocal8Bit().constData();string kcptn14 = angkc14.toLocal8Bit().constData();string kcptn15 = angkc15.toLocal8Bit().constData();string kcptn16 = angkc16.toLocal8Bit().constData();
              string kcptn17 = angkc17.toLocal8Bit().constData();string kcptn18 = angkc18.toLocal8Bit().constData();string kcptn19 = angkc19.toLocal8Bit().constData();string kcptn20 = angkc20.toLocal8Bit().constData();
              putText(frame,kcptn10,Point((frame.cols* 0.82)-16, ((frame.rows * 0.89)+5)-460),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn9,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-441),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn8,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-415),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn7,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-390),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn6,Point((frame.cols* 0.82)+5,((frame.rows * 0.89)+5)-365),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn5,Point((frame.cols* 0.82)-16,  ((frame.rows * 0.89)+5)-342),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn4,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-317),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn3,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-292),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn2,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-267),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn1,Point((frame.cols* 0.82)+5,((frame.rows * 0.89)+5)-245),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn,Point((frame.cols* 0.82)-17, ((frame.rows * 0.89)+5)-220) ,FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn12,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-195),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn13,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-170),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn14,Point((frame.cols* 0.82)+5,((frame.rows * 0.89)+5)-150) ,FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn15,Point((frame.cols* 0.82)+5,((frame.rows * 0.89)+5)-125),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn16,Point((frame.cols* 0.82)-16,((frame.rows * 0.89)+5)-100),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn17,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-75),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn18,Point((frame.cols* 0.82)+5, ((frame.rows * 0.89)+5)-50),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn19,Point((frame.cols* 0.82)+5,((frame.rows * 0.89)+5)-25),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     putText(frame,kcptn20,Point((frame.cols* 0.82)+5, (frame.rows * 0.89)+5),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                     Rect p=Rect(((frame.cols* 0.82)-25),((frame.rows * 0.89)+5-233),70,20);
                            rectangle(frame,p,Scalar(255,255,255),2,8,0);

          //video.write(frame);
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
              QString ALT; QString ALTK;QString angkk;QString angkk1;QString angkk2;QString angkk3;QString angkk4;QString angkk5;QString angkk6;QString angkk7;QString angkk8;QString angkk9;
              QString angkk10;QString angkk12;QString angkk13;QString angkk14;QString angkk15;QString angkk16;QString angkk17;QString angkk18;QString angkk19;QString angkk20;
              if (alt > 0){
                           float om2 = ko3[kunci][8];
                           float on1= om2; float on2 = on1+1; float on3= on1+2; float on4 = on1+3; float on5 = on1+4; float on6 = on1+5; float on7 = on1+6; float on8 = on1+7; float on9 = on1+8;float on10 = on1+9;
                           float on11= om2-1;float on20= om2-2;float on30= om2-3;float on40= om2-4;float on50= om2-5;float on60= om2-6;float on70= om2-7;float on80= om2-8;float on90= om2-9;
                           angkk = QString::number(on1);angkk1 = QString::number(on2);angkk2 = QString::number(on3);angkk3 = QString::number(on4);angkk4 = QString::number(on5);angkk5 = QString::number(on6);angkk6 = QString::number(on7);
                           angkk7 = QString::number(on7); angkk8 = QString::number(on8); angkk9 = QString::number(on9); angkk10 = QString::number(on10);angkk12 = QString::number(on11);angkk13 = QString::number(on20);angkk14 = QString::number(on30);
                           angkk15 = QString::number(on40);angkk16 = QString::number(on50);angkk17 = QString::number(on60);angkk18 = QString::number(on70);angkk19 = QString::number(on80);angkk20 = QString::number(on90);
                            ALT = DataAltitude + angkk;
                            ALTK = angkk;
                       }
                       else {
                           ALT = DataAltitude;
                           ALTK= "";
                       }
              string Altitude1 = ALT.toLocal8Bit().constData();
                       string ketinggian = ALTK.toLocal8Bit().constData();
                       string ketinggian1 = angkk1.toLocal8Bit().constData();string ketinggian2 = angkk2.toLocal8Bit().constData();string ketinggian3 = angkk3.toLocal8Bit().constData();string ketinggian4 = angkk4.toLocal8Bit().constData();string ketinggian5 = angkk5.toLocal8Bit().constData();
                       string ketinggian6 = angkk6.toLocal8Bit().constData();string ketinggian7 = angkk7.toLocal8Bit().constData();string ketinggian8 = angkk8.toLocal8Bit().constData();string ketinggian9 = angkk9.toLocal8Bit().constData();string ketinggian10 = angkk10.toLocal8Bit().constData();
                       string ketinggian12 = angkk12.toLocal8Bit().constData();string ketinggian13 = angkk13.toLocal8Bit().constData();string ketinggian14 = angkk14.toLocal8Bit().constData();string ketinggian15 = angkk15.toLocal8Bit().constData();string ketinggian16 = angkk16.toLocal8Bit().constData();
                       string ketinggian17 = angkk17.toLocal8Bit().constData();string ketinggian18 = angkk18.toLocal8Bit().constData();string ketinggian19 = angkk19.toLocal8Bit().constData();string ketinggian20 = angkk20.toLocal8Bit().constData();
                       flip(enlarged,flip1,+1);
                       Rect ROI2(frame.cols-flip1.cols-640,frame.rows-flip1.rows-50,flip1.cols,flip1.rows);
                              Mat baru2 = frame(ROI2);
                              Mat mask1(flip1);
                              flip1.copyTo(baru2,mask1);
                                     putText(frame,ketinggian10,Point((frame.cols* 0.08)+16, ((frame.rows * 0.89)+5)-460),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian9,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-441),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian8,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-415),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian7,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-390),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian6,Point((frame.cols* 0.08),((frame.rows * 0.89)+5)-365),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian5,Point((frame.cols* 0.08)+16,  ((frame.rows * 0.89)+5)-342),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian4,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-317),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian3,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-292),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian2,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-267),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian1,Point(frame.cols* 0.08,((frame.rows * 0.89)+5)-245),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian,Point((frame.cols* 0.08)+17, ((frame.rows * 0.89)+5)-220) ,FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian12,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-195),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian13,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-170),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian14,Point(frame.cols* 0.08,((frame.rows * 0.89)+5)-150) ,FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian15,Point(frame.cols* 0.08,((frame.rows * 0.89)+5)-125),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian16,Point((frame.cols* 0.08)+16,((frame.rows * 0.89)+5)-100),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian17,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-75),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian18,Point(frame.cols* 0.08, ((frame.rows * 0.89)+5)-50),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian19,Point(frame.cols* 0.08,((frame.rows * 0.89)+5)-25),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                     putText(frame,ketinggian20,Point((frame.cols* 0.08), (frame.rows * 0.89)+5),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255, 255, 255),1.6,LINE_AA);
                                      Rect r=Rect(((frame.cols* 0.08)+5),((frame.rows * 0.89)+5-233),70,20);
                                      rectangle(frame,r,Scalar(255,255,255),2,8,0);


                                      /*
        //grafik skala sebelah kiri frame//
        flip(enlarged,flip1,+1);
        Rect ROI2(frame.cols-flip1.cols-640,frame.rows-flip1.rows-50,flip1.cols,flip1.rows);
        Mat baru2 = frame(ROI2);
        Mat mask1(flip1);
        flip1.copyTo(baru2,mask1);
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
         //Rect s=Rect(22,164,85,20);
*/
         //rectangle(frame,s,Scalar(255,255,255),2,8,0);
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
        float omo;
        if (wak > 0){
            omo = ko[kunci][1];
            QString angka = QString::number(omo);

             Time = DataWaktu + angka +"s";
        }
        else {
            Time = DataWaktu;
        }
        string waktu1 = Time.toLocal8Bit().constData();
        QString Rol;
        if (rol > 0){
           float om3 = ko[kunci][4];
            QString angk = QString::number(om3);
             Rol = DataRoll + angk;
             /*
             if(om3>=235.56 && om3<=238.03){
              rectangle(frame,r,Scalar(255,255,255),2,8,0);
             }if(om3>=232.6 && om3<=235.55){
                 Rect p=Rect(22,90,70,20);
                 rectangle(frame,p,Scalar(255,255,255),2,8,0);
             }if(om3>=238.03 && om3<=242.6){
                Rect p=Rect(22,118,70,20);
                rectangle(frame,p,Scalar(255,255,255),2,8,0);
             }if(om3>=242.6 && om3<=245.6){
                 Rect p=Rect(22,140,70,20);
                 rectangle(frame,p,Scalar(255,255,255),2,8,0);
             }if(om3>245.6 && om3<=251.6){
                 Rect p=Rect(22,164,85,20);
                 rectangle(frame,p,Scalar(255,255,255),2,8,0);
             }
             */
        }
        else {
            Rol = DataRoll;
        }
        string Roll1 = Rol.toLocal8Bit().constData();
        QString Long;
        if (log > 0){
            float om4 = ko[kunci][5];
            QString angkl = QString::number(om4);
             Long = DataLongitude + angkl;
        }
        else {
             Long = DataLongitude;
        }

        string Longitude1 = Long.toLocal8Bit().constData();
        QString Pitc;
        if (pit > 0){
            float om5 = ko[kunci][6];
            QString ang = QString::number(om5);
            Pitc = DataPitch + ang;
        }
        else {
            Pitc = DataPitch;
        }
        string Pitch1 = Pitc.toLocal8Bit().constData();
        QString Lat;
        if (lat > 0){
            float om6 = ko[kunci][7];
            QString anka = QString::number(om6);
            Lat = DataLatitude + anka;
        }
        else {
            Lat = DataLatitude;
        }
        string Latitude1 = Lat.toLocal8Bit().constData();
        QString Yaw;
        if (yaw > 0){
            float om7 = ko[kunci][8];
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
    //       QDate cd = QDate::currentDate();
    //       QTime ct = QTime::currentTime();
    //         tanggal= cd.toString();
    //          jam   = ct.toString();
    //          string tanggalbaru = tanggal.toLocal8Bit().constData();
    //          string jambaru = jam.toLocal8Bit().constData();
    //   putText(frame,tanggalbaru+" | "+jambaru,Point2f(frame.cols-300,frame.rows*0.05),FONT_HERSHEY_SIMPLEX,0.6,Scalar(0,0,0),1.6,LINE_AA);
    QFileInfo fileinfo(infovideo);
    QDateTime last_created = fileinfo.lastRead();
    QDateTime last_modified = fileinfo.lastModified();
    tanggal_tercipta= last_created.toString();
    tanggal_modifikasi = last_modified.toString();
    string tercipta = tanggal_tercipta.toLocal8Bit().constData();
    string modifikasi = tanggal_modifikasi.toLocal8Bit().constData();
    putText(frame,modifikasi,Point2f(frame.cols-300,frame.rows*0.05),FONT_HERSHEY_SIMPLEX,0.6,Scalar(0,0,0),1.6,LINE_AA);
    /*
    //kotak sebelah kiri
    Mat roi4 =frame(cv::Rect(50,150,50,275));
    Mat color4 (roi4.size(),CV_8UC3,cv::Scalar(0,0,0));
    double alpha4 =0.2;
    addWeighted(color4,alpha4,roi4,1.0 - alpha4,0.0,roi4);
    //grafik kiri
    for(int i=156;i<=425;i=i+46){
    line(frame,Point( 94,i), Point(99, i),Scalar(255,255,255),1.6,LINE_AA);
    line(frame,Point( 94,i+23), Point(99, i+23),Scalar(255,255,255),1.6,LINE_AA);
    //conton data kecepatan
    putText(frame,"100",Point(70,i+3),FONT_HERSHEY_SIMPLEX,0.3,Scalar(255,255,255),1.6,LINE_AA);

    }
    //kotak penanda kiri
    line(frame,Point(50,284),Point(85,284),Scalar(255,255,255),1.5,LINE_AA); //bagian garis atas penanda
    line(frame,Point(50,284),Point(50,306),Scalar(255,255,255),1.5,LINE_AA); //bagian garis samping penanda
    line(frame,Point(50,306),Point(85,306),Scalar(255,255,255),1.5,LINE_AA); //bagian garis bawah penanda
    line(frame,Point(85,284),Point(95,294),Scalar(255,255,255),1.5,LINE_AA); //bagian garis miring atas penanda
    line(frame,Point(85,306),Point(95,294),Scalar(255,255,255),1.5,LINE_AA); //bagian garis miring bawah penanda
*/
    /*
        //menambahkan tanggal dan waktu
        QDate cd = QDate::currentDate();
        QTime ct = QTime::currentTime();
          tanggal= cd.toString();
           jam   = ct.toString();
           string tanggalbaru = tanggal.toLocal8Bit().constData();
           string jambaru = jam.toLocal8Bit().constData();
    putText(frame,tanggalbaru+" | "+jambaru,Point2f(frame.cols-300,frame.rows*0.05),FONT_HERSHEY_SIMPLEX,0.6,Scalar(0,0,0),1.6,LINE_AA);
    */
   // imwrite("D:\\Capture gambar\\gambar.png", frame); //write the image to a file as JPEG

      //konversi BGR ke RGB
    //konversi BGR ke RGB
   if (theme==2){
        video.write(frame);
        emit urutan(kunci);
   }
      else{
//          kunci =lk;
       if (keadaan==1){
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
       }
       else {
                   video.write(frame);
                   emit urutan(kunci);
              }
    }

   kunci ++;
    }
     keadaan=0;
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

