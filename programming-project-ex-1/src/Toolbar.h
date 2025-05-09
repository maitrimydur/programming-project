#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include "Enums.h"

class Toolbar : public bobcat::Group {
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

    bobcat::TextBox* toolsText;
    bobcat::TextBox* shapesText;
    bobcat::TextBox* sizeText;
    
    TOOL tool;
    ACTION action;

    void deselectAllTools();
    void visualizeSelectedTool();
    void onClick(bobcat::Widget* sender);

public:
    Toolbar(int x, int y, int w, int h);
    
    TOOL getTool() const;
    ACTION getAction() const;
    void clearAction();
};

#endif
