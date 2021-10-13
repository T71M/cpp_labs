//
//  Player.cpp
//  ex_1
//
//  Created by 71M on 08.10.2021.
//

#include "Player.hpp"
#include <iostream>
using namespace std;
#include "ctime"



Player:: Player(GameCard card){
   
    cout << "Введите вашу ставку: ";
    cin >> bet;
    firstHand = new Deck(card);
   
}

int Player:: getBet(){
    return bet;
}
void Player:: setBet(int bet){
    this -> bet = bet;
}

void Player:: setUpSecondHand(){
    GameCard temp;
    temp.setValue((*firstHand)[1]);
    secondHand = new Deck(temp);
    firstHand->deleteCard(1);
}



int Player:: calculatePoints(Deck *deck)  {
    
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
        }else if(coutPoints > 21){
            return -1;
        }
        return coutPoints;
    }
   

