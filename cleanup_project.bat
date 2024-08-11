@echo off
REM Navigate to the project directory
cd /d %~dp0

REM Remove duplicate LoadingActivity.kt files if found
echo Checking for duplicate LoadingActivity.kt files...
for /r %%f in (LoadingActivity.kt) do (
    echo Found: %%f
    if not "%%f"=="app\src\main\java\com\example\quantumquest\activities\LoadingActivity.kt" (
        echo Deleting duplicate: %%f
        del "%%f"
    )
)

echo Cleanup complete. Run the Python script to fix packages and imports.