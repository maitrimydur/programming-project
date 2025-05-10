#include "Triangle.h"
#include <GL/freeglut.h>

// Default constructor that initializes at the center of (0, 0), the default base/height, and the default color of black
Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    base = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

// Parameterized constructor that sets the center and color as it keeps the default dimensions
Triangle::Triangle(float mx, float my, float red, float green, float blue) : Triangle() {
    x = mx;
    y = my;
    base = 0.2;
    height = 0.2;
    r = red;
    g = green;
    b = blue;
}

// Renders an isosceles triangle using the current color
void Triangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();
}

// Simple bounding-box test for the area of the triangle
bool Triangle::contains(float mx, float my) {
    float minx = x - base/2;
    float maxx = x + base/2;
    float miny = y - height/2;
    float maxy = y + height/2;

    if (mx >= minx && mx <= maxx && my >= miny && my <= maxy) {
        return true;
    }
    else {
        return false;
    }
}

// Translates the triangle center by the (dx, dy) position
void Triangle::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

// Scales the base and height while enforcing a minimum limit
void Triangle::resize(float factor) {
    base   = base * factor;
    height = height * factor;

    if (base < 0.05) {
        base = 0.05;
    }
    
    if (height < 0.05) {
        height = 0.05;
    }
}

// Updates the triangle's RGB components
void Triangle::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
