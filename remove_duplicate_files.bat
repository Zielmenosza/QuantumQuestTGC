@echo off
setlocal enabledelayedexpansion

REM Set the directory to search for duplicates
set "root_dir=C:\Users\Ziel\AndroidStudioProjects\QuantumQuest"

REM Create an empty file to track unique files
set "file_list=%temp%\file_list.txt"
if exist "%file_list%" del "%file_list%"

REM Function to process files
:process_files
for /r "%root_dir%" %%f in (*.kt) do (
    REM Extract the file name
    set "file_name=%%~nxf"

    REM Check if the file name is already in the list
    findstr /i /c:"!file_name!" "%file_list%" >nul
    if !errorlevel! equ 1 (
        REM If not found, add it to the list
        echo !file_name! >> "%file_list%"
    ) else (
        REM If found, delete the duplicate file
        echo Deleting duplicate file: %%f
        del "%%f"
    )
)

REM Clean up
if exist "%file_list%" del "%file_list%"

echo Duplicate files have been removed.
pause
