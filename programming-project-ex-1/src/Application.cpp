#include "Application.h"
#include "Enums.h"
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar -> getTool();
    Color color = colorSelector -> getColor();

    if (tool == PENCIL) {
        canvas -> startScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
    }
    else if (tool == ERASER) {
        canvas -> eraseAt(mx, my);
    }
    else if (tool == SELECT) {
        canvas -> selectAt(mx, my);
    }
    else if (tool == RECTANGLE) {
        canvas -> addRectangle(mx, my, color.getR(), color.getG(), color.getB());
    }
    else if (tool == CIRCLE) {
        canvas -> addCircle(mx, my, color.getR(), color.getG(), color.getB());
    }
    else if (tool == TRIANGLE) {
        canvas -> addTriangle(mx, my, color.getR(), color.getG(), color.getB());
    }
    else if (tool == POLYGON) {
        canvas -> addPolygon(mx, my, color.getR(), color.getG(), color.getB());
    }

    lastX = mx;
    lastY = my;
    canvas -> redraw();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar -> getTool();
    Color color = colorSelector -> getColor();

    if (tool == PENCIL) {
        canvas -> addToScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
    }
    else if (tool == ERASER) {
        canvas -> eraseAt(mx, my);
    }
    else if (tool == SELECT) {
        float dx = mx - lastX;
        float dy = my - lastY;
        canvas -> moveSelected(dx, dy);
    }

    lastX = mx;
    lastY = my;
    
    canvas -> redraw();
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar -> getTool();
    if (tool == PENCIL) {
        canvas -> finishScribble();
        canvas -> redraw();
    }
    canvas -> redraw();
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar -> getAction();

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

void Application::onColorChange(bobcat::Widget* sender) {
    if (toolbar -> getTool() == SELECT) {
        Color color = colorSelector->getColor();

        canvas->recolorSelected(color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
}

Application::Application() {
    window = new Window(100, 100, 700, 700, "Programming Project");

    toolbar = new Toolbar(0, 0, 50, 650);

    canvas = new Canvas (50, 0, 650, 650);

    colorSelector = new ColorSelector(50, 650, 650,  50);
    colorSelector -> box(FL_BORDER_BOX);

    window -> add(toolbar);
    window -> add(canvas);
    window -> add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_CHANGE(colorSelector, Application::onColorChange);

    window -> show();
}
