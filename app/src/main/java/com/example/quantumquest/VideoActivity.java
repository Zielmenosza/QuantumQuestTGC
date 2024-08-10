package com.example.quantumquest;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.Gravity;
import android.widget.FrameLayout;
import android.widget.VideoView;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.view.WindowCompat;

public class VideoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Enable fullscreen mode
        WindowCompat.setDecorFitsSystemWindows(getWindow(), false);
        setContentView(R.layout.video_activity);

        VideoView videoView = findViewById(R.id.videoView);
        FrameLayout.LayoutParams layoutParams = new FrameLayout.LayoutParams(
                FrameLayout.LayoutParams.MATCH_PARENT,
                FrameLayout.LayoutParams.MATCH_PARENT);
        layoutParams.gravity = Gravity.CENTER;
        videoView.setLayoutParams(layoutParams);

        Uri videoUri = Uri.parse("android.resource://" + getPackageName() + "/" + R.raw.qq_intro);
        videoView.setVideoURI(videoUri);

        // Set the video to not loop
        videoView.setOnPreparedListener(mp -> {
            mp.setLooping(false);
            videoView.start();
        });

        // Start loading assets while the video plays
        loadGameAssets(() -> {
            // Transition to MainActivity after the video ends or after loading is done
            videoView.setOnCompletionListener(mp -> {
                videoView.stopPlayback();
                Intent intent = new Intent(VideoActivity.this, MainActivity.class);
                startActivity(intent);
                finish();
            });

            // Alternatively, move to MainActivity once loading is done (even if the video is still playing)
            new Handler(Looper.getMainLooper()).postDelayed(() -> {
                if (!isFinishing()) {
                    videoView.stopPlayback();
                    Intent intent = new Intent(VideoActivity.this, MainActivity.class);
                    startActivity(intent);
                    finish();
                }
            }, 1000); // Adjust timing as needed
        });
    }

    private void loadGameAssets(Runnable onComplete) {
        // Simulate loading with a delay
        new Handler(Looper.getMainLooper()).postDelayed(onComplete, 3000); // 3 seconds delay
    }
}