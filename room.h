#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QList>
#include "card.h"

class Player;
class Card;

class Room : public QObject
{
    Q_OBJECT
public:
    Room();
    bool getStatus() const;
    int getPot() const;
    //Player getDealer() const;
    //QList<Player> getPlayersList() const;

signals:
    //void sendPlayerCard();
    //void sendFlop();
    //void sendTurn();
    //void sendRiver();
    //void sendPot();

protected slots:
    //void onConnectPlayer(User &user);
    //void onBet(User &user, int bet);

private:
    int ID;
    //QList<Player> playersList;
    QList<Card *> board;
    int pot;
    //Player dealer;
    bool status;
    QList<Card *> cards;

    void init();
    void handle();

};

#endif // ROOM_H
