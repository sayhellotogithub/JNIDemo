package com.iblogstreet.jnialipay.JniUnits;

/*
 *  @项目名：  JniAlipay 
 *  @包名：    com.iblogstreet.jnialipay.JniUnits
 *  @文件名:   ArrayOperator
 *  @创建者:   Army
 *  @创建时间:  2016/8/21 18:23
 *  @描述：    Java与C交换数组，Java中有一个数组，交给C来排序，C排完序后，将其返回
 */
public class ArrayOperator {
    private static final String TAG = "ArrayOperator";
    public  static native void sortArray(int[] arr);
    static{
        System.loadLibrary("array");
    }

}
