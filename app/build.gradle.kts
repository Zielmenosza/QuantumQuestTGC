// build.gradle.kts (App-level)

    plugins {
        id("com.android.application")
        id("kotlin-android")
        id("org.jetbrains.kotlin.android")
        alias(libs.plugins.compose.compiler)
    }

android {
    namespace = "com.example.quantumquest"
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.quantumquest"
        minSdk = 26
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        vectorDrawables {
            useSupportLibrary = true
        }
    }

    buildTypes {
        release {isMinifyEnabled = true
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
            signingConfig = signingConfigs.getByName("debug")
        }
    }
    compileOptions {
        sourceCompatibility(JavaVersion.VERSION_11)
        targetCompatibility(JavaVersion.VERSION_11)
    }

    kotlinOptions {
        jvmTarget = "11"
    }
    buildFeatures {
        compose = true
    }

    composeOptions {
        kotlinCompilerExtensionVersion = "1.4.3"
    }
    buildToolsVersion = "34.0.0"
    ndkVersion = "26.1.10909125"
}

dependencies {
    implementation(libs.androidx.core.ktx)
    implementation(libs.androidx.lifecycle.runtime.ktx.v261)
    implementation(libs.androidx.activity.compose.v172)
    implementation(platform(libs.compose.bom))
    implementation(libs.kotlin.stdlib.jdk8)
    implementation(libs.ui)
    implementation(libs.androidx.ui.graphics)
    implementation(libs.ui.tooling.preview)
    implementation(libs.androidx.material3.v120)
    testImplementation(libs.junit)
    androidTestImplementation(libs.androidx.junit.v115)
    androidTestImplementation(libs.androidx.espresso.core.v351)
    androidTestImplementation(platform(libs.compose.bom))
    androidTestImplementation(libs.androidx.ui.test.junit4)
    androidTestImplementation(libs.junit.junit)
    debugImplementation(libs.androidx.ui.tooling)
    debugImplementation(libs.androidx.ui.test.manifest)
}
