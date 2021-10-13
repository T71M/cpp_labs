//
//  GameCard.cpp
//  ex_1
//
//  Created by 71M on 21.09.2021.
//

#include "GameCard.hpp"
#include <iostream>
using namespace std;


string GameCard:: getValue() const {
    return value;
}
GameCard:: GameCard(const GameCard& card){
    value = card.getValue();
}
GameCard:: GameCard(){
    value = "";
}
void GameCard:: setValue(string value){
    this -> value = value;
}
ostream& operator << (ostream& out, const GameCard card){
    out << card.getValue();
    return out;
}


