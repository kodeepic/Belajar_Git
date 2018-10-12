#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <opencv2/opencv.hpp>
class CVImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CVImageWidget(QWidget *parent = 0) : QWidget(parent) {}

    QSize sizeHint() const { return _qimage.size(); }
    QSize minimumSizeHint() const { return _qimage.size(); }

public slots:  //A slot or function is defined which will be intiated

    void showImage(const cv::Mat& frame) {
        // Convert the image to the RGB888 format
        switch (frame.type()) {
        case CV_8UC1:
            cvtColor(frame, _tmp, CV_GRAY2RGB);
            break;
        case CV_8UC3:
            cvtColor(frame, _tmp, CV_BGR2RGB);
            break;
        }

        // QImage needs the data to be stored continuously in memory
       assert(_tmp.isContinuous());
        // Assign OpenCV's image buffer to the QImage. Note that the bytesPerLine parameter
        // (http://qt-project.org/doc/qt-4.8/qimage.html#QImage-6) is 3*width because each pixel
        // has three bytes.
        _qimage = QImage(_tmp.data, _tmp.cols, _tmp.rows, _tmp.cols*3, QImage::Format_RGB888);

        this->setFixedSize(frame.cols, frame.rows);

        repaint();
    }

protected:

    void paintEvent(QPaintEvent* /*event*/) {
        // Display the image
        QPainter painter(this);
        painter.drawImage(QPoint(0,0), _qimage);
        painter.end();
    }

    QImage _qimage;
    cv::Mat _tmp;
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
