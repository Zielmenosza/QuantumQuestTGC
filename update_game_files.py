import os

def generate_file_tree(root_dir, output_file):
    with open(output_file, 'w', encoding='utf-8') as f:
        for root, dirs, files in os.walk(root_dir):
            level = root.replace(root_dir, '').count(os.sep)
            indent = ' ' * 4 * level
            f.write(f"{indent}{os.path.basename(root)}/\n")
            sub_indent = ' ' * 4 * (level + 1)
            for file in files:
                f.write(f"{sub_indent}{file}\n")

# Specify the directory you want to create a file tree of
root_directory = "C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/"

# Specify the output file where the file tree will be saved
output_file = "project_file_tree.txt"

generate_file_tree(root_directory, output_file)

print(f"File tree has been written to {output_file}")