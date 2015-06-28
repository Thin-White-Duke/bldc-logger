#-------------------------------------------------
#
# Project created by QtCreator 2014-07-19T13:28:24
#
#-------------------------------------------------

# On Ubuntu:
# sudo apt-get install qt-sdk libqt5multimedia5 libqt5multimedia5-plugins qtmultimedia5-dev

QT       += core
QT       += gui
QT       += printsupport
QT       += multimedia
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BLDC_Logger
CONFIG   += console
CONFIG   -= app_bundle

macx: QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9

win32 {
    OPENCV_PATH = D:/Dev/Tools/opencv2/sources-build/install
    INCLUDEPATH += $${OPENCV_PATH}/include
    LIBS += -L$${OPENCV_PATH}/x64/mingw/lib -lopencv_core2411.dll -lopencv_highgui2411.dll
}

macx {
    OPENCV_PATH = /Users/admin/Dev/opencv-2.4.11-build/install
    INCLUDEPATH += $${OPENCV_PATH}/include
    LIBS += -L$${OPENCV_PATH}/lib -lopencv_core -lopencv_highgui
}

unix:!macx {
    LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui \
            -lopencv_ml -lopencv_video -lopencv_features2d \
            -lopencv_calib3d -lopencv_objdetect -lopencv_contrib \
            -lopencv_legacy -lopencv_flann
}

TEMPLATE = app


SOURCES += main.cpp \
    packetinterface.cpp \
    logger.cpp \
    utility.cpp \
    MatToQImage.cpp \
    qcustomplot.cpp \
    videocoder.cpp \
    frameplotter.cpp \
    framegrabber.cpp \
    argprocessor.cpp

HEADERS += \
    packetinterface.h \
    logger.h \
    utility.h \
    MatToQImage.h \
    qcustomplot.h \
    videocoder.h \
    frameplotter.h \
    framegrabber.h \
    argprocessor.h

win32 {
    SOURCES += consolereader_win.cpp
    HEADERS += consolereader_win.h
} unix {
    SOURCES += consolereader.cpp
    HEADERS += consolereader.h
}
