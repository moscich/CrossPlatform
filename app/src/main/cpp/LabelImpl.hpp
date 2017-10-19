//
// Created by Marek Mościchowski on 19.10.2017.
//

#ifndef CPPABSTRACT_LABELIMPL_HPP
#define CPPABSTRACT_LABELIMPL_HPP


#include "lib/Label.hpp"
#include <jni.h>

class LabelImpl: public Label {
    void setText(std::string text);

public:
    LabelImpl(JNIEnv *pEnv, jobject pJobject);

private:
    jobject obj;
};


#endif //CPPABSTRACT_LABELIMPL_HPP
