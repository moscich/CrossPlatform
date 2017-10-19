//
// Created by Marek Mościchowski on 17.04.2017.
//

#include "EntryImpl.hpp"
#include <jni.h>

EntryImpl::EntryImpl(_JNIEnv *pEnv, _jobject *pJobject) {
    this->env = pEnv;
    this->jObject = pJobject;
}

EntryImpl::EntryImpl() {

}

void EntryImpl::textChanged(std::string string) {
    this->change(string);
}

std::string EntryImpl::text() {
    return someText;
}