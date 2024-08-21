@echo off
setlocal

:: Define paths
set "PROJECT_ROOT=C:\Users\Ziel\AndroidStudioProjects\QuantumQuest"
set "ICON_SRC=C:\Users\Ziel\AndroidStudioProjects\QuantumQuest\app\src\main\res\drawable\icon_1.png"
set "MIPMAP_DIR=%PROJECT_ROOT%\app\src\main\res\mipmap"

:: Create directories if they don't exist
mkdir "%MIPMAP_DIR%\mipmap-hdpi"
mkdir "%MIPMAP_DIR%\mipmap-mdpi"
mkdir "%MIPMAP_DIR%\mipmap-xhdpi"
mkdir "%MIPMAP_DIR%\mipmap-xxhdpi"
mkdir "%MIPMAP_DIR%\mipmap-anydpi-v26"

:: Move new icon to mipmap directories
copy "%ICON_SRC%" "%MIPMAP_DIR%\mipmap-hdpi\ic_launcher.png"
copy "%ICON_SRC%" "%MIPMAP_DIR%\mipmap-mdpi\ic_launcher.png"
copy "%ICON_SRC%" "%MIPMAP_DIR%\mipmap-xhdpi\ic_launcher.png"
copy "%ICON_SRC%" "%MIPMAP_DIR%\mipmap-xxhdpi\ic_launcher.png"

:: Create adaptive icon XML if necessary
set "ADAPTIVE_ICON_XML=%MIPMAP_DIR%\mipmap-anydpi-v26\ic_launcher.xml"
(
echo ^<?xml version="1.0" encoding="utf-8"?^>
echo ^<adaptive-icon xmlns:android="http://schemas.android.com/apk/res/android"^>
echo ^<background android:drawable="@drawable/ic_launcher_background"/^>
echo ^<foreground android:drawable="@drawable/ic_launcher_foreground"/^>
echo ^</adaptive-icon^>
) > "%ADAPTIVE_ICON_XML%"

echo Icons updated successfully!

endlocal
