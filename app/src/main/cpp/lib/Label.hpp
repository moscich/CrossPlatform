//
//  Label.hpp
//  BareCpp
//
//  Created by Marek Mościchowski on 12.10.2017.
//  Copyright © 2017 Marek Mościchowski. All rights reserved.
//

#ifndef Label_hpp
#define Label_hpp

#include <stdio.h>
#include <string>

class Label {
public:
    virtual void setText(std::string text) {}
};

#endif /* Label_hpp */
