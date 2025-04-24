#include "Toolbar.h"
using namespace bobcat;

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x,y,w,h), tool(PENCIL), action(NONE) {
    pencilButton = new Image(x,   y,   50,50,"./assets/pencil.png");
    eraserButton = new Image(x,  y+50, 50,50,"./assets/eraser.png");
    circleButton = new Image(x, y+100, 50,50,"./assets/circle.png");
    triangleButton = new Image(x, y+150, 50,50,"./assets/triangle.png");
    rectangleButton = new Image(x, y+200, 50,50,"./assets/rectangle.png");
    polygonButton = new Image(x, y+250, 50,50,"./assets/polygon.png");
    selectButton = new Image(x, y+300, 50,50,"./assets/select.png");
    undoButton = new Image(x, y+350, 50,50,"./assets/undo.png");
    clearButton = new Image(x, y+400, 50,50,"./assets/clear.png");
    bringFrontButton = new Image(x, y+450, 50,50,"./assets/front.png");
    sendBackButton = new Image(x, y+500, 50,50,"./assets/back.png");

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    selectButton->box(FL_BORDER_BOX);
    undoButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);
    bringFrontButton->box(FL_BORDER_BOX);
    sendBackButton->box(FL_BORDER_BOX);

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

    visualizeSelectedTool();
}

void Toolbar::deselectAllTools() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    selectButton->color(FL_BACKGROUND_COLOR);
}

void Toolbar::visualizeSelectedTool() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    selectButton->color(FL_BACKGROUND_COLOR);

    if (tool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (tool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (tool == POLYGON) {
        polygonButton->color(FL_WHITE);
    }
    else if (tool == SELECT) {
        selectButton->color(FL_WHITE);
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
