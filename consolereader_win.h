#ifndef CONSOLEREADER_H
#define CONSOLEREADER_H

#include <QThread>

class ConsoleReader : public QThread
{
    Q_OBJECT

public:
    explicit ConsoleReader(QObject *parent = 0);
    ~ConsoleReader();

signals:
    void textReceived(QString message);

protected:
    void run();

private slots:
    void onCheckStdin();

};

#endif // CONSOLEREADER_H
