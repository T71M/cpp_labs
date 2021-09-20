//
//  IShuffle.hpp
//  ex_1
//
//  Created by 71M on 31.08.2021.
//

#pragma once

#include <stdio.h>


class IShuffle {
public:
    virtual void shuffle() const = 0;
    virtual void shuffle(size_t i, size_t j) const = 0;
};
