// build.gradle.kts (Project-level)

plugins {
    kotlin("jvm") version "2.0.20-RC"
    id("com.android.application") version "8.5.2" apply false
    id("com.android.library") version "8.5.2" apply false
}

    subprojects {
    delete("build")
}

buildscript {
    repositories {
        google()
        mavenCentral()
    }
    dependencies {
        classpath(libs.gradle) // or the latest stable version
        classpath(libs.kotlin.gradle.plugin.v190) // Ensure this matches your Kotlin version
    }
}

allprojects {
    repositories {
        google()
        mavenCentral()
    }
}