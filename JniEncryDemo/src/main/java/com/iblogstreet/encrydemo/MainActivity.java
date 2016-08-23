package com.iblogstreet.encrydemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import com.iblogstreet.encrydemo.jniclass.EncryUtils;

public class MainActivity
        extends AppCompatActivity
{
    EditText mEtContent;
    TextView mTvResult;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTvResult = (TextView)findViewById(R.id.tv_result);

        mEtContent = (EditText)findViewById(R.id.et_content);
    }
    public void encode(View view){
      String result=  EncryUtils.encode(mEtContent.getText().toString().trim());
        mTvResult.setText(result+"");
    }
    public void decode(View view){
        String result=  EncryUtils.decode(mEtContent.getText().toString().trim());
        mTvResult.setText(result+"");
    }
}
