package com.example.quantumquest;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.widget.VideoView;
import androidx.appcompat.app.AppCompatActivity;

public class VideoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.video_activity);

        VideoView videoView = findViewById(R.id.videoView);
        videoView.setVideoPath("android.resource://" + getPackageName() + "/" + R.raw.qqintro);

        // Ensure the video does not repeat
        videoView.setOnCompletionListener(mp -> {
            // Transition to MainActivity when video is finished
            Intent intent = new Intent(VideoActivity.this, MainActivity.class);
            startActivity(intent);
            finish(); // Close the VideoActivity
        });

        // Handle any errors during playback
        videoView.setOnErrorListener((mp, what, extra) -> {
            // Log or handle the error
            return true;
        });

        videoView.start();
    }
}