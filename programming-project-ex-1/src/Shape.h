#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
using namespace bobcat;

void Toolbar::deselectAllTools() {
    pencilButton -> color(FL_BACKGROUND_COLOR);
    eraserButton -> color(FL_BACKGROUND_COLOR);
    circleButton -> color(FL_BACKGROUND_COLOR);
    triangleButton -> color(FL_BACKGROUND_COLOR);
    rectangleButton -> color(FL_BACKGROUND_COLOR);
    polygonButton -> color(FL_BACKGROUND_COLOR);
    selectButton -> color(FL_BACKGROUND_COLOR);
    undoButton -> color(FL_BACKGROUND_COLOR);
    clearButton -> color(FL_BACKGROUND_COLOR);
    bringFrontButton -> color(FL_BACKGROUND_COLOR);
    sendBackButton -> color(FL_BACKGROUND_COLOR);
    plusButton -> color(FL_BACKGROUND_COLOR);
    minusButton -> color(FL_BACKGROUND_COLOR);
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

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x,y,w,h), tool(PENCIL), action(NONE) {
    pencilButton = new Image(x, y, 50, 50, "./assets/pencil.png");
    eraserButton = new Image(x, y + 50, 50, 50, "./assets/eraser.png");
    circleButton = new Image(x, y + 100, 50, 50,"./assets/circle.png");
    triangleButton = new Image(x, y + 150, 50,50,"./assets/triangle.png");
    rectangleButton = new Image(x, y + 200, 50,50,"./assets/rectangle.png");
    polygonButton = new Image(x, y + 250, 50, 50,"./assets/polygon.png");
    selectButton = new Image(x, y + 300, 50, 50,"./assets/mouse.png");
    undoButton = new Image(x, y + 350, 50, 50,"./assets/undo.png");
    clearButton = new Image(x, y + 400, 50, 50,"./assets/clear.png");
    bringFrontButton = new Image(x, y + 450, 50, 50,"./assets/bring-to-front.png");
    sendBackButton = new Image(x, y + 500, 50, 50,"./assets/send-to-back.png");
    plusButton = new Image(x, y + 550, 50, 50, "./assets/plus.png");
    minusButton = new Image(x, y + 600, 50, 50, "./assets/minus.png");

    tool = PENCIL;
    action = NONE;

    pencilButton -> box(FL_BORDER_BOX);
    eraserButton -> box(FL_BORDER_BOX);
    circleButton -> box(FL_BORDER_BOX);
    triangleButton -> box(FL_BORDER_BOX);
    rectangleButton -> box(FL_BORDER_BOX);
    polygonButton -> box(FL_BORDER_BOX);
    selectButton -> box(FL_BORDER_BOX);
    undoButton -> box(FL_BORDER_BOX);
    clearButton -> box(FL_BORDER_BOX);
    bringFrontButton -> box(FL_BORDER_BOX);
    sendBackButton -> box(FL_BORDER_BOX);
    plusButton -> box(FL_BORDER_BOX);
    minusButton -> box(FL_BORDER_BOX);

    visualizeSelectedTool();

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
}
