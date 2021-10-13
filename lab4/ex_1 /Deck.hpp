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
    friend class Dealer;
public:
    Deck();
    Deck(GameCard card);
    Deck(const Deck& deck);
    void addCard(GameCard card);
    void deleteCard(int n);
    string operator [](int n) const;
    void printDeck();
    int getDeckCount();
    ~Deck();

private:
    GameCard* deck = nullptr;
    int deckCount;
    GameCard getRandCard();
};
