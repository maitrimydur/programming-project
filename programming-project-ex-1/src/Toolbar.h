#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include "Enums.h"

// Toolbar provides UI buttons to select the drawing tools such as TOOL enum and actions ACTION enum
class Toolbar : public bobcat::Group {
    // UI Elements of buttons for the tools and the actions
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* circleButton;
    bobcat::Image* triangleButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* polygonButton;
    bobcat::Image* selectButton;
    bobcat::Image* undoButton;
    bobcat::Image* clearButton;
    bobcat::Image* bringFrontButton;
    bobcat::Image* sendBackButton;
    bobcat::Image* plusButton;
    bobcat::Image* minusButton;

    // Labels for grouping the tools and the shapes
    bobcat::TextBox* toolsText;
    bobcat::TextBox* shapesText;
    bobcat::TextBox* sizeText;
    
    // Internal state of the current tool and action
    TOOL tool;
    ACTION action;

    // Internal methods for updating the UI state and the handling clicks
    void deselectAllTools();
    void visualizeSelectedTool();
    void onClick(bobcat::Widget* sender);

public:
    // Initializes toolbar at the position (x, y) with the dimensions (w, h)
    Toolbar(int x, int y, int w, int h);
    
    // Retrieves the current tool or action
    TOOL getTool() const;
    ACTION getAction() const;

    // Resets any action as it keeps the current tool
    void clearAction();
};

#endif
