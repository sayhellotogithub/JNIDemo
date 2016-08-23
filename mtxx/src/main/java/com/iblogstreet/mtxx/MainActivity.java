package com.iblogstreet.mtxx;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;

import com.mt.mtxx.image.JNI;

public class MainActivity
        extends AppCompatActivity
{
    static{
        System.loadLibrary("mtimage-jni");
    }
    private static final String TAG ="MainActivity";
    ImageView mIvSrc;
    Bitmap bitmap;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mIvSrc = (ImageView) findViewById(R.id.iv_src);

        bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.logo);
        mIvSrc.setImageBitmap(bitmap);
    }
    public void handle(View view){
        Log.e(TAG,"处理图片89");
        JNI jni=new JNI();
        int width=bitmap.getWidth();
        int height=bitmap.getHeight();
        int[] param=new int[width*height];
        bitmap.getPixels(param,0,width,0,0,width,height);
        //Native method not found: com.mt.mtxx.image.JNI.StyleElegant:([III)V
        //  public native void StyleElegant(int[] paramArrayOfInt, int paramInt1, int paramInt2);
        jni.StyleElegant(param,width,height);
        //jni.StyleLomoB(param,width,height);
        Bitmap newbitmap=Bitmap.createBitmap(param,width,height,bitmap.getConfig());
        mIvSrc.setImageBitmap(newbitmap);

    }
}
