package com.example.quantumquest

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.google.ar.core.ArCoreApk
import com.google.ar.core.Config
import com.google.ar.core.Session

class ARActivity : AppCompatActivity() {

    private lateinit var arSession: Session

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Initialize ARCore session
        if (checkARCoreSupport()) {
            setupSession()
        }
    }

    private fun checkARCoreSupport(): Boolean {
        // Check if ARCore is installed and supported
        val installStatus = ArCoreApk.getInstance().requestInstall(this, true)
        if (installStatus == ArCoreApk.InstallStatus.INSTALL_REQUESTED) {
            return false
        }

        // Check for camera permissions
        if (!CameraPermissionHelper.hasCameraPermission(this)) {
            CameraPermissionHelper.requestCameraPermission(this)
            return false
        }

        return true
    }

    private fun setupSession() {
        // Create a new ARCore session
        arSession = Session(this)

        // Configure the ARCore session
        val config = Config(arSession)
        config.updateMode = Config.UpdateMode.LATEST_CAMERA_IMAGE
        arSession.configure(config)
    }

    override fun onResume() {
        super.onResume()

        // Resume ARCore session
        if (::arSession.isInitialized) {
            arSession.resume()
        }
    }

    override fun onPause() {
        super.onPause()

        // Pause ARCore session
        if (::arSession.isInitialized) {
            arSession.pause()
        }
    }

}