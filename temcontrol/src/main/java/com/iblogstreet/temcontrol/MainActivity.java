package com.iblogstreet.temcontrol;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.TextView;

/**
 * 需求，根据第三方提供的C来进行温度控制
 * 其中有开启，和停止，及实时温度显示
 */
public class MainActivity
        extends AppCompatActivity
{
    static{
        System.loadLibrary("tem");
    }
    TextView tvTem;
    ProgressBar progressBar;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
         tvTem= (TextView) findViewById(R.id.tvTem);
         progressBar = (ProgressBar) findViewById(R.id.progressBar);
        progressBar.setMax(50);
    }
    int currenttem=0;
    public void start(View view){
        new Thread(){
            @Override
            public void run() {
                startTem();

            }
        }.start();

    }
    public void stop(View view){
        stopTem();
    }

    /**
     * 这个方法可以让C调用
     * @param tem
     */
    public void setCurrentProgress(final int tem){

        progressBar.setProgress(tem);
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                tvTem.setText(tem+"");
            }
        });
    }
    public native void startTem();
    public native void stopTem();
}
