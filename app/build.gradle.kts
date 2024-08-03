plugins {
    id("com.android.application")
    id("org.jetbrains.kotlin.android")
}

android {
    namespace = "com.example.QuantumQuest" // Add this line with your actual package name
    compileSdk = 33  // Ensure this matches your desired SDK version

    defaultConfig {
        applicationId = "com.example.QuantumQuest"  // Replace with your actual package name
        minSdk = 30
        targetSdk = 30  // Ensure this matches your desired SDK version
        versionCode = 1
        versionName = "1.0"

        ndkVersion = "26.1.10909125"  // Make sure this is consistent with your NDK installation
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(getDefaultProguardFile("proguard-android-optimize.txt"), "proguard-rules.pro")
        }
    }

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
    implementation(libs.androidx.core.ktx)
    implementation(libs.androidx.ui.v168)
    implementation(libs.androidx.material3.v120)
    implementation(libs.androidx.lifecycle.runtime.ktx.v261)
    implementation(libs.androidx.activity.compose.v172)
    implementation(libs.material)
}