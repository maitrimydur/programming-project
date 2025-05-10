#include "Rectangle.h"
#include <GL/freeglut.h>

// Default constructor that positions at the origin, selects the default size and default color black
Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

// Parameterized constructor that sets the position and color but keeps the default size
Rectangle::Rectangle(float mx, float my, float red, float green, float blue) : Rectangle() {
    x = mx;
    y = my;
    width = 0.2;
    height = 0.2;
    r = red;
    g = green;
    b = blue;
}

// Renders the rectangle as a filled rectangle
void Rectangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

// Checks if a point is in the rectangle bounds
bool Rectangle::contains(float mx, float my) {
    if (mx >= x - width/2 && mx <= x + width/2 && my >= y - height/2 && my <= y + height/2) {
        return true;
    }
    else {
        return false;
    }
}

// Translates the rectangle's position by the given delta
void Rectangle::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

// Scales the rectangle dimensions with a limit for the minimum
void Rectangle::resize(float factor) {
    width = width * factor;
    height = height * factor;

    if (width < 0.05) {
        width = 0.05;
    }
    
    if (height < 0.05) {
        height = 0.05;
    }
}

// Sets the colors based on the RGB values
void Rectangle::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
