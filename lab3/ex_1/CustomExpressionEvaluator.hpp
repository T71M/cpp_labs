//
//  CustomExpressionEvaluator.hpp
//  ex_1
//
//  Created by 71M on 31.08.2021.
//

#pragma once

#include <stdio.h>
#include "ExpressionEvaluator.hpp"
#include "IShuffle.hpp"
class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle {
    
public:
    double calculate() const override;
    void logToFile(string& filename) const override;
    void logToScreen() const override;
    void shuffle() const override;
    void shuffle(size_t i, size_t j) const override;
    void printOperandsCount();
};
