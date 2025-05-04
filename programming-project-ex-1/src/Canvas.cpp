#include "Canvas.h"
#include <GL/freeglut.h>
#include <algorithm>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x,y,w,h), currentScribble(nullptr), selected(nullptr) {
    //
}

Canvas::~Canvas() {
    for (int i = 0; i < (int)shapes.size(); i++) {
        delete shapes[i];
    }
}

void Canvas::startScribble(float x, float y, float r, float g, float b, int size) {
    currentScribble = new Scribble();
    shapes.push_back(currentScribble);
    currentScribble -> addPoint(x, y, r, g, b, size);
}

void Canvas::addToScribble(float x, float y, float r, float g, float b, int size) {
    if (currentScribble) {
        currentScribble -> addPoint(x, y, r, g, b, size);
    }
}

void Canvas::finishScribble() {
    currentScribble = NULL;
}

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

void Canvas::selectAt(float mx, float my) {
    selected = nullptr;

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

void Canvas::moveSelected(float dx, float dy) {
    if (selected) {
        selected -> moveBy(dx, dy);
    }
}

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

void Canvas::clear() {
    for (int i = 0; i < (int)shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
    selected = NULL;
}

void Canvas::undo() {
    if (shapes.size() > 0) {
        delete shapes[shapes.size() - 1];
        shapes.pop_back();
        selected = NULL;
    }
}

void Canvas::render() {
    for (int i = 0; i < (int)shapes.size(); i++) {
        shapes[i] -> draw();
    }
}

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
