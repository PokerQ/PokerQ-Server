#include "server.h"
#include "thread.h"

#include <QDebug>
#include <QTcpServer>
#include <QList>

Server::Server(QObject * parent) :
    QTcpServer(parent)
{
}

Server::~Server()
{
    for(int i=0; i<threadsList.length(); ++i)
        delete threadsList.at(i);
}

void Server::startServer()
{
    int port = 31337;

    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Unable to start server...";
    }
    else
    {
        qDebug() << "Server is listenning on port: " << port;
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "Client ID " << socketDescriptor << " is connecting...";

    Thread * thread = new Thread(socketDescriptor, this);
    threadsList.append(thread);

    connect(thread, &Thread::finished, thread, &Thread::deleteLater);

    thread->start();
}
