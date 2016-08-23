#include <jni.h>
#include <android/log.h>
#include <stdio.h>

#define LOG_TAG "JniAlipay"
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)



        void sortArray(int *arr, int len) {
    int i = 0;
    int j = 0;
    int tmp=0;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if(arr[j]<arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}

void Java_com_iblogstreet_jnialipay_JniUnits_ArrayOperator_sortArray(JNIEnv *env, jobject obj, jintArray arr) {

    //数组的长度
    jsize len = (*env)->GetArrayLength(env, arr);
    LOGD("len %d", len);
    //jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
    jint* arrs=(*env)->GetIntArrayElements(env,arr,NULL);


    //对数组进行排序
    sortArray(arrs, len);

    (*env)->ReleaseIntArrayElements(env,arr,arrs,0);
    LOGD("len %d", len);

}
//jsize GetArrayLength(JNIEnv *env, jarray array);
//  jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
// void        (*ReleaseIntArrayElements)(JNIEnv*, jintArray,jint*, jint);
