#include "Scribble.h"

// Adds a new Point to this scribble
void Scribble::addPoint(float x, float y, float r, float g, float b, int s) {
    points.push_back(new Point(x, y, r, g, b, s));
}

// Renders the points in the scribble
void Scribble::draw() {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i] -> draw();
    }
}

// Returns true if any points hold the given coordinates
bool Scribble::contains(float mx, float my) {
    for (int i = 0; i < (int)points.size(); i++) {
        if (points[i] -> contains(mx, my)) {
            return true;
        }
    }
    return false;
}

// Translates all points by the (dx, dy) positions
void Scribble::moveBy(float dx, float dy) {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i] -> moveBy(dx, dy);
    }
}

// Scales the size of each point by its factor
void Scribble::resize(float factor) {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i] -> resize(factor);
    }
}

// Updates the color for all points in the scribble
void Scribble::setColor(float nr, float ng, float nb) {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i] -> setColor(nr, ng, nb);
    }
}

// Marks this shape as a scribble
bool Scribble::isScribble() const {
    return true;
}

// Destructor that deletes all dynamically allocated points
Scribble::~Scribble() {
    for (int i = 0; i < (int)points.size(); i++) {
        delete points[i];
    }
    points.clear();
}
