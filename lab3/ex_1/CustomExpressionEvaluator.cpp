//
//  CustomExpressionEvaluator.cpp
//  ex_1
//
//  Created by 71M on 31.08.2021.
//

#include "CustomExpressionEvaluator.hpp"
#include <fstream>
#include <iostream>



double CustomExpressionEvaluator :: calculate() const{
    double answer = 0;
    for(int i = 0; i < operandsCount; i++){
        answer+= operands[i] /(i + 1);
    }
    return answer;
}
void CustomExpressionEvaluator:: logToFile(string &filename) const {
    ofstream fout;
    fout.open("/Users/71M/Desktop/cpp_labs/lab_3/ex_1/" + filename + ".txt", fstream::app);
    fout << "CustomExpressionEvaluator" << endl;
    for(int i = 0; i < operandsCount; i++){
        if(i != 0){
            if(i != operandsCount - 1){
                if(operands[i] >= 0) fout << operands[i] << "/" << i + 1 << " + ";
                else fout << "(" << operands[i] << ")" << "/" << i + 1 << " + ";
            }
            else{
                if(operands[i] >= 0) fout << operands[i] << "/" << i + 1 << " = " << calculate() << endl;
                else fout << "(" << operands[i] << ")" << "/" << i + 1 << " = " << calculate() << endl;
            }
            
        }else {
            if(i != operandsCount - 1){
                if(operands[i] >= 0) fout << operands[i] << " + ";
                else fout << "(" << operands[i] << ")" <<  " + ";
            }
            else{
                if(operands[i] >= 0) fout << operands[i] << " = " << calculate() << endl;
                else fout << "(" << operands[i] << ")"  << " = " << calculate() << endl;
            }
        }
        
    }
}
void CustomExpressionEvaluator:: logToScreen() const {
    cout << "CustomExpressionEvaluator" << endl;
    for(int i = 0; i < operandsCount; i++){
        if(i != 0){
            if(i != operandsCount - 1){
                if(operands[i] >= 0) cout << operands[i] << "/" << i + 1 << " + ";
                else cout << "(" << operands[i] << ")" << "/" << i + 1 << " + ";
            }
            else{
                if(operands[i] >= 0) cout << operands[i] << "/" << i + 1  << " = " << calculate() << endl;
                else cout << "(" << operands[i] << ")" << "/" << i + 1 << " = " << calculate() << endl;
            } 
            
        } else {
            if(i != operandsCount - 1){
                if(operands[i] >= 0) cout << operands[i] << " + ";
                else cout << "(" << operands[i] << ")" <<  " + ";
            }
            else{
                if(operands[i] >= 0) cout << operands[i] << " = " << calculate() << endl;
                else cout << "(" << operands[i] << ")"  << " = " << calculate() << endl;
            }
        }
        
    }
}


void CustomExpressionEvaluator:: shuffle() const {
    double temp;
    if(operands[0] >= 0) operands[0] = -operands[0];
    if(operands[operandsCount - 1] >= 0) operands[operandsCount - 1] = -operands[operandsCount - 1];
    temp = operands[0];
    operands[0] = operands[operandsCount - 1];
    operands[operandsCount - 1] = temp;
    
}


void CustomExpressionEvaluator:: shuffle(size_t i, size_t j) const {
    double temp;
    if(operands[j] >= 0) operands[j] = -operands[j];
    if(operands[i] >= 0) operands[i] = -operands[i];
    temp = operands[j];
    operands[j] = operands[i];
    operands[i] = temp;
}
void CustomExpressionEvaluator:: printOperandsCount(){
    cout << operandsCount << endl;
}
