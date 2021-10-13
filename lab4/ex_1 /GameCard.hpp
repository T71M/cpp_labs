//
//  GameCard.hpp
//  ex_1
//
//  Created by 71M on 21.09.2021.
//
#pragma once

#include <stdio.h>
using namespace std;
#include <string>

class GameCard {
public:
    GameCard();
    GameCard(const GameCard& card);
    void setValue(string value);
    string getValue() const;
    friend ostream& operator<< (ostream &out, GameCard card);
  
private:
    string value;
};

