#include <jni.h>
#include <string>
#include "ViewModelCpp.hpp"
#include "EntryImpl.hpp"
#include "lib/SharedViewModel.hpp"
#include "LabelImpl.hpp"

static JavaVM *jvm;


extern "C" {
JNIEXPORT void JNICALL
Java_com_example_marekmoscichowski_myapplication_MainActivity_setup(JNIEnv *env, jobject instance,
                                                                    jobject entry);
};

JNIEXPORT void JNICALL
Java_com_example_marekmoscichowski_myapplication_MainActivity_setup(JNIEnv *env, jobject instance,
                                                                    jobject entry) {

    Entry *entryCpp = new EntryImpl(env, entry);
    ViewModelCpp *viewModel = new ViewModelCpp(entryCpp);

//    const std::string string = viewModel->gogo();

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_marekmoscichowski_myapplication_Label_setup(JNIEnv *env, jobject instance) {

    jclass thisClass = env->GetObjectClass(instance);
    jfieldID fidNumber = env->GetFieldID(thisClass, "native_ptr", "J");
    LabelImpl *label = new LabelImpl(env, instance);
    env->SetLongField(instance, fidNumber, (jlong) label);

    JNIEnv *env22;
    env->GetJavaVM(&jvm);
    int res = jvm->GetEnv((void **)&env22, JNI_VERSION_1_6);
    jint rs = jvm->AttachCurrentThread(&env, NULL);
    jstring jstr = env22->NewStringUTF("HELLO BOBO");
    jclass clazz = env22->FindClass("com/example/marekmoscichowski/myapplication/Label");
    // Get the method that you want to call
    jmethodID messageMe = env22->GetMethodID(clazz, "setText", "(Ljava/lang/String;)V");
    env22->CallVoidMethod(instance, messageMe, jstr);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_marekmoscichowski_myapplication_MainViewModel_setup__Lcom_example_marekmoscichowski_myapplication_EntryI_2Lcom_example_marekmoscichowski_myapplication_Label_2(
        JNIEnv *env, jobject instance, jobject entry, jobject label) {

    jclass entryClass = env->GetObjectClass(entry);
    jfieldID entryFidNumber = env->GetFieldID(entryClass, "native_ptr", "J");
    jlong entryPointer = env->GetLongField(entry, entryFidNumber);
    EntryImpl *entryImpl = (EntryImpl *) entryPointer;

    jclass labelClass = env->GetObjectClass(label);
    jfieldID labelFidNumber = env->GetFieldID(labelClass, "native_ptr", "J");
    jlong labelPointer = env->GetLongField(label, labelFidNumber);
    LabelImpl *labelImpl = (LabelImpl *) labelPointer;

    jclass thisClass = env->GetObjectClass(instance);
    jfieldID fidNumber = env->GetFieldID(thisClass, "native_ptr", "J");
    SharedViewModel *model = new SharedViewModel(entryImpl, labelImpl);
    env->SetLongField(instance, fidNumber, (jlong) model);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_marekmoscichowski_myapplication_EntryI_setup(JNIEnv *env, jobject instance) {

    jclass thisClass = env->GetObjectClass(instance);
    jfieldID fidNumber = env->GetFieldID(thisClass, "native_ptr", "J");
    EntryImpl *entry = new EntryImpl();
    env->SetLongField(instance, fidNumber, (jlong) entry);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_marekmoscichowski_myapplication_EntryI_textChange(JNIEnv *env, jobject instance,
                                                                   jstring s_) {
    const char *s = env->GetStringUTFChars(s_, 0);

    jclass thisClass = env->GetObjectClass(instance);
    jfieldID fidNumber = env->GetFieldID(thisClass, "native_ptr", "J");
    jlong vm = env->GetLongField(instance, fidNumber);
    EntryImpl *entry = (EntryImpl *) vm;
    std::string coco = entry->text();
    entry->textChanged(s);

    env->ReleaseStringUTFChars(s_, s);
}

extern "C"
jstring
Java_com_example_marekmoscichowski_myapplication_EntryI_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}