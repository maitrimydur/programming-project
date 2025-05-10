#include "Application.h"
#include "Color.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/textbox.h>

using namespace bobcat;

// Called when the mouse is pressed down on the Canvas
void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    // Determines the current tool and color
    TOOL tool = toolbar -> getTool();
    Color color = colorSelector -> getColor();

    // Handles each type of tool
    if (tool == PENCIL) {
        // Starts a new scribble at (mx, my) position
        canvas -> startScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        colorSelector -> updateRGBInputs();
    }
    else if (tool == ERASER) {
        // Removes any shape/scribble that is under the cursor
        canvas -> eraseAt(mx, my);
    }
    else if (tool == SELECT) {
        // Selects the shape/scribble that is under the cursor
        canvas -> selectAt(mx, my);
    }
    else if (tool == RECTANGLE) {
        // Adds a new rectangle at (mx, my) position
        canvas -> addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        colorSelector -> updateRGBInputs();
    }
    else if (tool == CIRCLE) {
        // Adds a new circle at (mx, my) position
        canvas -> addCircle(mx, my, color.getR(), color.getG(), color.getB());
        colorSelector -> updateRGBInputs();
    }
    else if (tool == TRIANGLE) {
        // Adds a new triangle at (mx, my) position
        canvas -> addTriangle(mx, my, color.getR(), color.getG(), color.getB());
        colorSelector -> updateRGBInputs();
    }
    else if (tool == POLYGON) {
        // Adds a new polygon at (mx, my) posiiton
        canvas -> addPolygon(mx, my, color.getR(), color.getG(), color.getB());
        colorSelector -> updateRGBInputs();
    }

    // Saves the last coordinates of the mouse for drag events
    lastX = mx;
    lastY = my;

    // Redraws the canvas to be able to show changes
    canvas -> redraw();
}

// Called when the mouse is dragged while it is moved pressed
void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar -> getTool();
    Color color = colorSelector -> getColor();

    if (tool == PENCIL) {
        // Continues to add points to the current scribble
        canvas -> addToScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
    }
    else if (tool == ERASER) {
        // Keeps erasing under the cursor 
        canvas -> eraseAt(mx, my);
    }
    else if (tool == SELECT) {
        // Moves the selected object by the delta of the mouse
        float dx = mx - lastX;
        float dy = my - lastY;
        canvas -> moveSelected(dx, dy);
    }

    // Updates the last positions and redraws based on it
    lastX = mx;
    lastY = my;
    canvas -> redraw();
}

// Called when the mouse button is released
void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    // Finishes drawing a scribble
    TOOL tool = toolbar -> getTool();
    if (tool == PENCIL) {
        canvas -> finishScribble();
        canvas -> redraw();
    }
    canvas -> redraw();
}

// Called when a toolbar button is changed in tool or action
void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar -> getAction();

    // Maps each action to the corresponding canvas method
    if (action == CLEAR) {
        canvas -> clear();
    }
    else if (action == UNDO) {
        canvas -> undo();
    }
    else if (action == BRING_TO_FRONT) {
        canvas -> bringToFront();
    }
    else if (action == SEND_TO_BACK) {
        canvas -> sendToBack();
    }
    else if (action == RESIZE_UP) {
        canvas -> resizeSelectedUp();
    }
    else if (action == RESIZE_DOWN) {
        canvas -> resizeSelectedDown();
    }

    canvas -> redraw();
}

// Called when the color selector is changed
void Application::onColorChange(bobcat::Widget* sender) {
    // Recolors only if it is in SELECT mode
    if (toolbar -> getTool() == SELECT) {
        Color color = colorSelector->getColor();

        canvas -> recolorSelected(color.getR(), color.getG(), color.getB());
        canvas -> redraw();
    }
}

// Application constructor––sets up the UI and callbacks
Application::Application() {
    // Creates the main window
    window = new Window(100, 100, 700, 700, "Programming Project");
    
    // Creates toolbar, canvas, and color selector
    toolbar = new Toolbar(0, 0, 250, 450);
    canvas = new Canvas (250, 0, 450, 450);
    colorSelector = new ColorSelector(0, 450, 700,  250);

    // Configures the appearance of canvas
    canvas -> box(FL_BORDER_FRAME);
    canvas -> color(FL_BLACK);

    // Adds widgets to the window
    window -> add(canvas);
    window -> add(toolbar);
    window -> add(colorSelector);

    // Hooks up the event callbacks
    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_CHANGE(colorSelector, Application::onColorChange);

    // Makes the window shown and starts the UI
    window -> show();
}
