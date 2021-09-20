//
//  ILoggable.hpp
//  ex_1
//
//  Created by 71M on 30.08.2021.
//
#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class ILoggable {
    
public:
    virtual void logToFile(string& filename) const = 0;
    virtual void logToScreen() const = 0;
    
};
