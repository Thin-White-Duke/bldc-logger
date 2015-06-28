#ifndef ARGPROCESSOR_H
#define ARGPROCESSOR_H

#include <QObject>

class ArgProcessor : public QObject
{
    Q_OBJECT
public:
    explicit ArgProcessor(QObject *parent = 0);

    QString getPort() const;
    int getCamera() const;
    int getWidth() const;
    int getHeight() const;
    double getFps() const;

private:
    QString mPort;
    int mCamera;
    int mWidth;
    int mHeight;
    double mFps;

};

inline QString ArgProcessor::getPort() const
{
    return mPort;
}

inline int ArgProcessor::getCamera() const
{
    return mCamera;
}

inline int ArgProcessor::getWidth() const
{
    return  mWidth;
}

inline int ArgProcessor::getHeight() const
{
    return mHeight;
}

inline double ArgProcessor::getFps() const
{
    return mFps;
}

#endif // ARGPROCESSOR_H
