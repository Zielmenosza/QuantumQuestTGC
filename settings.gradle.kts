// settings.gradle.kts

pluginManagement {
    repositories {
        gradlePluginPortal() // Required for Gradle plugins
        google()             // Google's Maven repository
        mavenCentral()       // Maven Central repository
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        google()
        mavenCentral()
    }
}

rootProject.name = "QuantumQuest"
include(":app", ":arcore_client")