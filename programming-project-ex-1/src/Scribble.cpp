#include "Scribble.h"

void Scribble::addPoint(float x, float y, float r, float g, float b, int s) {
    points.push_back(new Point(x, y, r, g, b, s));
}

void Scribble::draw() {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i]->draw();
    }
}

bool Scribble::contains(float mx, float my) {
    for (int i = 0; i < (int)points.size(); i++) {
        if (points[i]->contains(mx, my)) {
            return true;
        }
    }
    return false;
}

void Scribble::moveBy(float dx, float dy) {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i]->moveBy(dx, dy);
    }
}

void Scribble::resize(float factor) {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i]->resize(factor);
    }
}

void Scribble::setColor(float nr, float ng, float nb) {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i]->setColor(nr, ng, nb);
    }
}

Scribble::~Scribble() {
    for (int i = 0; i < (int)points.size(); i++) {
        delete points[i];
    }
    points.clear();
}
