//
//  Dealer.cpp
//  ex_1
//
//  Created by 71M on 08.10.2021.
//

#include "Dealer.hpp"
#include <iostream>
using namespace std;

Dealer:: Dealer(){
    
}
Dealer:: Dealer(Deck& deck){
    firstHand = new Deck(deck.getRandCard());
}
void Dealer:: getCardFirstHand(GameCard card){
    firstHand -> addCard(card);
}

void Dealer:: getCardSecondHand(GameCard card){
    secondHand -> addCard(card);
}

void Dealer:: printFirstHand(){
  firstHand->printDeck();
}

void Dealer:: printSecndHand(){
   secondHand->printDeck();
}

void Dealer:: setUpSecondHand(Deck& deck){
secondHand = new Deck(deck.getRandCard());
}

int Dealer:: calculatePoints(Deck* deck){
    int coutPoints = 0;
    int cntAPlayer = 0;
    
    for(int i = 0; i < (*deck).getDeckCount(); i++){
        string value = (*deck)[i];
        int test = value[0] - '0';
        if(test < 10){
            if(test == 1){
                coutPoints += 10;
            }else{
                coutPoints += test;
            }
           
        }
        else{
            if(value[0] == 'A'){
                coutPoints+= 11;
                cntAPlayer++;
            }
            else{
                coutPoints+= 10;
            }
        }
    }
    
    if(cntAPlayer > 1){
        return 1;
    } if(coutPoints > 21){
        return -1;
    }
    return coutPoints;
}

void Dealer:: endGame(Deck& deck, bool split){
    int points =  calculatePoints(firstHand);
    if(points != 1 || points != -1){
        while(true){
            int temp = calculatePoints(firstHand);
            if (temp < 17) {
                if(temp == 1) break;
                if(temp == -1) break;
                GameCard card = deck.getRandCard();
                this ->firstHand ->addCard(card);
            } else break;
        }
    }
    if(split){
        int points =  calculatePoints(secondHand);
        if(points != 1 || points != -1){
            while(true){
                int temp = calculatePoints(secondHand);
                if(temp == 1) break;
                else if(temp == -1) break;
                else if (temp < 17) {
                    GameCard card = deck.getRandCard();
                    secondHand->addCard(card);
                } else return;
            }
        }
    }
}
GameCard Dealer:: getRandCard(Deck& deck){
    return deck.getRandCard();
}

Dealer:: ~Dealer(){
    delete firstHand;
    delete secondHand;
}


