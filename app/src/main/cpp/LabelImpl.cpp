//
// Created by Marek Mościchowski on 19.10.2017.
//

#include "LabelImpl.hpp"
#include <iostream>

static JavaVM *jvm;

void LabelImpl::setText(std::string text) {

    JNIEnv *env;
    jint rs = jvm->AttachCurrentThread(&env, NULL);

    jstring jstr = env->NewStringUTF(text.c_str());
    jclass clazz = env->FindClass("com/example/marekmoscichowski/myapplication/Label");
    // Get the method that you want to call
    jmethodID messageMe = env->GetMethodID(clazz, "setText", "(Ljava/lang/String;)V");
    env->CallVoidMethod(obj, messageMe, jstr);
}

LabelImpl::LabelImpl(JNIEnv *env, jobject pJobject) {
    int status = env->GetJavaVM(&jvm);
    this->obj = env->NewGlobalRef(pJobject);
//    jint rs = (*env)->GetJavaVM(env, &jvm);
//    this->env = pEnv;
}

