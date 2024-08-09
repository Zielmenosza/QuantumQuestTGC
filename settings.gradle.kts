// settings.gradle.kts

pluginManagement {
    repositories {
        gradlePluginPortal()
        google()
        mavenCentral()
        maven { url = uri("https://maven.pkg.jetbrains.space/public/p/compose/dev") } // Add this line
    }
}

dependencyResolutionManagement {
    RepositoriesMode.FAIL_ON_PROJECT_REPOS  // Or RepositoriesMode.FAIL_ON_PROJECT_REPOS to enforce
    repositories {
        google()
        mavenCentral()
        maven { url = uri("https://maven.example.com/repo") }
    }
}

rootProject.name = "QuantumQuest"
include(":app")