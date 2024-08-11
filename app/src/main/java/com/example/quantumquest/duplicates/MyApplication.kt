package com.example.quantumquest

import android.app.Application
import com.facebook.FacebookSdk
import com.google.firebase.FirebaseApp

class MyApplication : Application() {
    override fun onCreate() {
        super.onCreate()
        FirebaseApp.initializeApp(this)
        FacebookSdk.sdkInitialize(applicationContext)
    }
}