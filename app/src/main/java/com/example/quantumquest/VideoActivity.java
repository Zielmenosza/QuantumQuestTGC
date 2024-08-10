package com.example.quantumquest;

import android.content.Intent;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.WindowManager;
import android.widget.VideoView;
import androidx.appcompat.app.AppCompatActivity;

public class VideoActivity extends AppCompatActivity {

    private VideoView videoView;
    private boolean assetsLoaded = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Enable fullscreen mode
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.video_activity);

        videoView = findViewById(R.id.videoView);

        // Load and start the video
        Uri videoUri = Uri.parse("android.resource://" + getPackageName() + "/" + R.raw.qq_intro);
        videoView.setVideoURI(videoUri);

        // Set up an OnCompletionListener to transition to MainActivity after video ends
        videoView.setOnCompletionListener(mp -> {
            if (assetsLoaded) {
                goToMainActivity();
            }
        });

        videoView.start();  // Start the video playback

        // Start loading assets in the background
        new LoadAssetsTask().execute();
    }

    private class LoadAssetsTask extends AsyncTask<Void, Void, Void> {
        @Override
        protected Void doInBackground(Void... voids) {
            // Simulate loading assets (e.g., loading textures, initializing game state, etc.)
            // Replace with actual loading code
            try {
                Thread.sleep(5000); // Simulate a 5-second load time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return null;
        }

        @Override
        protected void onPostExecute(Void aVoid) {
            assetsLoaded = true;
            if (!videoView.isPlaying()) {
                goToMainActivity();
            }
        }
    }

    // Method to transition to MainActivity
    private void goToMainActivity() {
        Intent intent = new Intent(VideoActivity.this, MainActivity.class);
        startActivity(intent);
        finish();  // Close this activity
    }
}