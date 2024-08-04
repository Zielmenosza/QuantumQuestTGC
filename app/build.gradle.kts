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
    androidTestImplementation ("androidx.test.ext:junit:1.2.1") // Or latest version
    androidTestImplementation ("androidx.test.espresso:espresso-core:3.6.1") // Or latest version
    testImplementation ("junit:junit:4.13.2") // Or latest version
    implementation("androidx.core:core-ktx:1.13.1")
    implementation("androidx.appcompat:appcompat:1.7.0")
    implementation("com.google.android.material:material:1.12.0")
    implementation(libs.androidx.ui.android)
    implementation(libs.androidx.material3.android)
}