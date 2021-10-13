//
//  Deck.hpp
//  ex_1
//
//  Created by 71M on 21.09.2021.
//

#pragma once
#include <stdio.h>
#include "GameCard.hpp"


class Deck {
public:
    Deck();
    Deck(GameCard card);
    Deck(const Deck& deck);
    void addCard(GameCard card);
    void deleteCard(int n);
    GameCard operator [](int n) const;
    void printDeck();
    int getDeckCount();
   
    string shuffle() const;
    ~Deck();
protected:
    GameCard* deck = nullptr;
private:
    int deckCount;
    GameCard getRandCard();
};
