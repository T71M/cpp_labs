//
//  ISalaryCalculation.hpp
//  ex_2
//
//  Created by 71M on 01.09.2021.
//


#pragma once
#include <stdio.h>

class ISalaryCalculation {
public:
  virtual double calculate() const = 0;
};
