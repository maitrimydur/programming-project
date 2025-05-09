#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
using namespace bobcat;

void Toolbar::deselectAllTools() {
    pencilButton -> color(fl_rgb_color(245, 233, 211));
    eraserButton -> color(fl_rgb_color(245, 233, 211));
    circleButton -> color(fl_rgb_color(245, 233, 211));
    triangleButton -> color(fl_rgb_color(245, 233, 211));
    rectangleButton -> color(fl_rgb_color(245, 233, 211));
    polygonButton -> color(fl_rgb_color(245, 233, 211));
    selectButton -> color(fl_rgb_color(245, 233, 211));
    undoButton -> color(fl_rgb_color(245, 233, 211));
    clearButton -> color(fl_rgb_color(245, 233, 211));
    bringFrontButton -> color(fl_rgb_color(245, 233, 211));
    sendBackButton -> color(fl_rgb_color(245, 233, 211));
    plusButton -> color(fl_rgb_color(245, 233, 211));
    minusButton -> color(fl_rgb_color(245, 233, 211));
}

void Toolbar::clearAction() {
    action = NONE;
}

void Toolbar::visualizeSelectedTool() {
    deselectAllTools();

    if (action == UNDO) {
        undoButton -> color(FL_WHITE);
    }
    else if (action == CLEAR) {          
        clearButton -> color(FL_WHITE);
    }
    else if (action == BRING_TO_FRONT) { 
        bringFrontButton -> color(FL_WHITE);
    }
    else if (action == SEND_TO_BACK) {   
        sendBackButton -> color(FL_WHITE);
    }
    else if (action == RESIZE_UP) {
        plusButton -> color(FL_WHITE);
    }
    else if (action == RESIZE_DOWN) {
        minusButton -> color(FL_WHITE);
    }
    else {
        if(tool == PENCIL) {
            pencilButton -> color(FL_WHITE);
        }
        else if (tool == ERASER) {    
            eraserButton -> color(FL_WHITE); 
        }
        else if (tool == CIRCLE) {    
            circleButton -> color(FL_WHITE); 
        }
        else if (tool == TRIANGLE) {  
            triangleButton -> color(FL_WHITE); 
        }
        else if (tool == RECTANGLE) { 
            rectangleButton -> color(FL_WHITE); 
        }
        else if (tool == POLYGON) {   
            polygonButton -> color(FL_WHITE); 
        }
        else if (tool == SELECT) {    
            selectButton -> color(FL_WHITE); 
        }
    }
}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();
    action = NONE;

    if (sender == pencilButton) {
        tool = PENCIL;
    }
    else if (sender == eraserButton) {
        tool = ERASER; 
    }
    else if (sender == circleButton) {     
        tool = CIRCLE;
    }
    else if (sender == triangleButton) {   
        tool = TRIANGLE;
    }
    else if (sender == rectangleButton) {  
        tool = RECTANGLE;
    }
    else if (sender == polygonButton) {    
        tool = POLYGON;
    }
    else if (sender == selectButton) {     
        tool = SELECT;
    }
    else if (sender == undoButton) {       
        action = UNDO;
    }
    else if (sender == clearButton) {      
        action = CLEAR;
    }
    else if (sender == bringFrontButton) {
        action = BRING_TO_FRONT;
    }
    else if (sender == sendBackButton) {   
        action = SEND_TO_BACK;
    }
    else if (sender == plusButton) {
        action = RESIZE_UP;
    }
    else if (sender == minusButton) {
        action = RESIZE_DOWN;
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedTool();
    redraw();
}

TOOL Toolbar::getTool() const { 
    return tool; 
}

ACTION Toolbar::getAction() const {
    return action; 
}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x + 10, y + 50, 50, 50, "./assets/pencil.png");
    pencilButton -> box(FL_BORDER_BOX);
    eraserButton = new Image(x + 70, y + 50, 50, 50, "./assets/eraser.png");
    eraserButton -> box(FL_BORDER_BOX);
    selectButton = new Image(x + 130, y + 50, 50, 50,"./assets/mouse.png");
    selectButton -> box(FL_BORDER_BOX);
    undoButton = new Image(x + 10, y + 110, 50, 50,"./assets/undo.png");
    undoButton -> box(FL_BORDER_BOX);
    clearButton = new Image(x + 70, y + 110, 50, 50,"./assets/clear.png");
    clearButton -> box(FL_BORDER_BOX);
    bringFrontButton = new Image(x + 130, y + 110, 50, 50,"./assets/bring-to-front.png");
    bringFrontButton -> box(FL_BORDER_BOX);
    sendBackButton = new Image(x + 10, y + 170, 50, 50,"./assets/send-to-back.png");
    sendBackButton -> box(FL_BORDER_BOX);
    circleButton = new Image(x + 10, y + 290, 50, 50,"./assets/circle.png");
    circleButton -> box(FL_BORDER_BOX);
    triangleButton = new Image(x + 70, y + 290, 50,50,"./assets/triangle.png");
    triangleButton -> box(FL_BORDER_BOX);
    rectangleButton = new Image(x + 10, y + 350, 50,50,"./assets/rectangle.png");
    rectangleButton -> box(FL_BORDER_BOX);
    polygonButton = new Image(x + 70, y + 350, 50, 50,"./assets/polygon.png");
    polygonButton -> box(FL_BORDER_BOX);
    plusButton = new Image(x + 170, y + 290, 50, 50, "./assets/plus.png");
    plusButton -> box(FL_BORDER_BOX);
    minusButton = new Image(x + 170, y + 350, 50, 50, "./assets/minus.png");
    minusButton -> box(FL_BORDER_BOX);

    toolsText = new TextBox(10, 20, 250, 25, "Tools");
    toolsText -> labelsize(18);
    toolsText -> labelcolor(fl_rgb_color(30, 41, 45));
    toolsText -> labelfont(FL_HELVETICA_BOLD);
    shapesText = new TextBox(10, 260, 250, 25, "Shapes");
    shapesText -> labelsize(18);
    shapesText -> labelcolor(fl_rgb_color(30, 41, 45));
    shapesText -> labelfont(FL_HELVETICA_BOLD);
    sizeText = new TextBox(170, 260, 250, 25, "Size");
    sizeText -> labelsize(18);
    sizeText -> labelcolor(fl_rgb_color(30, 41, 45));
    sizeText -> labelfont(FL_HELVETICA_BOLD);

    tool = PENCIL;
    action = NONE;
    box(FL_FLAT_BOX);
    color(fl_rgb_color(134, 158, 164));

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(selectButton, Toolbar::onClick);
    ON_CLICK(undoButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);
    ON_CLICK(bringFrontButton, Toolbar::onClick);
    ON_CLICK(sendBackButton, Toolbar::onClick);
    ON_CLICK(plusButton, Toolbar::onClick);
    ON_CLICK(minusButton, Toolbar::onClick);

    visualizeSelectedTool();
}
