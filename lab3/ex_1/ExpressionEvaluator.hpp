//
//  ExpressionEvaluator.hpp
//  ex_1
//
//  Created by 71M on 30.08.2021.
//
#pragma once
#include <stdio.h>
#include "ILoggable.hpp"
#include <string>
using namespace std;

class ExpressionEvaluator:public ILoggable {
public:
    ExpressionEvaluator();
    ExpressionEvaluator(int n);
    virtual double calculate() const = 0;
    void setOperand(size_t n, double value);
    void setOperands(double* ops, size_t n);
    ~ExpressionEvaluator();
protected:
    int operandsCount;
    double* operands;
};

