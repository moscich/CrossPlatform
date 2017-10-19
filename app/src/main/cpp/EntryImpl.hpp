//
// Created by Marek Mościchowski on 17.04.2017.
//

#ifndef CPPABSTRACT_ENTRYIMPL_HPP
#define CPPABSTRACT_ENTRYIMPL_HPP


#include "lib/Entry.hpp"
#include <jni.h>

class EntryImpl: public Entry {

public:

    std::string someText;
    void textChanged(std::string string);
    std::string text();
    EntryImpl();
    EntryImpl(_JNIEnv *pEnv, _jobject *pJobject);

    _JNIEnv *env;
    _jobject *jObject;
};


#endif //CPPABSTRACT_ENTRYIMPL_HPP
