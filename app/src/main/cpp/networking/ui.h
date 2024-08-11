// ui.h

#ifndef UI_H
#define UI_H

#include <vector>
#include <string>
#include <memory>
#include "input_handler.h" // Assuming InputHandler and Input are defined here
#include "TextureAsset.h"  // Assuming TextureAsset class is used for texture handling

// Forward declare classes for rendering if needed
class Renderer;
class Input;

// Define a UIElement class to manage individual UI components
class UIElement {
public:
    UIElement(const std::string& name, float x, float y, float width, float height);
    ~UIElement();

    void setPosition(float x, float y);
    void setSize(float width, float height);
    void setTexture(const std::shared_ptr<TextureAsset>& texture);

    void render(Renderer& renderer) const; // Pass renderer for drawing
    void update(); // Update logic for the element
    bool containsPoint(float x, float y) const; // Utility to check if a point is within the element

    // Additional methods to manage element properties and events
    void setVisible(bool visible);
    bool isVisible() const;

private:
    std::string name_;
    float x_, y_;      // Position
    float width_, height_; // Size
    bool visible_;     // Visibility flag
    std::shared_ptr<TextureAsset> texture_; // Texture for rendering
};

// UI class for managing multiple UI elements
class UI {
public:
    UI();
    ~UI();

    void initialize(); // Setup initial UI elements
    void update();     // Update all UI elements
    void render(Renderer& renderer); // Render all UI elements

    void handleInput(const Input& input); // Handle input and interact with UI elements

    // Methods to manage UI elements
    void addElement(const std::shared_ptr<UIElement>& element);
    void removeElement(const std::string& name);
    std::shared_ptr<UIElement> getElement(const std::string& name) const;

private:
    std::vector<std::shared_ptr<UIElement>> elements_; // List of UI elements
};

#endif // UI_H