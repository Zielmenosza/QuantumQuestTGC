@echo off
:: Set the base directory of your project
set BASE_DIR=C:\Users\Ziel\AndroidStudioProjects\QuantumQuest\app\src\main\java\com\example\quantumquest

:: Verify and move Card related files
if exist "%BASE_DIR%\cards\Card.kt" (
    echo Card.kt exists
) else (
    echo Missing Card.kt, checking for backup...
    if exist "%BASE_DIR%\cards\Card_backup.kt" (
        echo Found backup, renaming...
        ren "%BASE_DIR%\cards\Card_backup.kt" Card.kt
    ) else (
        echo Card.kt not found and no backup available.
    )
)

:: Repeat for other classes
if exist "%BASE_DIR%\cards\CharacterCard.kt" (
    echo CharacterCard.kt exists
) else (
    echo Missing CharacterCard.kt, creating...
    echo class CharacterCard { } > "%BASE_DIR%\cards\CharacterCard.kt"
)

:: Continue for other classes as needed...

echo Batch script complete. Running Python script for further fixes...
python fix_kotlin_classes.py