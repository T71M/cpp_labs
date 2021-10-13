//
//  objectAdapter.cpp
//  ex_2
//
//  Created by 71M on 11.10.2021.
//

#include "objectAdapter.hpp"


objectAdapter:: objectAdapter(){
    deck = new Deck;
}
objectAdapter:: objectAdapter(Deck* deck){
    this -> deck = deck;
}
string objectAdapter:: format() const{
    return deck -> shuffle();
}
