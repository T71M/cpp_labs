//
//  IFormattable.hpp
//  ex_2
//
//  Created by 71M on 11.10.2021.
//

#include <stdio.h>

#pragma once
#include <iostream>
#include <string>
using namespace std;

class IFormattable {
public:
    virtual string format() const = 0;
};
