#include "Point.h"
#include <GL/freeglut.h>
#include <cmath>

Point::Point() : x(0.0), y(0.0), r(0.0), g(0.0), b(0.0), size(7) {
    //
}

Point::Point(float x, float y, float rr, float gg, float bb, int s) : x(x), y(y), r(rr), g(gg), b(bb), size(s) {
    //
}

void Point::draw() {
    glColor3f(r, g, b);
    glPointSize(size);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

bool Point::contains(float mx, float my) {
    float dx = mx - x;
    float dy = my - y;
    float distSq = dx * dx + dy * dy;
    int half = size / 2;
    
    if (distSq <= half * half) {
        return true;
    }
    else {
        return false;
    }
}

void Point::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

void Point::resize(float factor) {
    if (factor > 1) {
        size = size + 1;
    }
    else if (factor < 1.0) {
        size = size - 1;
    }
    
    if (size < 1) {
        size = 1;
    }
}

void Point::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
