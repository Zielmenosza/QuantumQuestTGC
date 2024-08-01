// build.gradle.kts (Project-level)

plugins {
    // Android application plugin and Kotlin Android plugin
    id("com.android.application") version "8.1.4" apply false
    id("org.jetbrains.kotlin.android") version "2.0.0" apply false
    alias(libs.plugins.compose.compiler) apply false // Using version catalogs
}

buildscript {
    dependencies {
        classpath(libs.gradle) // Reference to Gradle version in version catalog
        classpath(libs.kotlin.gradle.plugin) // Kotlin Gradle plugin
    }
}

// If you have additional subprojects or custom tasks, you can define them here

// Example of defining a global directory for builds
val myBuildDir: File = layout.buildDirectory.get().asFile

// Optional: Custom task to print the build directory
tasks.register("printBuildDir") {
    doLast {
        println("Build directory: $myBuildDir")
    }
}