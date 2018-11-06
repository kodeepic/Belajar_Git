#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QArrayData>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static int iki;
    static Mat masuk[10000];
    static int aku;
//    static QTimer timerku;
//    const int panjang;

    static int lebar;
    static int data1[1000];



public slots:
//   void pengolahangambar();

private slots:
   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

   void on_loadvideo_clicked();

   void on_takeframe_clicked();

   void showVideo();

//   void on_lihat_clicked();




   void on_dataprocess_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
