// Root build.gradle.kts

plugins {
    id("com.android.application") version "8.5.2" apply false
    id("com.android.library") version "8.5.2" apply false
    id("com.google.gms.google-services") version "4.4.2" apply false
    alias(libs.plugins.orgJetbrainsKotlinAndroid) apply false
    alias(libs.plugins.composeCompiler) apply false
}
