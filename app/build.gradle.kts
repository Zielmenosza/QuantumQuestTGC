// Module-level build.gradle.kts

plugins {
    id("com.android.application")
    id("com.google.gms.google-services")
    alias(libs.plugins.orgJetbrainsKotlinAndroid)
    alias(libs.plugins.composeCompiler)
}

android {
    namespace = "com.example.quantumquest"
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.quantumquest"
        minSdk = 23
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17

        java {
            toolchain {
                languageVersion.set(JavaLanguageVersion.of(17))
            }
        }
    }

    kotlinOptions {
        jvmTarget = "17"
    }

    buildFeatures {
        compose = true
    }

    composeOptions {
        kotlinCompilerExtensionVersion = "2.0.0"
    }

    ndkVersion = "27.0.12077973"
    buildTypes {
        getByName("release") {
            signingConfig = signingConfigs.getByName("debug")
        }
    }
}

dependencies {
    implementation(libs.androidxCoreKtx)
    implementation(libs.androidxAppcompat)
    implementation(libs.googleMaterial)
    implementation(libs.googleArCore)

    // Compose
    implementation(libs.androidxComposeUi)
    implementation(libs.androidxComposeUiToolingPreview)
    implementation(libs.androidxComposeRuntime)
    implementation(libs.androidxComposeFoundation)
    implementation(libs.androidxComposeMaterial3)

    // Lifecycle
    implementation(libs.androidxLifecycleRuntimeKtx)

    // Activity
    implementation(libs.androidxActivityCompose)

    // Navigation
    implementation(libs.androidxNavigationRuntimeKtx)
    implementation(libs.androidxNavigationCompose)

    // Annotation
    implementation("androidx.annotation:annotation:1.8.2")
    implementation(libs.media3Common)

    // Import the Firebase BoM
    implementation(platform("com.google.firebase:firebase-bom:33.1.2"))

    // Add Firebase Analytics (or any other Firebase SDK)
    implementation("com.google.firebase:firebase-analytics")

    // Testing
    testImplementation(libs.junit)
    androidTestImplementation(libs.androidxTestJunit)
    androidTestImplementation(libs.androidxEspressoCore)
    androidTestImplementation(libs.androidxComposeUiTestJunit4)

    // Debug
    debugImplementation(libs.androidxComposeUiTooling)
    debugImplementation(libs.androidxComposeUiTestManifest)

    implementation("com.google.firebase:firebase-auth")
    implementation("com.google.android.gms:play-services-auth:21.2.0")
    // Firebase Authentication
    implementation("com.google.firebase:firebase-auth-ktx")
       // Facebook SDK
    implementation("com.facebook.android:facebook-android-sdk:17.0.1")
    implementation("com.facebook.android:facebook-login:17.0.1")
}