#include "card.h"

Card::Card(Number number, Color color)
{

    this->number = number;
    this->color = color;

    isDistributed = false;

}

Card::~Card()
{

}

bool Card::getIsDistributed() const
{
    return isDistributed;
}

void Card::setIsDistributed(bool value)
{
    isDistributed = value;
}
