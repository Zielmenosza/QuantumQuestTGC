@echo off
echo Running Python script to update the project and remove duplicates...

python customize_cards_characters.py

echo Removing duplicates in CardRepository.kt and CharacterRepository.kt...
python remove_duplicates.py

echo Python script complete. Please rebuild your project.
pause