//
//  Multiplier.hpp
//  ex_1
//
//  Created by 71M on 30.08.2021.
//

#pragma once

#include <stdio.h>
#include "ExpressionEvaluator.hpp"

class Multiplier : public ExpressionEvaluator {
public:
    double calculate() const override;
    void logToFile(string& filename) const override;
    void logToScreen() const override;
};
