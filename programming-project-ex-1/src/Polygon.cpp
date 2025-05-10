#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

// Default constructor which initializes the Polygon's center at (0,0), has 5 sides, creates a default size and is the color black
Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    sides = 5;
    length = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

// Parameterized constructor that sets the center, keeps the default shape and the color values and then applies it with the provided color
Polygon::Polygon(float mx, float my, float red, float green, float blue) : Polygon() {
    x = mx;
    y = my;
    sides = 5;
    length = 0.1;
    r = red;
    g = green;
    b = blue;
}

// Renders the regular polygon with its current color
void Polygon::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        float theta = 0.0;

        while (theta <= 2 * M_PI) {
            glVertex2f(x + length * cos(theta), y + length * sin(theta));
            theta = theta + inc;
        }
    glEnd();
}

// Simple hit-test that is within the polygon's bounding box
bool Polygon::contains(float mx, float my) {
    float dx = mx - x;
    float dy = my - y;

    if (dx >= -length && dx <= length && dy >= -length && dy <= length) {
        return true;
    }
    else {
        return false;
    }
}

// Translates the polygon center position by (dx, dy)
void Polygon::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

// Scales the edge length by the factor, enforcing its minimum length
void Polygon::resize(float factor) {
    length = length * factor;
    
    if (length < 0.05) {
        length = 0.05;
    }
}

// Updates the polygon's RGB values
void Polygon::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
