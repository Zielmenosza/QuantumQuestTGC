// settings.gradle.kts

pluginManagement {
    repositories {
        gradlePluginPortal() // For Gradle plugins
        google()             // Google's Maven repository
        mavenCentral()       // Maven Central repository
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.PREFER_PROJECT)  // Or RepositoriesMode.FAIL_ON_PROJECT_REPOS to enforce
    repositories {
        google()
        mavenCentral()
        maven { url = uri("https://maven.example.com/repo") }
    }
}

rootProject.name = "QuantumQuest"
include(":app")