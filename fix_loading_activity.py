import os

def fix_loading_activity():
    file_path = "app/src/main/java/com/example/quantumquest/LoadingActivity.kt"
    if os.path.exists(file_path):
        with open(file_path, "r") as file:
            lines = file.readlines()

        # Ensure there is only one class declaration
        class_declared = False
        updated_lines = []
        for line in lines:
            if "class LoadingActivity" in line:
                if class_declared:
                    continue
                class_declared = True
            updated_lines.append(line)

        # Replace the incorrect MainActivity reference with the correct one
        updated_lines = [
            line.replace("MainActivity", "com.example.quantumquest.activities.MainActivity")
            for line in updated_lines
        ]

        # Ensure other unresolved references are corrected
        updated_lines = [
            line.replace("val <T> KClass<T>.java: Class<T>", "MainActivity::class.java")
            for line in updated_lines
        ]

        with open(file_path, "w") as file:
            file.writelines(updated_lines)
        print(f"Updated {file_path}")

def main():
    fix_loading_activity()

if __name__ == "__main__":
    main()