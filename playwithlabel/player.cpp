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
using namespace std;

// Variabel Array untuk menampung data penerbangan


Player::Player(QObject *parent) : QThread(parent)
{
    stop =true;

}

bool Player :: loadVideo(String filename){
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
     kunci =1;
    int frame_width = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    video.open(lokasivideo,CV_FOURCC('M','J','P','G'),frameRate,Size(frame_width,frame_height),true);
    if (!video.isOpened()) {
            qDebug() << "Could not open the output video file for write\n"<<endl;
        }
    int delay =(1000/frameRate);
    while (!stop) {
        if(!capture.read(frame))
        {
            stop=true;
            break;
        }
        if(Baterai>0){
            image2 = imread("C:\\Users\\Ariku\\Documents\\MATLAB\\B1001%.png");
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
          video.write(frame);
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
        int omo;
        if (wak > 0){
            omo = ko[kunci][1];
            QString angka = QString::number(omo);

             Time = DataWaktu + angka +"us";
        }
        else {
            Time = DataWaktu;
        }
        string waktu1 = Time.toLocal8Bit().constData();
        QString fast;
        if (kec > 0){
            float om1 = ko[kunci][2];
            QString angku = QString::number(om1);
            fast = DataKecepatan + angku;
        }
        else {
            fast = DataKecepatan;
        }
        string kecepatan1 = fast.toLocal8Bit().constData();
        QString ALT;
        if (alt > 0){
            float om2 = ko[kunci][3];
            QString angkk = QString::number(om2);
             ALT = DataAltitude + angkk;
        }
        else {
            ALT = DataAltitude;
        }
        string Altitude1 = ALT.toLocal8Bit().constData();
        QString Rol;
        if (rol > 0){
            int om3 = ko[kunci][4];
            QString angk = QString::number(om3);
             Rol = DataRoll + angk;
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
        }
        else {
            Rol = DataRoll;
        }
        string Roll1 = Rol.toLocal8Bit().constData();
        QString Long;
        if (log > 0){
            int om4 = ko[kunci][5];
            QString angkl = QString::number(om4);
             Long = DataLongitude + angkl;
        }
        else {
             Long = DataLongitude;
        }

        string Longitude1 = Long.toLocal8Bit().constData();
        QString Pitc;
        if (pit > 0){
            int om5 = ko[kunci][6];
            QString ang = QString::number(om5);
            Pitc = DataPitch + ang;
        }
        else {
            Pitc = DataPitch;
        }
        string Pitch1 = Pitc.toLocal8Bit().constData();
        QString Lat;
        if (lat > 0){
            int om6 = ko[kunci][7];
            QString anka = QString::number(om6);
            Lat = DataLatitude + anka;
        }
        else {
            Lat = DataLatitude;
        }
        string Latitude1 = Lat.toLocal8Bit().constData();
        QString Yaw;
        if (yaw > 0){
            int om7 = ko[kunci][8];
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
        QDate cd = QDate::currentDate();
        QTime ct = QTime::currentTime();
          tanggal= cd.toString();
           jam   = ct.toString();
           string tanggalbaru = tanggal.toLocal8Bit().constData();
           string jambaru = jam.toLocal8Bit().constData();
    putText(frame,tanggalbaru+" | "+jambaru,Point2f(frame.cols-300,frame.rows*0.05),FONT_HERSHEY_SIMPLEX,0.6,Scalar(0,0,0),1.6,LINE_AA);
    imwrite("D:\\Capture gambar\\gambar.png", frame); //write the image to a file as JPEG

      //konversi BGR ke RGB
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
   kunci ++;
    }
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

