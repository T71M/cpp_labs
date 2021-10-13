//
//  main.cpp
//  ex_1
//
//  Created by 71M on 02.09.2021.
//

#include <iostream>
#include "Game.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Game* game = new Game;
    game -> gameProcess();
    delete game;
    
   
    return 0;
}
