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
    rang = card.getRang();
}
GameCard:: GameCard(){
    value = "";
}
void GameCard:: setValue(string value){
    this -> value = value;
}
void GameCard:: setRang(string rang){
    this -> rang = rang;
}

string GameCard:: getRang() const{
    return rang;
}

ostream& operator << (ostream& out, const GameCard card){
    out << card.getRang() << card.getValue();
    return out;
}


