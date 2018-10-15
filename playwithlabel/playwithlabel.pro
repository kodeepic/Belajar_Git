#-------------------------------------------------
#
# Project created by QtCreator 2018-10-15T11:25:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = playwithlabel
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH +=C:\OpenCV\opencv\build\install\include

LIBS +=C:\OpenCV\opencv\build\bin\libopencv_core343.dll
LIBS +=C:\OpenCV\opencv\build\bin\libopencv_highgui343.dll
LIBS +=C:\OpenCV\opencv\build\bin\libopencv_imgcodecs343.dll
LIBS +=C:\OpenCV\opencv\build\bin\libopencv_imgproc343.dll
LIBS +=C:\OpenCV\opencv\build\bin\libopencv_calib3d343.dll
LIBS +=C:\OpenCV\opencv\build\bin\libopencv_videoio343.dll
LIBS +=C:\OpenCV\opencv\build\bin\libopencv_photo343.dll
LIBS +=C:\OpenCV\opencv\build\bin\libopencv_video343.dll

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui
