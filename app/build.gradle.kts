plugins {
    id("com.android.application")
    kotlin("android")
    kotlin("kapt") // if you are using Kotlinannotation processing
}

android {
    namespace = "com.example.quantumquest" // Add the namespace here
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.quantumquest"
        minSdk = 21
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }

    kotlinOptions {
        jvmTarget ="17"
    }
}

dependencies {
    implementation("androidx.core:core-ktx:1.13.1")
    implementation("androidx.appcompat:appcompat:1.7.0")
    implementation("com.google.android.material:material:1.12.0")
    implementation("androidx.compose.ui:ui:1.6.8")
    implementation("androidx.compose.ui:ui-tooling-preview:1.6.8")
    implementation("androidx.compose.runtime:runtime:1.6.8")
    implementation("androidx.lifecycle:lifecycle-runtime-ktx:2.8.4")
    implementation("androidx.activity:activity-compose:1.9.1")
    implementation("com.google.ar:core:1.44.0")
    implementation("androidx.navigation:navigation-runtime-ktx:2.8.0")
    implementation("androidx.compose.foundation:foundation:1.6.8")
    implementation("androidx.navigation:navigation-compose:2.8.0")
    testImplementation("junit:junit:4.13.2")
    implementation("androidx.compose.material3:material3:1.2.0")
    androidTestImplementation("androidx.test.ext:junit:1.2.1")
    androidTestImplementation("androidx.test.espresso:espresso-core:3.6.1")
    androidTestImplementation("androidx.compose.ui:ui-test-junit4:1.6.8")
    debugImplementation("androidx.compose.ui:ui-tooling:1.6.8")
    debugImplementation("androidx.compose.ui:ui-test-manifest:1.6.8")
}