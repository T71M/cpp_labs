//
//  classAdapter.cpp
//  ex_2
//
//  Created by 71M on 11.10.2021.
//

#include "classAdapter.hpp"



classAdapter:: classAdapter() : Deck(){
}
classAdapter:: classAdapter(Deck& deck) : Deck(deck){
}

string classAdapter:: format() const{
    return shuffle();
}
