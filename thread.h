#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QTcpSocket>

class QThread;

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(qintptr ID, QObject *parent = 0);
    ~Thread();
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket * socket;
    qintptr socketDescriptor;
};

#endif // THREAD_H
