//
//  Entry.hpp
//  BareCpp
//
//  Created by Marek Mościchowski on 12.10.2017.
//  Copyright © 2017 Marek Mościchowski. All rights reserved.
//

#ifndef Entry_hpp
#define Entry_hpp

#include <stdio.h>
#include <functional>

class Entry {
public:
    std::function<void (const std::string&)> change;
};

#endif /* Entry_hpp */
