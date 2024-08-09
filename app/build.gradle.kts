import org.gradle.internal.impldep.com.amazonaws.PredefinedClientConfigurations.defaultConfig
import org.gradle.internal.impldep.com.jcraft.jsch.ConfigRepository.defaultConfig

plugins {
    id("com.android.application")
    kotlin("android")
    kotlin("kapt") // if you are using Kotlin annotation processing
}

android {
    namespace = "com.example.quantumquest" // Corrected
    compileSdk = 34 // Corrected

    defaultConfig {
        applicationId = "com.example.quantumquest" // Corrected
        minSdk = 21 // Corrected
        targetSdk = 34 // Corrected
        versionCode = 1 // Corrected
        versionName = "1.0" // Corrected
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17 // Corrected
        targetCompatibility = JavaVersion.VERSION_17 // Corrected
    }

    kotlinOptions {
        jvmTarget = "17" // Corrected
    }

    ndkVersion = "27.0.12077973" // Corrected
}

dependencies {
    implementation(libs.androidx.core.ktx)
    implementation(libs.androidx.appcompat)
    implementation(libs.material)
    implementation(libs.androidx.ui.v168)
    implementation(libs.androidx.ui.tooling.preview.v168) // Changed to match UI version
    implementation(libs.androidx.runtime)
    implementation(libs.androidx.lifecycle.runtime.ktx.v261)
    implementation(libs.androidx.activity.compose.v172)
    implementation(libs.core)
    implementation(libs.androidx.navigation.runtime.ktx)
    implementation(libs.androidx.foundation.v168) // Match version with UI and runtime
    implementation(libs.androidx.navigation.compose)
    implementation(libs.androidx.annotation)
    testImplementation(libs.junit)
    implementation(libs.androidx.material3.v120)
    androidTestImplementation(libs.androidx.junit.v115)
    androidTestImplementation(libs.androidx.espresso.core.v351)
    androidTestImplementation(libs.ui.test.junit4) // Changed to match UI version
    debugImplementation(libs.ui.tooling) // Changed to match UI version
    debugImplementation(libs.androidx.ui.test.manifest) // Changed to match UI version
}