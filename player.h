#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Card;
class Room;

class Player : public QObject
{
    Q_OBJECT
public:
    Player(int _user_id, int _position, Room * _room);
    ~Player();
    int getID() const;
    int getUser_id() const;
    int getStack() const;
    void setStack(int value);
    int getBet() const;
    void setBet(int value);
    int getPosition() const;

private:
    int ID;
    int user_id;
    QPair<Card*, Card*> hand;
    int stack;
    int bet;
    int position;
    void init(int _user_id, int _position, Room *  _room);
    void handle();

public slots:
    void receiveHand(QPair<Card*, Card*>);

signals:
    void sendFold(Player * player);
    void sendBet(Player * player, int value);


};

#endif // PLAYER_H
