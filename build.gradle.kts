// build.gradle.kts (Project-level)

plugins {
    kotlin("jvm") version "1.9.0" apply false
    id("com.android.application") version "8.5.1" apply false
    id("com.android.library") version "8.5.1" apply false
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
        classpath("com.android.tools.build:gradle:8.5.1") // or the latest stable version
        classpath("org.jetbrains.kotlin:kotlin-gradle-plugin:1.9.0") // Ensure this matches your Kotlin version
    }
}

allprojects {
    repositories {
        google()
        mavenCentral()
    }
}