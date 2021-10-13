//
//  Deck.cpp
//  ex_1
//
//  Created by 71M on 21.09.2021.
//

#include "Deck.hpp"
#include <iostream>
using namespace std;
#include "ctime"

Deck:: Deck(){
    srand((unsigned)time(NULL));
    deckCount = 52;
    deck = new GameCard[52];
    string values[] = {"\u2665","\u2666","\u2663", "\u2660"};
    string specCards[] = { "2","3","4","5","6","7","8","9","10", "A","K","J","Q" };
    int cnt = 0;
    int countValue = 0;
    for(int i = 0; i < 52; i++){
        deck[i].setValue(values[countValue]);
        deck[i].setRang(specCards[cnt]);
        cnt++;
        if((i + 1)  % 13 == 0){
            cnt = 0;
            countValue++;
        }
       
    }
}

Deck:: Deck(GameCard card){
    srand((unsigned)time(NULL));
    deckCount = 1;
    deck = new GameCard[11];
    deck[0] = card;
}
Deck:: Deck(const Deck& deck){
    delete this -> deck;
    this-> deck = deck.deck;
}

GameCard Deck:: getRandCard(){
   
      int cardPos = rand()% deckCount;
      GameCard randCard = deck[cardPos];
      deleteCard(cardPos);
      return randCard;

}

GameCard Deck:: operator[](int n) const{
    return deck[n];
}

int Deck:: getDeckCount(){
    return deckCount;
}

void Deck:: addCard(GameCard card){
    deck[deckCount] = card;
    deckCount++;
}

void Deck:: deleteCard(int n){
    deckCount--;
    for(int i = 0; i < deckCount - 1; i++){
        if(i >= n){
            deck[i].setValue(deck[i+1].getValue());
            deck[i].setRang(deck[i+1].getRang());
        }
    }
}

void Deck:: printDeck(){
    for (int i = 0; i < deckCount; ++i) {
        cout << deck[i] << " ";
    }
}


string Deck:: shuffle() const {
    string shuffleDeck = "";
    int* pos = new int[52];
    for(int i = 0; i < 52; ++i){pos[i] = i;}
    for(int i = 0; i< 52; ++i){
        int randPos = rand()%52;
        if(pos[randPos] != -1){
            shuffleDeck += deck[pos[randPos]].getRang() + deck[pos[randPos]].getValue() + " ";
            pos[randPos] = -1;
        } else {
            --i;
        }
    }
    delete[] pos;
   
    return shuffleDeck;
}
Deck:: ~Deck(){
    delete[] deck;
}
