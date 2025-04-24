#include "Application.h"
#include "Enums.h"
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->startScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
    }
    else if (tool == ERASER) {
        canvas->startScribble(mx, my, 1.0, 1.0, 1.0, 14);
    }
    else if (tool == SELECT) {
        canvas->selectAt(mx, my);
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
    }
    else if (tool == CIRCLE) {
        canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(mx, my, color.getR(), color.getG(), color.getB());
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, color.getR(), color.getG(), color.getB());
    }

    lastX = mx;
    lastY = my;
    canvas->redraw();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->addToScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
    }
    else if (tool == ERASER) {
        canvas->addToScribble(mx, my, 1.0, 1.0, 1.0, 14);
    }
    else if (tool == SELECT) {
        float dx = mx - lastX;
        float dy = my - lastY;
        canvas->moveSelected(dx, dy);
    }

    lastX = mx;
    lastY = my;
    
    canvas->redraw();
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    if (tool == PENCIL || tool == ERASER) {
        canvas->finishScribble();
        canvas->redraw();
    }
    canvas -> redraw();
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
    }
    else if (action == UNDO) {
        canvas->undo();
    }
    else if (action == BRING_TO_FRONT) {
        canvas->bringToFront();
    }
    else if (action == SEND_TO_BACK) {
        canvas->sendToBack();
    }

    canvas->redraw();
}

Application::Application() {
    window = new Window(100, 100, 400, 600, "Paint Application");
    toolbar = new Toolbar(0, 0, 50, 550);
    canvas = new Canvas (50, 0, 350, 550);
    colorSelector = new ColorSelector(50, 550, 350,  50);
    colorSelector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}
