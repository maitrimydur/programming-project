#include "Rectangle.h"
#include <GL/freeglut.h>

Rectangle::Rectangle() : x(0.0), y(0.0), width(0.2), height(0.2), r(0.0), g(0.0), b(0.0) {
    //
}

Rectangle::Rectangle(float xx, float yy, float rr, float gg, float bb) : x(xx), y(yy), width(0.2), height(0.2), r(rr), g(gg), b(bb) {
    //
}

void Rectangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

bool Rectangle::contains(float mx, float my) {
    if (mx >= x - width/2 && mx <= x + width/2 && my >= y - height/2 && my <= y + height/2) {
        return true;
    }
    else {
        return false;
    }
}

void Rectangle::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

void Rectangle::resize(float factor) {
    width  = width * factor;
    height = height * factor;

    if (width < 0.05) {
        width = 0.05;
    }
    if (height < 0.05) {
        height = 0.05;
    }
}

void Rectangle::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
