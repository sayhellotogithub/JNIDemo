package com.iblogstreet.alipay;

import android.app.AlertDialog;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity
        extends AppCompatActivity
{
    EditText tvName;
    private EditText tvPwd;
    private EditText tvMoney;
    AlertDialog dialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tvName = (EditText) findViewById(R.id.tv_name);
        tvPwd = (EditText) findViewById(R.id.tv_pwd);
        tvMoney = (EditText) findViewById(R.id.tv_money);
    }
    public void showDialog(final String msg){
        if(dialog!=null){
            dialog.dismiss();
            dialog=null;
        }
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AlertDialog.Builder builder=new AlertDialog.Builder(MainActivity.this);
                builder.setTitle("提示");
                builder.setMessage(msg);
                dialog = builder.create();
                dialog.show();
            }
        });

    }
    public void dismissDialog(){
        dialog.dismiss();
    }


    public void pay(View view){

        final String username =tvName.getText().toString();
        final String pwd      =tvPwd.getText().toString();
        final int    money    =Integer.valueOf(tvMoney.getText().toString());
        new Thread(){
            @Override
            public void run() {
                final int result = pay(username, pwd, money);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(MainActivity.this,"result:"+result,Toast.LENGTH_SHORT).show();
                    }
                });

            }
        }.start();



    }
    public  native int pay(String username,String pwd,int money);

    static {
        System.loadLibrary("alipay");
    }
}
