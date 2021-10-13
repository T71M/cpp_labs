//
//  Game.cpp
//  ex_1
//
//  Created by 71M on 08.10.2021.
//

#include "Game.hpp"
#include <iostream>
using namespace std;

Game:: Game(){
    endGame = false;
    split = false;
    srand((unsigned)time(NULL));
}
void Game:: resetGame(){
    delete dealer;
    delete player;
    delete[] deck;
    endGame = false;
    split = false;
    show = false;
    deck = new Deck[4];
    dealer = new Dealer(*getRandDeck());
    player = new Player(dealer -> getRandCard(*getRandDeck()));
    cntSteps = 0;
}
void Game:: defaultGame(){
    while(!endGame){
        try{
            printGameStats();
            if(show){
                calculateWinner();
                breakGame();
                return;
                
            }
            if(cntSteps == 0){
                int choose;
                cout << "1. Взять карту " << endl;
                cin >> choose;
                if(choose == 1){
                    player -> getCardFirstHand( dealer -> getRandCard(*getRandDeck()) );
                }
            } else if(cntSteps == 1){
                int choose;
                cout << "1. Взять карту " << endl << "2. Сплит " << endl << "3. Хватит "<< endl;
                cin >> choose;
                if(choose == 1){
                    player -> getCardFirstHand(dealer -> getRandCard(*getRandDeck()));
                    int a =  player -> calculatePoints(player-> firstHand);
                     a == -1 ? throw -1 : NULL;
                } else if(choose == 3){
                    show = true;
                    dealer -> endGame( *getRandDeck(), split );
                } else if(choose == 2){
                    split = true;
                    player -> setUpSecondHand();
                    dealer -> setUpSecondHand( *(getRandDeck()) );
                    break;
                }
            } else {
                int choose;
                cout << "1. Взять карту" << endl << "2. Хватит " << endl;
                cin >> choose;
                if(choose == 1){
                    player -> getCardFirstHand(dealer -> getRandCard(*getRandDeck()));
                    int a =  player -> calculatePoints(player-> firstHand );
                    a == -1 ? throw -1 : NULL;
                } else if(choose == 2){
                    show = true;
                    dealer ->endGame( *getRandDeck(), split);
                }
                
            }
            ++cntSteps;
            cout << endl << endl << endl;
        } catch(int){
            printGameStats();
            cout << "Перебор! Вы проиграли! Ваш проигрыш: " << player -> getBet() << endl;
            breakGame();
           
           
           
    }
        catch(const char*){
            printGameStats();
        cout << "Пара тузов! Вы выиграли! Ваш выигрыш: " << player -> getBet() << " ";
        player -> setBet(player -> getBet() * 2);
        cout << "Всего: " << player -> getBet();
        breakGame();
    
    }
        catch(bool){
            printGameStats();
        cout << "У диллера пара тузов! Вы проиграли! Ваш проигрыш: " << player -> getBet() << endl;
            breakGame();
    }
        catch(double){
            printGameStats();
        cout << "У диллера перебор! Вы выиграли! Ваш выигрыш: " << player -> getBet() << " " ;
        player -> setBet(player -> getBet() * 2);
        cout << "Всего: " << player -> getBet();
        cout << endl;
        breakGame();
    }
            
        }
    
}
void Game:: splitGame(){
    cntSteps = 0;
    bool firstHandLose = false;
    bool secondHandLose = false;
    while(!endGame){
        try{
            printSplitGameStats();
            if(show){
                calculateWinnerSplit();
                breakGame();
                return;
            }
            if(firstHandLose && secondHandLose){
                show = true;
                dealer -> endGame(*getRandDeck(), split);
                continue;
            }
            if(cntSteps == 0){
                int choose;
                string firstStep = firstHandLose == 1 ? "" : "1. Взять карту для 1 руки ";
                string secondStep = secondHandLose == 1.1 ? "" : "2. Взять карту для 2 руки  ";
                cout << firstStep << endl << secondStep  << endl;
                cin >> choose;
                if(choose == 1){
                    player -> getCardFirstHand(dealer -> getRandCard(*getRandDeck()));
                    int a = player -> calculatePoints(player->firstHand);
                    if(a == -1){
                        firstHandLose = true;
                        throw 1;
                    }
                } else if(choose == 2){
                    player -> getCardSecondHand(dealer -> getRandCard(*getRandDeck()));
                    int a = player -> calculatePoints(player->firstHand);
                    if(a == -1){
                        secondHandLose = true;
                        throw 1.1;
                    }
                }
            } else if(cntSteps == 1){
                int choose;
                string firstStep = firstHandLose == 1 ? "" : "1. Взять карту для 1 руки ";
                string secondStep = secondHandLose == 1.1 ? "" : "2. Взять карту для 2 руки  ";
                cout  << firstStep << endl << secondStep  << endl << "3. Хватит "<< endl;
                cin >> choose;
                if(choose == 1){
                    player -> getCardFirstHand(dealer -> getRandCard(*getRandDeck()));
                    int a = player -> calculatePoints(player->firstHand);
                    if(a == -1){
                        firstHandLose = true;
                        throw 1;
                    }
                    
                } else if(choose == 3){
                    show = true;
                    dealer -> endGame( *getRandDeck(), split);
                    continue;
                } else if(choose == 2){
                    player -> getCardSecondHand(dealer -> getRandCard(*getRandDeck()) );
                    int a = player -> calculatePoints(player->secondHand);
                    if(a == -1){
                        secondHandLose = true;
                        throw 1.1;
                    }
                }
            } else {
                int choose;
               
                string firstStep = firstHandLose == 1 ? "" : "1. Взять карту для 1 руки  ";
                string secondStep = secondHandLose == 1.1 ? "" : "2. Взять карту для 2 руки  ";
                
                cout << firstStep << endl << secondStep << endl <<  "3.Хватит" << endl;
                cin >> choose;
                if(choose == 1){
                    player -> getCardFirstHand(dealer -> getRandCard(*getRandDeck()));
                    int a = player -> calculatePoints(player->firstHand);
                    if(a == -1){
                        firstHandLose = true;
                        throw 1;
                    }
                } else if (choose == 2){
                    player -> getCardSecondHand(dealer -> getRandCard(*getRandDeck()));
                    int a = player -> calculatePoints(player->secondHand);
                    if(a == -1){
                        secondHandLose = true;
                        throw 1.1;
                    }
                } else if(choose == 3){
                    show = true;
                    dealer -> endGame( *getRandDeck(), split);
                    continue;
                   
                }
                
            }
            ++cntSteps;
            cout << endl << endl << endl;
        }catch(int){
            cout << "Перебор в 1 руке!";
            cout << endl << endl << endl;
            continue;
        }catch(double){
            cout << "Перебор вo 2 руке!";
            cout << endl << endl << endl;
            continue;
        }
        
        }
    
}
void Game:: gameProcess(){
    while(!endGame){
        defaultGame();
        if(split){
            splitGame();
        }
    }
}

void Game:: breakGame(){
    int choose;
    cout << endl;
    cout << "1.Продолжить " << endl << "2. Хватит" << endl;
    cin >> choose;
    if(choose == 1){
        resetGame();
    } else if (choose == 2) endGame = true;
}

void Game:: printSplitGameStats(){
    cout << "Ваша ставка: " << player -> getBet() << " ₽";
    cout << endl;
    cout << "Колоды: ";
    for(int i = 0; i < 4; ++i){
        cout << "[" << deck[i].getDeckCount() << "] ";
    }
    cout << endl;
    
    cout << "1 рука дилера: ";
    dealer -> printFirstHand();
    string output = show ?  "" : " ??";
    cout << output;
    cout << endl;
    cout << "2 рука дилера: ";
    dealer -> printSecndHand();
    cout << output;
    cout << endl;
    
    cout << "Ваша первая рука: ";
    player -> printFirstHand();
    cout << endl;
    cout << "Ваша 2 рука: ";
    player -> printSecndHand();
    
    cout << endl;
    
}

void Game:: calculateWinner(){
    int playerPoints = player -> calculatePoints(player -> firstHand);
    int dealerPoints = dealer -> calculatePoints(dealer -> firstHand);
    if(dealerPoints == 1) throw true;
    if (dealerPoints == -1) throw 1.1;
    else if(playerPoints == 1){
        throw 'A';
    } else{
    if (dealerPoints > playerPoints){
       cout << "Недобор! Вы проиграли! Ваш проигрыш: " << player -> getBet();
   } else if(playerPoints > dealerPoints){
       cout << " Вы выиграли! Ваш выигрыш: " << player -> getBet() << " ";
       player -> setBet(player -> getBet() * 2);
       cout << "Всего: " << player -> getBet();
   }else if(playerPoints == dealerPoints){
       cout << "Ничья! Ваша ставка остается при вас";
   }
   cout << endl;
    }
}

void Game:: calculateWinnerSplit(){
   
    int playerFirstHand = player -> calculatePoints(player -> firstHand);
    int dealerFirstHand = dealer -> calculatePoints(dealer -> firstHand);
    int playerSecondHand = player -> calculatePoints(player -> secondHand);
    int dealerSecondHand = dealer -> calculatePoints(dealer -> secondHand);
    
    bool playerFirstHandWin = false;
    bool playerSecondHandWin = false;
    bool dealerFirstHandWin = false;
    bool dealerSecondHandWin = false;
    
    if(dealerFirstHand == -1) cout << "У диллера в 1 руке перебор!" << endl;
    if(dealerSecondHand == -1) cout << "У диллера во 2 руке перебор!" << endl;
    
    if(playerFirstHand == 1){
        if(dealerFirstHand != 1){
            cout << "В вашей 1 руке пара тузов!" << endl;
            playerFirstHandWin = true;
        } else {
            cout << "В 1 руке ничья!";
            playerFirstHandWin = true;
            dealerFirstHandWin = true;
        }
    }
    else if(playerFirstHand != -1 && dealerFirstHand != -1){
        if(playerFirstHand > dealerFirstHand){
            playerFirstHandWin = true;
        } else if(dealerFirstHand == playerSecondHand){
            cout << "В 1 руке ничья!";
            playerFirstHandWin = true;
            dealerFirstHandWin = true;
            
        }else{
            dealerFirstHandWin = true;
        }
    }
    
    if(playerSecondHand == 1){
        if(dealerSecondHand != 1){
            cout << "В Вашей 2 руке пара тузов!" << endl;
            playerSecondHandWin = true;
        } else {
            cout << "Вo 2 руке ничья!";
            playerSecondHandWin = true;
            dealerSecondHandWin = true;
        }
    }
    else if(playerSecondHand != -1 && dealerSecondHand != -1){
        if(playerSecondHand > dealerSecondHand){
            playerSecondHandWin = true;
        }  else if(dealerSecondHand == playerSecondHand){
            cout << "Вo 2 руке ничья!";
            playerSecondHandWin = true;
            dealerSecondHandWin = true;
            
        } else{
            dealerSecondHandWin = true;
        }
    }
    
    
    if(playerFirstHandWin || playerSecondHandWin){
        if(!dealerFirstHandWin || !dealerSecondHandWin ){
            cout << "2 Ваши руки выиграли! Ваш выигрыш:  " << player -> getBet() << " ";
            player -> setBet(player -> getBet() * 2);
            cout << "Всего: " << player -> getBet();
        }
        else {
            cout << "1 Ваша игра сыграла в ничью! Ваша ставка остается при Вас!";
        }
    }
    else if (!playerFirstHandWin && !playerSecondHandWin ){
        if(!dealerFirstHandWin || !dealerSecondHandWin){
            cout << "1 Ваша рука сыграла в ничью! Ваша ставка остается при Вас!";
        }else{
            cout << "Вы проиграли! Ваш проигрыш: " << player -> getBet();
        }
       
    }
    
}

Deck* Game:: getRandDeck(){
    int randPos = rand()% 4;
    return &deck[randPos];
}

void Game:: printGameStats(){
    cout << "Ваша ставка: " << player -> getBet() << " ₽";
    cout << endl;
    cout << "Колоды: ";
    for(int i = 0; i < 4; ++i){
        cout << "[" << deck[i].getDeckCount() << "] ";
    }
    cout << endl;
    
    cout << "Дилер: ";
    dealer -> printFirstHand();
    string output = show ?  "" : " ??";
    cout << output;
    cout << endl;
    
    cout << "Вы: ";
    player -> printFirstHand();
    cout << endl;
}

Game:: ~Game(){
    delete player;
    delete dealer;
    delete[] deck;
}

