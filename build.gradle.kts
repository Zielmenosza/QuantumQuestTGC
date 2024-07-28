// build.gradle.kts (Project-level)

plugins {
    // Add these plugins to the project-level build file
    id("com.android.application") version "8.1.4" apply false
    id("org.jetbrains.kotlin.android") version "2.0.0" apply false
    alias(libs.plugins.compose.compiler) apply false
}

buildscript {
    dependencies {
        classpath(libs.gradle)
        classpath(libs.kotlin.gradle.plugin)
    }
}
val myBuildDir: File = layout.buildDirectory.get().asFile