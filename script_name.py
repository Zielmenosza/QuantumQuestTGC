import os

# Path to the Model directory
model_dir = os.path.join("app", "src", "main", "java", "com", "example", "quantumquest", "Model")

def check_card_model():
    card_model_path = os.path.join(model_dir, "CardModel.kt")
    
    if not os.path.exists(card_model_path):
        print(f"Error: CardModel.kt not found in {model_dir}.")
        return False
    
    with open(card_model_path, "r") as file:
        content = file.read()

    required_properties = ["val name: String", "val cost: Int", "val description: String"]

    for prop in required_properties:
        if prop not in content:
            print(f"Error: '{prop}' not found in CardModel.kt.")
            return False

    print("CardModel.kt is present and has the required properties.")
    return True

if __name__ == "__main__":
    if not os.path.exists(model_dir):
        print(f"Error: Model directory not found at {model_dir}. Please check your file structure.")
    else:
        check_card_model()