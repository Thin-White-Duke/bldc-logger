#include "argprocessor.h"

#include <QTextStream>

ArgProcessor::ArgProcessor(QObject *parent) : QObject(parent)
{
    QTextStream streamOut(stdout);
    QTextStream streamIn(stdin);
#ifdef Q_OS_WIN
    QString defaultPort_ = "COM3";
#elif defined(Q_OS_MAC)
    QString defaultPort_ = "/dev/tty.usbmodem261";
#else
    QString defaultPort_ = "/dev/ttyACM0";
#endif
    streamOut << "Port (default is " + defaultPort_ + "): ";
    streamOut.flush();
    mPort = streamIn.readLine();
    if(mPort.isEmpty()) {
        mPort = defaultPort_;
    }

    streamOut << "Camera index (default is 0): ";
    streamOut.flush();
    mCamera = streamIn.readLine().toInt();

    streamOut << "Camera width (default is 1280): ";
    streamOut.flush();
    mWidth = streamIn.readLine().toInt();
    if(mWidth == 0) {
        mWidth = 1280;
    }

    streamOut << "Camera height (default is 720): ";
    streamOut.flush();
    mHeight = streamIn.readLine().toInt();
    if(mHeight == 0) {
        mHeight = 720;
    }

    streamOut << "Camera fps (default is 25.0): ";
    streamOut.flush();
    mFps = streamIn.readLine().toInt();
    if(mFps == 0) {
        mFps = 25.0;
    }
}

