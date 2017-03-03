#include "server.h"
//#include "thread.h"

#include <QDebug>
#include <QTcpServer>

Server::Server(QObject * parent) :
    QTcpServer(parent)
{
}

void Server::startServer()
{
    int port = 1337;

    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Unable to start server...";
    }
    else
    {
        qDebug() << "Server is listenning on port: " + port;
    }

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "Client ID " + socketDescriptor + " is connecting...";
}
