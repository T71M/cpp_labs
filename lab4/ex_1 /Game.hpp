//
//  Game.hpp
//  ex_1
//
//  Created by 71M on 08.10.2021.
//



#include <stdio.h>
#include "Player.hpp"
#include "Deck.hpp"
#include "Dealer.hpp"
#pragma once

class Game {
public:
    
    Game();
    void gameProcess();
    void resetGame();
    void printGameStats();
    Deck* getRandDeck();
    void calculateWinner();
    void calculateWinnerSplit();
    void  printSplitGameStats();
    void breakGame();
    void defaultGame();
    void splitGame();
    ~Game();
  
    
private:
    bool split;
    bool endGame;
    bool show;
    Deck* deck = new Deck[4];
    Dealer* dealer = new Dealer(*getRandDeck());
    Player* player = new Player(dealer -> getRandCard(*getRandDeck()));
   
    int cntSteps = 0;
};
