// settings.gradle.kts

pluginManagement {
    repositories {
        gradlePluginPortal() // Required for Gradle plugins
        google()             // Google's Maven repository
        mavenCentral()       // Maven Central repository
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS) // Ensures repositories are only defined here
    repositories {
        google()             // Google's Maven repository
        mavenCentral()       // Maven Central repository
    }
}

rootProject.name = "QuantumQuest"
include(":app")