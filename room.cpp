#include "room.h"
#include "player.h"
#include "card.h"

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
            cards[i+j] = new Card(static_cast<Number>(i), static_cast<Color>(j));
        }
    }
}

void Room::init()
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

Player Room::getDealer() const
{
    return dealer;
}

QList<Player> Room::getPlayersList() const
{
    return playersList;
}

