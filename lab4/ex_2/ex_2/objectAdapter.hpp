//
//  objectAdapter.hpp
//  ex_2
//
//  Created by 71M on 11.10.2021.
//

#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "IFormattable.hpp"
#include "Deck.hpp"
using namespace std;

class objectAdapter : public IFormattable {
public:
    objectAdapter();
    objectAdapter(Deck* deck);
    string format() const override;
private:
    Deck* deck;
};
