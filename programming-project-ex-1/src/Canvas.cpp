#include "Canvas.h"
#include <FL/Enumerations.H>
#include <GL/freeglut.h>
#include <algorithm>

// Constructor that initializes the drawing area, background color, and states 
Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    currentScribble = nullptr;
    selected = nullptr;
    
    box(FL_FLAT_BOX);
    color(fl_rgb_color(213, 231, 239));
}

// Destructor that deletes all stored shapes/scribbles
Canvas::~Canvas() {
    for (int i = 0; i < (int)shapes.size(); i++) {
        delete shapes[i];
    }
}

// Begins a new freehand stroke––scribble
void Canvas::startScribble(float x, float y, float r, float g, float b, int size) {
    currentScribble = new Scribble();
    shapes.push_back(currentScribble);
    currentScribble -> addPoint(x, y, r, g, b, size);
}

// Adds a point to the current scribble while dragging
void Canvas::addToScribble(float x, float y, float r, float g, float b, int size) {
    if (currentScribble) {
        currentScribble -> addPoint(x, y, r, g, b, size);
    }
}

// Finishes the current scribble so further drags will start a new scribble
void Canvas::finishScribble() {
    currentScribble = NULL;
}

// Adds a new geometry shape at (x, y) position with the given colors
void Canvas::addRectangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Rectangle(x, y, r, g, b));
}
void Canvas::addCircle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Circle(x, y, r, g, b));
}
void Canvas::addTriangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Triangle(x, y, r, g, b));
}

void Canvas::addPolygon(float x, float y, float r, float g, float b) {
    shapes.push_back(new Polygon(x, y, r, g, b));
}

// Selects the top most non-scribble shape under the cursor and if none, it selects scribbles
void Canvas::selectAt(float mx, float my) {
    selected = nullptr;

    // Searches from top most down
    for (int i = (int)shapes.size() - 1; i >= 0; --i) {
        if (!shapes[i] -> isScribble() && shapes[i] -> contains(mx, my)) {
            selected = shapes[i];
            return;
        }
    }
    for (int i = (int)shapes.size() - 1; i >= 0; --i) {
        if (shapes[i] -> isScribble() && shapes[i] -> contains(mx, my)) {
            selected = shapes[i];
            return;
        }
    }
}

// Moves the selected object by the (dx, dy) coordinates
void Canvas::moveSelected(float dx, float dy) {
    if (selected) {
        selected -> moveBy(dx, dy);
    }
}

// Resizes and recolors whichever object is selected
void Canvas::resizeSelected(float factor) {
    if (selected) {
        selected -> resize(factor);
    }
}
void Canvas::recolorSelected(float r, float g, float b) {
    if (selected) {
        selected -> setColor(r, g, b);
    }
}

// Changes the stacking order based on which object is selected
void Canvas::bringToFront() {
    if (!selected) {
        return;
    }

    for (int i = 0; i < (int)shapes.size(); i++) {
        if (shapes[i] == selected) {
            Shape* tmp = shapes[i];
            shapes.erase(shapes.begin() + i);
            shapes.push_back(tmp);
            break;
        }
    }
}
void Canvas::sendToBack() {
    if (!selected) {
        return;
    }

    for (int i = 0; i < (int)shapes.size(); i++) {
        if (shapes[i] == selected) {
            Shape* tmp = shapes[i];
            shapes.erase(shapes.begin() + i);
            shapes.insert(shapes.begin(), tmp);
            break;
        }
    }
}

// Conveniences for the wrappers' small resize steps
void Canvas::resizeSelectedUp() {
    if (selected) {
        selected -> resize(1.1);
    }
}
void Canvas::resizeSelectedDown() {
    if (selected) {
        selected -> resize(0.9);
    }
}

// Removes all shapes and clears the selection
void Canvas::clear() {
    for (int i = 0; i < (int)shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
    selected = NULL;
}

// Undo the last added shape or scribble
void Canvas::undo() {
    if (shapes.size() > 0) {
        delete shapes[shapes.size() - 1];
        shapes.pop_back();
        selected = NULL;
    }
}

// Renders all the shapes that have OpenGL
void Canvas::render() {
    glClearColor(213.0/255.0, 231.0/255.0, 239.0/255.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < (int)shapes.size(); i++) {
        shapes[i] -> draw();
    }
}

// Erases the topmost shapes that are under the cursor
void Canvas::eraseAt(float x, float y) {
    for (int i = (int)shapes.size() - 1; i >= 0; --i) {
        if (shapes[i] -> contains(x, y)) {
            delete shapes[i];
            shapes.erase(shapes.begin() + i);
            selected = nullptr;
            break;
        }
    }
}
