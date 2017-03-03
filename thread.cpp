#include "thread.h"

#include <QDebug>
#include <QThread>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

Thread::Thread(qintptr ID, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = ID;
}

Thread::~Thread()
{
    delete socket;
}

void Thread::run()
{
    qDebug() << "Thread started";

    socket = new QTcpSocket();

    if (!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, &QTcpSocket::readyRead, this, &Thread::readyRead, Qt::DirectConnection);
    connect(socket, &QTcpSocket::disconnected, this, &Thread::disconnected);

    qDebug() << socketDescriptor << " Client connected";

    exec();
}

void Thread::readyRead()
{
    QString data = QString(socket->readAll());
    QJsonDocument qJsonDocument = QJsonDocument::fromJson(data.toUtf8());
    
    QJsonObject qJsonObject = qJsonDocument.object();
    
    qDebug() << qJsonObject.value("method").toString();
    
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
}
