#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QList>

class Player;
class Card;
class QList;

class Room
{
public:
    Room();
    bool getStatus() const;
    int getPot() const;
    Player getDealer() const;
    QList<Player> getPlayersList() const;

signals:
    void sendPlayerCard();
    void sendFlop();
    void sendTurn();
    void sendRiver();
    void sendPot();

protected slots:
    void onConnectPlayer(User &user);
    void onBet(User &user, int bet);

private:
    int ID;
    QList<Player> playersList;
    Card board[5];
    int pot;
    Player dealer;
    bool status;
    Card cards[52];

    void init();
    void handle();

};

#endif // ROOM_H
