#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/textbox.h>
#include "Toolbar.h"
#include "Canvas.h"
#include "ColorSelector.h"

class Application : public bobcat::Application_ {
    // UI components
    bobcat::Window* window;
    Toolbar* toolbar;
    Canvas* canvas;
    ColorSelector* colorSelector;
    
    // States dragging operations
    float lastX;
    float lastY;

    // Event handlers
    void onCanvasMouseDown(bobcat::Widget* sender, float mx, float my);
    void onCanvasDrag(bobcat::Widget* sender, float mx, float my);
    void onCanvasMouseUp(bobcat::Widget* sender, float mx, float my);
    void onToolbarChange(bobcat::Widget* sender);
    void onColorChange(bobcat::Widget* sender);

public:
    // Constructor that sets up the widgets and registers callbacks
    Application();
    
    friend struct::AppTest;
};

#endif
