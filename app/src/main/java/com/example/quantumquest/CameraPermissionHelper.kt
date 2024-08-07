package com.example.quantumquest

import android.Manifest
import android.app.Activity
import android.content.pm.PackageManager
import androidx.core.app.ActivityCompat

object CameraPermissionHelper {
    private const val CAMERA_PERMISSION_CODE = 1
    private const val CAMERA_PERMISSION = Manifest.permission.CAMERA

    fun hasCameraPermission(activity: Activity): Boolean {
        return ActivityCompat.checkSelfPermission(activity, CAMERA_PERMISSION) == PackageManager.PERMISSION_GRANTED
    }

    fun requestCameraPermission(activity: Activity) {
        ActivityCompat.requestPermissions(activity, arrayOf(CAMERA_PERMISSION), CAMERA_PERMISSION_CODE)
    }
}