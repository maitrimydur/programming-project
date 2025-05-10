#include "Point.h"
#include <GL/freeglut.h>
#include <cmath>

// Default constructor that contains origin point, the color black, and the default size
Point::Point() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 7;
}

// Parameterized constructor that initializes the position, the color, and the size
Point::Point(float mx, float my, float red, float green, float blue, int s) : Point() {
    x = mx;
    y = my;
    r = red;
    g = green;
    b = blue;
    size = s;
}

// Draws the point as a GL_POINT with its current size and color
void Point::draw() {
    glColor3f(r, g, b);
    glPointSize(size);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

// Returns true if the (mx, my) position lies within half the point's size radius
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

// Moves the point by its specified delta
void Point::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

// Resizes the point by either incrementing or decrementing its size, but makes sure to enforce a minimum size of 1
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

// Changes the point's color to the new RGB values selected
void Point::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
