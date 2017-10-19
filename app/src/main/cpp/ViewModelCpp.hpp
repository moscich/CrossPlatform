//
// Created by Marek Mościchowski on 17.04.2017.
//

#ifndef CPPABSTRACT_VIEWMODELCPP_HPP
#define CPPABSTRACT_VIEWMODELCPP_HPP


#include "lib/Entry.hpp"

class ViewModelCpp {
public:
    ViewModelCpp(Entry *entry);
    std::string gogo();
private:
    Entry *entry;
};


#endif //CPPABSTRACT_VIEWMODELCPP_HPP
