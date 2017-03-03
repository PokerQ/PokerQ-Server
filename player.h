#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QPair>

class Card;

class Player
{
public:
    Player(int, int);
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
    QPair<Card, Card> hand;
    int stack;
    int bet;
    int position;
    void init(int, int);
    void handle();

public slots:
    void receiveHand(QPair<Card, Card>);

signals:
    void fold();
    void sendBet(int);


};

#endif // PLAYER_H
