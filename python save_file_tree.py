import os

def generate_directory_tree(root_dir, indent=''):
    tree_structure = ""
    for item in sorted(os.listdir(root_dir)):
        item_path = os.path.join(root_dir, item)
        if os.path.isdir(item_path):
            tree_structure += f"{indent}📂 {item}/\n"
            tree_structure += generate_directory_tree(item_path, indent + '    ')
        else:
            tree_structure += f"{indent}📄 {item}\n"
    return tree_structure

def save_tree_to_file(file_path, tree_structure):
    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(tree_structure)

# Run the script from the project root directory
if __name__ == "__main__":
    # Define your project root directory
    project_root = '.'
    # Define the output file path
    output_file = 'project_file_tree.txt'

    # Generate the file tree structure
    print("Generating file tree...")
    tree_structure = generate_directory_tree(project_root)
    
    # Save the tree structure to the output file
    save_tree_to_file(output_file, tree_structure)
    
    print(f"File tree saved to {output_file}")
