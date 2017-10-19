package com.example.marekmoscichowski.myapplication;

import android.widget.TextView;

/**
 * Created by marekmoscichowski on 18.10.2017.
 */

public class Label {
    private long native_ptr = 0;

    static {
        System.loadLibrary("native-lib");
    }

    private final TextView textField;

    public Label(TextView tv) {
        this.textField = tv;
        setup();
    }

    public void setText(String text) {
        textField.setText(text);
    }

    public native void setup();
}
