#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
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


private slots:
    void on_pushButton_clicked();
    void onDoubleClicked();
signals:
    void doubleClicked();
protected:
    bool eventFilter(QObject *target, QEvent *event);
private:
    Ui::MainWindow *ui;
    QWidget *widget;
    bool isMaximized;
 //   Mat image;
};

#endif // MAINWINDOW_H
