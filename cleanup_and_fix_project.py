import os
import re
import shutil

# Paths to clean up
paths_to_cleanup = [
    ".kotlin/sessions",
    "logs",
    "hs_err_pid",
    "reports",
]

# Files and patterns to remove
patterns_to_remove = [
    r"\.salive$",
    r"hs_err_pid.*\.log$",
    r"\.bat$",
    r"\.txt$"
]

# Files to review and potentially fix
kotlin_files_to_fix = [
    "app/src/main/java/com/example/quantumquest/cards/",
    "app/src/main/java/com/example/quantumquest/managers/",
    "app/src/main/java/com/example/quantumquest/duplicates/"
]

# Clean up paths
def cleanup_paths():
    for path in paths_to_cleanup:
        if os.path.exists(path):
            shutil.rmtree(path)
            print(f"Removed: {path}")

# Remove unnecessary files based on patterns
def remove_files_by_pattern(root_dir="."):
    for root, dirs, files in os.walk(root_dir):
        for file in files:
            for pattern in patterns_to_remove:
                if re.search(pattern, file):
                    file_path = os.path.join(root, file)
                    os.remove(file_path)
                    print(f"Removed: {file_path}")

# Fix common Kotlin issues
def fix_kotlin_issues():
    for kotlin_dir in kotlin_files_to_fix:
        for root, dirs, files in os.walk(kotlin_dir):
            for file in files:
                if file.endswith(".kt"):
                    file_path = os.path.join(root, file)
                    fix_kotlin_file(file_path)

def fix_kotlin_file(file_path):
    with open(file_path, "r") as file:
        content = file.read()

    # Example fixes: Remove unresolved references, fix imports
    content = re.sub(r"Unresolved reference '.*'", "", content)
    content = re.sub(r"import .*Model", "", content)
    content = re.sub(r"import .*CardModel", "import com.example.quantumquest.Model.CardModel", content)

    with open(file_path, "w") as file:
        file.write(content)
    print(f"Fixed: {file_path}")

if __name__ == "__main__":
    print("Starting project cleanup and fixes...")
    cleanup_paths()
    remove_files_by_pattern()
    fix_kotlin_issues()
    print("Project cleanup and fixes completed.")