import pyxel

# Adjust these values as needed for your card size
width = 160
height = 240

# Define colors for your card (replace with desired colors)
border_color = 1  # Black
background_color = 7  # Light gray
text_color = 0  # Black

def draw():
    pyxel.cls(background_color)

    # Draw card border (using lines if thickness argument isn't supported)
    try:
        pyxel.rect(0, 0, width, height, border_color, thickness=2)  # Try using thickness if available
    except TypeError:
        # Fallback: Draw lines manually if thickness isn't supported
        pyxel.line(0, 0, width, 0, border_color)
        pyxel.line(0, height - 1, width, height - 1, border_color)
        pyxel.line(0, 0, 0, height, border_color)
        pyxel.line(width - 1, 0, width - 1, height, border_color)

    # Draw card title (replace with your card name)
    pyxel.text(10, 10, "Elemental Enigma", text_color)

    # Draw card art area (replace with your specific art)
    # This is a placeholder for now
    pyxel.circ(width // 2, height // 2, 30, text_color)

def update():
    pass

# Initialize Pyxel before using other Pyxel functions
pyxel.init(width, height, title="Quantum Quest Card Art")

pyxel.run(draw, update)