package com.iblogstreet.encrydemo.jniclass;

/*
 *  @项目名：  EncryDemo 
 *  @包名：    com.iblogstreet.encrydemo.jniclass
 *  @文件名:   EncryUtils
 *  @创建者:   Army
 *  @创建时间:  2016/8/20 17:52
 *  @描述：    用于加解密的类
 */
public class EncryUtils {
    private static final String TAG = "EncryUtils";
    public static native String encode(String content);
    public static native  String decode(String content);
    static{
        System.loadLibrary("encodeLib");
    }
}
