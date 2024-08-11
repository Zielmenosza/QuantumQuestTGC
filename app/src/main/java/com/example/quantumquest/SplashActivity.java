package com.example.quantumquest;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import androidx.appcompat.app.AppCompatActivity;

public class SplashActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        // Delay for the splash screen
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                // Start the VideoActivity
                Intent intent = new Intent(SplashActivity.this, VideoActivity.class);
                startActivity(intent);
                finish(); // Close the SplashActivity
            }
        }, 3000); // 3 seconds delay
    }
}