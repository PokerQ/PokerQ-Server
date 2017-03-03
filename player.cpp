#include "player.h"
#include "card.h"

Player::Player(int _user_id, int _position)
{
    init(_user_id, _position);
}

void Player::init(int _user_id, int _position)
{
    user_id = _user_id;
    position = _position;
    stack = 500;
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
        emit fold();
    } else {
        emit(sendBet(value));
    }
}

int Player::getPosition() const
{
    return position;
}


void Player::receiveHand(QPair<Card, Card> _hand)
{
    hand = _hand;
}

Player::~Player()
{

}
