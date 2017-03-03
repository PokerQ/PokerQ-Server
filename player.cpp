#include "player.h"
#include "card.h"
#include "room.h"

#include <QPair>

Player::Player(int _user_id, int _position, Room * _room)
{
    init(_user_id, _position, _room);
}

void Player::init(int _user_id, int _position, Room * _room)
{
    user_id = _user_id;
    position = _position;
    stack = 500;
    
    QObject::connect(this, &Player::sendFold, _room, &Room::onFold);
    QObject::connect(this, &Player::sendBet, _room, &Room::onBet);
}

int Player::getID() const
{
    return ID;
}

int Player::getUser_id() const
{
    return user_id;
}

int Player::getStack() const
{
    return stack;
}

void Player::setStack(int value)
{
    stack = value;
}

int Player::getBet() const
{
    return bet;
}

void Player::setBet(int value)
{
    bet = value;
    if (bet == 0) {
        emit sendFold(this);
    } else {
        emit sendBet(this, value);
    }
}

int Player::getPosition() const
{
    return position;
}


void Player::receiveHand(QPair<Card*, Card*> _hand)
{
    hand = _hand;
}

Player::~Player()
{

}
