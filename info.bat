@echo off
set output_file=collected_info.txt

:: Create or clear the output file
echo Collecting information from the project files... > %output_file%

:: Collect layout XML files from the 'res/layout' directory
echo Layout XML files: >> %output_file%
for /r "app\src\main\res\layout" %%f in (*.xml) do type %%f >> %output_file%

:: Collect drawable resources from the 'res/drawable' directory
echo Drawable resources: >> %output_file%
dir /b /s "app\src\main\res\drawable\*.png" >> %output_file%
dir /b /s "app\src\main\res\drawable\*.xml" >> %output_file%

:: Collect app icon references from 'AndroidManifest.xml'
echo App icon reference in AndroidManifest.xml: >> %output_file%
findstr /i "android:icon" app\src\main\AndroidManifest.xml >> %output_file%

:: Collect information about main menu buttons in activities or fragments
echo Main menu button configurations in activities/fragments: >> %output_file%
findstr /i "button" app\src\main\java\com\example\quantumquest\activities\*.java >> %output_file%
findstr /i "button" app\src\main\java\com\example\quantumquest\fragments\*.java >> %output_file%

echo Information collection completed. Check %output_file% for details.
