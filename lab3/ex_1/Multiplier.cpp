//
//  Multiplier.cpp
//  ex_1
//
//  Created by 71M on 30.08.2021.
//

#include "Multiplier.hpp"
#include <fstream>
#include <iostream>

double Multiplier :: calculate() const {
    double answer = 1;
    for(int i = 0; i < operandsCount; i++){
        answer *= operands[i];
    } 
    return answer;
}

void Multiplier:: logToFile(string &filename) const {
    ofstream fout;
    fout.open("/Users/71M/Desktop/cpp_labs/lab_3/ex_1/" + filename + ".txt", fstream::app);
    fout << "Multiplier" << endl;
    for(int i = 0; i < operandsCount; i++){
        if(i != operandsCount - 1){
            if(operands[i] >= 0) fout << operands[i] << " * ";
            else fout << "(" << operands[i] << ")" << " * ";
        }
        else{
            if(operands[i] >= 0) fout << operands[i] << " * " << calculate();
            else fout << "(" << operands[i] << ")" << " * " << calculate();
        }
    }
}
void Multiplier:: logToScreen() const {
    cout << "Multiplier" << endl;
    for(int i = 0; i < operandsCount; i++){
        if(i != operandsCount - 1){
            if(operands[i] >= 0) cout << operands[i] << " * ";
            else cout << "(" << operands[i] << ")" << " * ";
        }
        else{
            if(operands[i] >= 0) cout << operands[i] << " = " << calculate() << endl;
            else cout << "(" << operands[i] << ")" << " = " << calculate() << endl;
        }
    }
}
