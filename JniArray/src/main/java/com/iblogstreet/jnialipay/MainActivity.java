package com.iblogstreet.jnialipay;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

import com.iblogstreet.jnialipay.JniUnits.ArrayOperator;

public class MainActivity
        extends AppCompatActivity
{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void sort(View view){
        int[] arr={3,4,2,7,6,5,0,8,9};
        Log.e("before","arr[0]"+arr[0]);
        ArrayOperator.sortArray(arr);
        Log.e("after","arr[0]"+arr[0]);

        //Toast.makeText(this,"排序后"+arr.toString(),Toast.LENGTH_SHORT).show();
    }
}
