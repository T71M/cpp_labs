//
//  Substractor.cpp
//  ex_1
//
//  Created by 71M on 30.08.2021.
//

#include "Substractor.hpp"
#include <fstream>
#include <iostream>

double Substractor :: calculate() const {
    double answer = operands[0];
    for(int i = 1; i < operandsCount; i++){
        answer -= operands[i];
    }
    return answer;
}

void Substractor:: logToFile(string &filename) const {
    ofstream fout;
    fout.open("/Users/71M/Desktop/cpp_labs/lab_3/ex_1/" + filename + ".txt", fstream::app);
    fout << "Substractor" << endl;
    for(int i = 0; i < operandsCount; i++){
        if(i != operandsCount - 1){
            if(operands[i] >= 0) fout << operands[i] << " - ";
            else fout << "(" << operands[i] << ")" << " - ";
        }
        else{
            if(operands[i] >= 0) fout << operands[i] << " = " << calculate() << endl;
            else fout << "(" << operands[i] << ")" << " = " << calculate() << endl;
        }
    }
}
void Substractor:: logToScreen() const {
    cout << "Substractor" << endl;
    for(int i = 0; i < operandsCount; i++){
        if(i != operandsCount - 1){
            if(operands[i] >= 0) cout << operands[i] << " - ";
            else cout << "(" << operands[i] << ")" << " - ";
        }
        else{
            if(operands[i] >= 0) cout << operands[i] << " = " << calculate() << endl;
            else cout << "(" << operands[i] << ")" << " = " << calculate() << endl;
        }
    }
    
}
void Substractor:: shuffle() const {
    double temp;
    if(operands[0] >= 0) operands[0] = -operands[0];
    if(operands[operandsCount - 1] >= 0) operands[operandsCount - 1] = -operands[operandsCount - 1];
    temp = operands[0];
    operands[0] = operands[operandsCount - 1];
    operands[operandsCount - 1] = temp;
    
}


void Substractor:: shuffle(size_t i, size_t j) const {
    double temp;
    if(operands[j] >= 0) operands[j] = -operands[j];
    if(operands[i] >= 0) operands[i] = -operands[i];
    temp = operands[j];
    operands[j] = operands[i];
    operands[i] = temp;
}



