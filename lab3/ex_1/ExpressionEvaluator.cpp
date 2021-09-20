//
//  ExpressionEvaluator.cpp
//  ex_1
//
//  Created by 71M on 30.08.2021.
//

#include "ExpressionEvaluator.hpp"




ExpressionEvaluator:: ExpressionEvaluator() {
    operands = new double[20];
    operandsCount = 20;
    for(int i = 0; i < operandsCount; i++){
        operands[i] = 0;
    }
};
ExpressionEvaluator:: ExpressionEvaluator(int n){
    operands = new double[n];
    operandsCount = n;
    for(int i = 0; i < operandsCount; i++){
        operands[i] = 0;
    }
};
void ExpressionEvaluator:: setOperand(size_t n, double value){
    operands[n] = value;
    operandsCount = n + 1;
}
void ExpressionEvaluator:: setOperands(double *ops, size_t n){
    operandsCount = n;
    for(int i = 0 ; i < n; i++){
        operands[i] = *ops;
        ops++;
    }
}
ExpressionEvaluator:: ~ExpressionEvaluator(){
    delete[] operands;
    operandsCount = 0;
}

