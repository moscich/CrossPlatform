//
//  SharedViewModel.cpp
//  BareCpp
//
//  Created by Marek Mościchowski on 12.10.2017.
//  Copyright © 2017 Marek Mościchowski. All rights reserved.
//

#include "SharedViewModel.hpp"


SharedViewModel::SharedViewModel(Entry *entry, Label *label) {
    entry->change = [this, label](const std::string &message) {
        std::string result = "";
        for(int i = int(message.length() -1) ; i>=0 ; i--) {
            char c = message[i]; //this is your character
            result += c;
        }
        label->setText(result);
    };
}
