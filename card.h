#ifndef CARD_H
#define CARD_H

class Card
{

public:
    Card(Number number, Color color);
    ~Card();

public:

    bool getIsDistributed() const;
    void setIsDistributed(bool value);

private:
    bool isDistributed;
    Number number;
    Color color;

    enum Number {
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

    enum Color {
        Pike,
        Clover,
        Heart,
        Tile
    };
};

#endif // CARD_H
