//
//  classAdapter.hpp
//  ex_2
//
//  Created by 71M on 11.10.2021.
//



#include <stdio.h>
#include "Deck.hpp"
#include "IFormattable.hpp"
#pragma once

class classAdapter : public IFormattable, public Deck {
public:
    classAdapter();
    classAdapter(Deck& deck);
    string format() const override;
};
