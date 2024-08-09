import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.VideoView;
import androidx.appcompat.app.AppCompatActivity;

import com.example.quantumquest.MainActivity;
import com.example.quantumquest.R;

public class VideoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.video_activity);  // Make sure this matches your XML file name

        VideoView videoView = findViewById(R.id.videoView);

        // Set the path to the video
        String videoPath = "android.resource://" + getPackageName() + "/" + R.raw.qqintro;  // Reference your video file here
        Uri uri = Uri.parse(videoPath);
        videoView.setVideoURI(uri);

        // Start playing the video
        videoView.start();

        // Listener to move to the next activity once the video is done
        videoView.setOnCompletionListener(mp -> {
            // After the video ends, navigate to the main game activity
            Intent intent = new Intent(VideoActivity.this, MainActivity.class);
            startActivity(intent);
            finish();
        });
    }
}