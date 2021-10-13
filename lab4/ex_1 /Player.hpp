//
//  Player.hpp
//  ex_1
//
//  Created by 71M on 08.10.2021.
//

#pragma once

#include <stdio.h>
#include "GameCard.hpp"
#include "Deck.hpp"
#include "Dealer.hpp"

class Player : public Dealer{
    friend class Game;
public:
    Player(GameCard card);
    int getBet();
    void setBet(int bet);
    int calculatePoints(Deck* deck) override;
    void setUpSecondHand();
  
   
private:
    int bet;
};
