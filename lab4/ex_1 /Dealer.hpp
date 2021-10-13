//
//  Dealer.hpp
//  ex_1
//
//  Created by 71M on 08.10.2021.
//



#include <stdio.h>
#include "GameCard.hpp"
#include "Deck.hpp"
#pragma once

class Dealer {
    friend class Game;
public:
    Dealer();
    Dealer(Deck& deck);
    void getCardFirstHand(GameCard card);
    void getCardSecondHand(GameCard card);
    void printFirstHand();
    void printSecndHand();
    GameCard getRandCard(Deck& deck);
    virtual int calculatePoints(Deck* deck);
    ~Dealer();
   
   
    
private:
    void endGame(Deck& deck,bool split);
    void setUpSecondHand(Deck& deck);
    
protected:
    Deck* firstHand = nullptr;
    Deck* secondHand = nullptr;
    
};
