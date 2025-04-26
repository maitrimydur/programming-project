#include "Triangle.h"
#include <GL/freeglut.h>

Triangle::Triangle() : x(0.0), y(0.0), base(0.2), height(0.2), r(0.0), g(0.0), b(0.0) {
    //
}

Triangle::Triangle(float xx, float yy, float rr, float gg, float bb): x(xx), y(yy), base(0.2), height(0.2), r(rr), g(gg), b(bb) {
    //
}

void Triangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();
}

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

void Triangle::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

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

void Triangle::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
