// settings.gradle.kts

pluginManagement {
    repositories {
        gradlePluginPortal() // For Gradle plugins
        google()             // Google's Maven repository
        mavenCentral()       // Maven Central repository
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.PREFER_SETTINGS) // Ensure this setting
    repositories {
        google()  // Centralize Google repository declaration here
        mavenCentral()
        // Add other repositories if needed
    }
}

rootProject.name = "QuantumQuest"
include(":app")