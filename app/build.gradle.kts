plugins {
    id("com.android.application")
    id("org.jetbrains.kotlin.android")
}

android {
    namespace = "com.example.QuantumQuest"  // Replace with your actual package name
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.QuantumQuest"  // This should match your namespace
        minSdk = 30
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"

        // Ensure NDK version matches your setup
        ndkVersion = "26.1.10909125"
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(getDefaultProguardFile("proguard-android-optimize.txt"), "proguard-rules.pro")
        }
    }

    // Set both Java and Kotlin to target JVM 17
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }

    kotlinOptions {
        jvmTarget = "17"
    }

    externalNativeBuild {
        cmake {
            path = file("src/main/cpp/CMakeLists.txt")
            version = "3.22.1"  // Ensure this matches your installed CMake version
        }
    }
}

dependencies {
    implementation("com.google.ar:core:1.44.0")
    implementation("androidx.core:core-ktx:1.9.0")
    implementation("androidx.appcompat:appcompat:1.5.1")
    implementation("com.google.android.material:material:1.7.0")
}