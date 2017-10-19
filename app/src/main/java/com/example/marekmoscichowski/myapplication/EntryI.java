package com.example.marekmoscichowski.myapplication;

import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.widget.EditText;

import static android.content.ContentValues.TAG;

/**
 * Created by marekmoscichowski on 14.04.2017.
 */

public class EntryI implements TextWatcher {

    private long native_ptr = 0;

    static {
        System.loadLibrary("native-lib");
    }

    public EditText editText;

    EntryI(EditText editText){

        String s = stringFromJNI();
        Log.d(TAG, "EntryI: " + s);
        this.editText = editText;
        this.editText.addTextChangedListener(this);
        this.setup();
    }

    public String text() {
        return editText.getText().toString();
    }
    public native String stringFromJNI();
    public native void setup();
    public native void textChange(String s);

    @Override
    public void beforeTextChanged(CharSequence s, int start, int count, int after) {

    }

    @Override
    public void onTextChanged(CharSequence s, int start, int before, int count) {
        this.textChange(s.toString());
    }

    @Override
    public void afterTextChanged(Editable s) {

    }
}
