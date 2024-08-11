package com.example.quantumquest;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.VideoView;

public class AspectRatioVideoView extends VideoView {

    public AspectRatioVideoView(Context context) {
        super(context);
    }

    public AspectRatioVideoView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public AspectRatioVideoView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        int width = getDefaultSize(0, widthMeasureSpec);
        int height = getDefaultSize(0, heightMeasureSpec);

        // Calculate aspect ratio
        float aspectRatio = 1.7647f; // Example aspect ratio (width / height)

        if (width > 0 && height > 0) {
            if (width < height * aspectRatio) {
                width = (int) (height * aspectRatio);
            } else {
                height = (int) (width / aspectRatio);
            }
        }

        setMeasuredDimension(width, height);
    }
}