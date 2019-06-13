package com.wjx.android.ndksummary;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        //打开对应库
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(String.valueOf(myAddFromJNI()));
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     * MainActivity.java 关联 so 库中方法
     * 默认去查找一个以Java包名+方法名的方法 就会去查找Java_com_wjx_android_ndksummary_MainActivity_stringFromJNI方法
     */
    public native String stringFromJNI();

    public native String myStringFromJNI();

    int i = 8;
    int j = 9;
    public int add(int num1, int num2){
        return num1 + num2;
    }

    public native int myAddFromJNI();
}
