#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <player.h>
#include <QString>
#include <QFile>
//#include <QProgressBar>
//#include <QPushButton>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent =0);
    ~MainWindow();
private slots:
    void updatePlayerUI(QImage img);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    //void setProgressBarValue();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Player* myPlayer;
   // QProgressBar *bar;
 //   QPushButton *button;

};
/*
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

namespace coba {
inline QImage cvMatToQImage (const cv ::Mat &inMat)
{
    switch (inMat.type()) {
    case CV_8UC4:
    {
        QImage gambar(inMat.data,inMat.cols,inMat.rows,
                      static_cast<int>(inMat.step),QImage ::Format_ARGB32);
        return gambar;
    }
    case CV_8UC3:
    {
        QImage gambar(inMat.data,inMat.cols,inMat.rows,
                      static_cast<int>(inMat.step),QImage ::Format_RGB888);
        return gambar.rgbSwapped();
    }
    case CV_8UC1:
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,5,0)
        QImage gambar(inMat.data,inMat.cols,inMat.rows,
                      static_cast<int>(inMat.step),QImage ::Format_Grayscale8);
#else
        static QVector<QRgb> sColorTable;
        if(sColorTable.isEmpty())
        {
            sColorTable.resize(256);
           for(int i=0;i<256;i++)
           {
               sColorTable[i]=qRgb(i,i,i);
           }
        }
        QImage gambar(inMat.data,inMat.cols,inMat.rows,
                      static_cast<int>(inMat.step),QImage :: Format_Indexed8);
        gambar.setColorTable(sColorTable);
#endif
        return gambar;
    }
    default :
        qWarning()<<"Ngak bisa handle" << inMat.type();
        break;
    }
    return QImage();
}
inline QPixmap cvMatToQPixmap(const cv ::Mat &inMat)
{
    return QPixmap::fromImage(cvMatToQImage(inMat));
}
}

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};
*/
#endif // MAINWINDOW_H
