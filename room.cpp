#include "room.h"
//#include "player.h"
#include "card.h"
#include "user.h"

#include <QList>

Room::Room()
{
    init();
    handle();
}

enum Number {
    AS,
    One,
    Two,
    Three,
    Four,
    Five,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

enum Color {
    Pike,
    Clover,
    Heart,
    Tile
};

void Room::init()
{
    for(int i=AS; i != King; ++i)
    {
        for(int j=Pike; j != Tile; ++j) {
            cards.append(new Card(i, j));
        }
    }
}

void Room::handle()
{
    //connect(this, &Player::bet, this, &Room::onBet);
    //connect(this, )
}

bool Room::getStatus() const
{
    return status;
}

int Room::getPot() const
{
    return pot;
}

/*Player Room::getDealer() const
{
    return dealer;
}

QList<Player> Room::getPlayersList() const
{
    return playersList;
}*/

