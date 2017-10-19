//
//  SharedViewModel.hpp
//  BareCpp
//
//  Created by Marek Mościchowski on 12.10.2017.
//  Copyright © 2017 Marek Mościchowski. All rights reserved.
//

#ifndef SharedViewModel_hpp
#define SharedViewModel_hpp

#include <stdio.h>
#include "Entry.hpp"
#include "Label.hpp"

class SharedViewModel {
public:
    SharedViewModel(Entry *entry, Label *label);
};

#endif /* SharedViewModel_hpp */
