#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

//class QList;
class Thread;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject * parent = 0);
    ~Server();
    void startServer();

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    QList<Thread *> threadsList;
};

#endif // SERVER_H
