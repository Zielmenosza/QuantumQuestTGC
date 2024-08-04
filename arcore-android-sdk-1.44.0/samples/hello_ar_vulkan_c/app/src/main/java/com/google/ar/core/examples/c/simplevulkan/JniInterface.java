/*
 * Copyright 2019 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.google.ar.core.examples.c.simplevulkan;

import android.app.Activity;
import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLUtils;
import android.util.Log;
import android.view.Surface;
import java.io.IOException;

/** JNI interface to native layer. */
public class JniInterface {
  static {
    System.loadLibrary("simple_vulkan_native");
  }

  private static final String TAG = "JniInterface";
  static AssetManager assetManager;

  public static native long createNativeApplication(AssetManager assetManager);

  public static native void destroyNativeApplication(long nativeApplication);

  public static native void onPause(long nativeApplication);

  public static native void onResume(long nativeApplication, Context context, Activity activity);

  /** Allocate resources for rendering. */
  public static native void onSurfaceCreated(long nativeApplication, Surface surface);

  /** Called when the view port width, height, or display rotation may have changed. */
  public static native void onDisplayGeometryChanged(
      long nativeApplication, int displayRotation, int width, int height);

  /** Main render loop. */
  public static native void onSurfaceDrawFrame(long nativeApplication);

  public static Bitmap loadImage(String imageName) {

    try {
      return BitmapFactory.decodeStream(assetManager.open(imageName));
    } catch (IOException e) {
      Log.e(TAG, "Cannot open image " + imageName);
      return null;
    }
  }

  public static void loadTexture(int target, Bitmap bitmap) {
    GLUtils.texImage2D(target, 0, bitmap, 0);
  }
}
