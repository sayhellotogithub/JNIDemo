#include <jni.h>
#include <android/log.h>
#include "TemControl.h"
#include "com_iblogstreet_temcontrol_MainActivity.h"

#define LOG_TAG "temcontrol"
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
int flag = 0;
/*
 * Class:     com_iblogstreet_temcontrol_MainActivity
 * Method:    startTem
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_iblogstreet_temcontrol_MainActivity_startTem
(JNIEnv* env,jobject obj){
LOGI("%s", "startTem");

jclass clazz = (*env)->FindClass(env, "com/iblogstreet/temcontrol/MainActivity");
//jmethodID GetMethodID(JNIEnv *env, jclass clazz,
//const char *name, const char *sig);
// public void setCurrentProgress(int);descriptor: (I)V
jint tem = getTem();
flag = 1;
while(flag){

    LOGD(" tem %d", tem);
    jmethodID methodId = (*env)->GetMethodID(env, clazz, "setCurrentProgress", "(I)V");
    //  void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->
    CallVoidMethod(env, obj, methodId, getTem());
    sleep(1);
}

}

/*
 * Class:     com_iblogstreet_temcontrol_MainActivity
 * Method:    stopTem
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_iblogstreet_temcontrol_MainActivity_stopTem
(JNIEnv
* env,
jobject obj
){
flag = 0;
LOGI("%s", "stopTem");
}
