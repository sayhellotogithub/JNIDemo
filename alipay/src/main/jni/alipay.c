#include <jni.h>
#include "com_iblogstreet_alipay_pay_Payment.h"
#include <android/log.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LOG_TAG "alipay"

#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
void showJavaDialog(JNIEnv *env, jobject obj,char * msg){
    //如用户密码验证成功
    //jclass FindClass(JNIEnv *env, const char *name);
    //char *name是方法的类名全路径
    jclass clazz=(*env)->FindClass(env,"com/iblogstreet/alipay/MainActivity");
    //jmethodID GetMethodID(JNIEnv *env, jclass clazz,const char *name, const char *sig);
    //---->name 是方法名 char *sig 是方法签名
    // public void showDialog(java.lang.String);    descriptor: (Ljava/lang/String;)V
    //public void dismissDialog();    descriptor: ()V
    jmethodID methodId=(*env)->GetMethodID(env,clazz,"showDialog","(Ljava/lang/String;)V");
    //NativeType Call<type>Method(JNIEnv *env, jobject obj,jmethodID methodID, ...);
    (*env)->CallVoidMethod(env,obj,methodId,(*env)->NewStringUTF(env,msg));
}
void dismissJavaDialog(JNIEnv *env, jobject obj){
    //如用户密码验证成功
    //jclass FindClass(JNIEnv *env, const char *name);
    //char *name是方法的类名全路径
    jclass clazz=(*env)->FindClass(env,"com/iblogstreet/alipay/MainActivity");
    //jmethodID GetMethodID(JNIEnv *env, jclass clazz,const char *name, const char *sig);
    //---->name 是方法名 char *sig 是方法签名,通过javap -classpath .-s 包名及类型命令可以得到
    // public void showDialog(java.lang.String);    descriptor: (Ljava/lang/String;)V
    //public void dismissDialog();    descriptor: ()V
    jmethodID methodId=(*env)->GetMethodID(env,clazz,"dismissDialog","()V");
    //NativeType Call<type>Method(JNIEnv *env, jobject obj,jmethodID methodID, ...);
    (*env)->CallVoidMethod(env,obj,methodId);
}

JNIEXPORT jint JNICALL Java_com_iblogstreet_alipay_MainActivity_pay
        (JNIEnv *env, jobject obj, jstring name, jstring pwd, jint money) {
    //账号为admin 密码为 123 余额为1000
    //100为支付成功，101为登录失败,102 余额不足
    //支付之前有检查，如用户密码验证
    //支付环境检查
    LOGD("admin %s ", name);
    LOGD("pwd %s ", pwd);
    LOGD("money %d", money);
    // jsize GetStringLength(JNIEnv *env, jstring string);
    jsize len = (*env)->GetStringLength(env, name);
    LOGD("len %d ", len);
    //给name分配空间
    char *nameBuf = (char *) malloc(len + 1);
    nameBuf[len] = '\0';
    (*env)->GetStringUTFRegion(env, name, 0, len, nameBuf);
    len = (*env)->GetStringLength(env, pwd);
    LOGD("len %d ", len);
    char *pwdBuf = (char *) malloc(len + 1);
    pwdBuf[len] = '\0';
    (*env)->GetStringUTFRegion(env, pwd, 0, len, pwdBuf);
    showJavaDialog(env,obj,"用户密码验证成功");
    sleep(2);
    showJavaDialog(env,obj,"正在扫描系统环境");
    sleep(2);
    dismissJavaDialog(env,obj);
    //void GetStringUTFRegion(JNIEnv *env, jstring str, jsize start, jsize len, char *buf);

//    //如用户密码验证成功
//    //jclass FindClass(JNIEnv *env, const char *name);
//    //char *name是方法的类名全路径
//    jclass clazz=(*env)->FindClass(env,"com/iblogstreet/alipay/MainActivity");
//    //jmethodID GetMethodID(JNIEnv *env, jclass clazz,const char *name, const char *sig);
//    //---->name 是方法名 char *sig 是方法签名
//    // public void showDialog(java.lang.String);    descriptor: (Ljava/lang/String;)V
//    //public void dismissDialog();    descriptor: ()V
//    jmethodID methodId=(*env)->GetMethodID(env,clazz,"showDialog","(Ljava/lang/String;)V");
//    //NativeType Call<type>Method(JNIEnv *env, jobject obj,jmethodID methodID, ...);
//    (*env)->CallVoidMethod(env,obj,methodId,(*env)->NewStringUTF(env,"用户密码验证成功"));
//    sleep(2);
//    (*env)->CallVoidMethod(env,obj,methodId,(*env)->NewStringUTF(env,"正在扫描系统环境"));
//    sleep(2);
    int result = 0;
    if (strcmp(nameBuf, "admin") == 0 && strcmp(pwdBuf, "123") == 0) {
        if (money > 1000)
            result = 102;
        else {
            result = 100;
        }
    } else {
        result = 101;
    }
    free(nameBuf);
    free(pwdBuf);
    nameBuf = NULL;
    pwdBuf = NULL;
    LOGD("money %d", 101);

    return result;
}
