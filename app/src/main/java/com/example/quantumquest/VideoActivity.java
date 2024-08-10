package com.example.quantumquest;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.VideoView;
import androidx.appcompat.app.AppCompatActivity;

public class VideoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.video_activity);

        VideoView videoView = findViewById(R.id.videoView);
        Uri videoUri = Uri.parse("android.resource://" + getPackageName() + "/" + R.raw.qq_intro);
        videoView.setVideoURI(videoUri);

        videoView.setOnCompletionListener(mp -> {
            // Transition to the main activity once the video finishes
            Intent intent = new Intent(VideoActivity.this, MainActivity.class);
            startActivity(intent);
            finish(); // Close the VideoActivity
        });

        videoView.start();
    }
}