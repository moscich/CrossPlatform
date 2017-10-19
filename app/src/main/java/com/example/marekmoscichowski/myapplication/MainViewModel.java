package com.example.marekmoscichowski.myapplication;

import android.widget.EditText;
import android.widget.TextView;

/**
 * Created by marekmoscichowski on 14.04.2017.
 */

public class MainViewModel {
    private long native_ptr = 0;

    static {
        System.loadLibrary("native-lib");
    }

    MainViewModel(EditText et, TextView tv) {
        setup(new EntryI(et), new Label(tv));
    }

    public native void setup(EntryI entry, Label label);
}
