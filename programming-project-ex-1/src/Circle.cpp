#include "Circle.h"
#include <GL/freeglut.h>
#include <cmath>

// Default constructor that is centered at origin, contains default radius and the color black
Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

// Parameterized constructor that places a circle at the (mx, my) position with the given color
Circle::Circle(float mx, float my, float red, float green, float blue) : Circle() {
    x = mx;
    y = my;
    radius = 0.1;
    r = red;
    g = green;
    b = blue;
}

// Draws the circle as an approximated 60-sided polygon
void Circle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / 60;
        float theta = 0.0;

        while (theta <= 2 * M_PI) {
            glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
            theta = theta + inc;
        }

    glEnd();
}

// Hit-test which checks if the point (mx, my) lies within the circle
bool Circle::contains(float mx, float my) {
    float dx = mx - x;
    float dy = my - y;
    
    if (dx * dx + dy * dy <= radius * radius) {
        return true;
    }
    else {
        return false;
    }
}

// Moves the circle by the change in (dx, dy)
void Circle::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

// Resizes the circle by a scaling factor with a limit of the minimum radius
void Circle::resize(float factor) {
    radius = radius * factor;

    if (radius < 0.05) {
        radius = 0.05;
    }
}

// Changes the circle's fill in color
void Circle::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
