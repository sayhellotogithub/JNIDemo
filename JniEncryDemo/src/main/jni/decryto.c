//
// Created by Army on 2016/8/20.
//
#include <jni.h>
#include <stdlib.h>//用于malloc/free
char * toParseCode(char * s){
    char *p=s;
    char *q=s;
    char tmp='\n';
    while(*q!='\0'){
        q++;
    }
    q--;
    while(p<q){
        tmp=*p;
        *p=*q;
        *q=tmp;
        p++;
        q--;
    }
    return s;
}

//将字符串转置
jstring Java_com_iblogstreet_encrydemo_jniclass_EncryUtils_encode(JNIEnv *env,jobject obj,jstring content){

    //jsize       (*GetStringLength)(JNIEnv*, jstring);
   // jsize       (*GetStringUTFLength)(JNIEnv*, jstring);
//    void        (*GetStringRegion)(JNIEnv*, jstring, jsize, jsize, jchar*);
//    void        (*GetStringUTFRegion)(JNIEnv*, jstring, jsize, jsize, char*);
//    jstring NewStringUTF(const char* bytes)
//    { return functions->NewStringUTF(this, bytes); }
    jsize len=(*env)->GetStringLength(env,content);
    char *ptr=(char *) malloc(len+1);//这里要加1，注意字符串的结束符'\0'
    ptr[len]='\0';
    //将字符串转换成字符数组
    (*env)->GetStringUTFRegion(env,content,0,len,ptr);
    ptr=toParseCode(ptr);
    jstring str=(*env)->NewStringUTF(env,ptr);
    free(ptr);
    ptr=NULL;
    return str;
}
jstring Java_com_iblogstreet_encrydemo_jniclass_EncryUtils_decode(JNIEnv *env,jobject obj,jstring content){
    jsize len=(*env)->GetStringLength(env,content);
    char *ptr=(char *) malloc(len+1);//这里要加1，注意字符串的结束符'\0'
    ptr[len]='\0';
    //将字符串转换成字符数组
    (*env)->GetStringUTFRegion(env,content,0,len,ptr);
    ptr=toParseCode(ptr);
    jstring str=(*env)->NewStringUTF(env,ptr);
    free(ptr);
    ptr=NULL;
    return str;
}

