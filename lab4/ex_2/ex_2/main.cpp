//
//  main.cpp
//  ex_2
//
//  Created by 71M on 11.10.2021.
//

#include <iostream>
#include "Deck.hpp"
#include "IFormattable.hpp"
#include "objectAdapter.hpp"
#include "classAdapter.hpp"

void prettyPrint(const IFormattable& object ){
    cout << object.format();
}

int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "Russian");
    
    Deck* deck = new Deck;
    cout << "обычная колода: " << endl;
    
    deck -> printDeck();
    cout << endl << endl;
    
    cout << "Адаптер обьекта: " << endl;
    IFormattable* objectAdapter_deck = new objectAdapter(deck);
    prettyPrint(*objectAdapter_deck);
    cout << endl << endl;
    
    
    cout << "адаптер класса: " << endl;
    IFormattable* classAdapter_deck = new classAdapter(*deck);
    prettyPrint(*classAdapter_deck);
    
    
    
    
    
    return 0;
}
