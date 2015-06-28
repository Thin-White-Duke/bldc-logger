#include "consolereader_win.h"

#include <QtDebug>

#include <QTextStream>
#include <QTimer>

ConsoleReader::ConsoleReader(QObject *parent) : QThread(parent)
{
    start();
}

ConsoleReader::~ConsoleReader()
{
    quit();
    wait();
}

void ConsoleReader::run()
{
   QTimer timer;
   connect(&timer, SIGNAL(timeout()), this, SLOT(onCheckStdin()), Qt::DirectConnection);
   timer.start(100);
   QThread::exec();
}

void ConsoleReader::onCheckStdin()
{
    QTextStream stream(stdin);

    // Do we have a new line to be read ?
    QString line = stream.readLine();
    if (!line.isEmpty())
    {
        emit textReceived(line);
    }
}
