#ifndef CARD_H
#define CARD_H

#include <QObject>

class Card : public QObject
{
    Q_OBJECT

public:
    Card(int number, int color);
    ~Card();


public:

    bool getIsDistributed() const;
    void setIsDistributed(bool value);

private:
    bool isDistributed;
    int number;
    int color;

    enum class Number {
        AS,
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

    enum class Color {
        Pike,
        Clover,
        Heart,
        Tile
    };

};

#endif // CARD_H
