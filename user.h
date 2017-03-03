#ifndef USER_H
#define USER_H

#include <QObject>

class QString;

class User : public QObject
{
    Q_OBJECT
public:
    User(int id, QString username);
    ~User();

    int getId() const;
    void setId(int value);

    QString getUsername() const;
    void setUsername(const QString &value);

private:
    int id;
    QString username;



};

#endif // USER_H
