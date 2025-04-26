#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

Polygon::Polygon() : x(0.0), y(0.0), sides(5), length(0.1), r(0.0), g(0.0), b(0.0) {
    //
}

Polygon::Polygon(float xx, float yy, float rr, float gg, float bb) : x(xx), y(yy), sides(5), length(0.1), r(rr), g(gg), b(bb) {
    //
}

void Polygon::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        float theta = 0.0;
        while (theta <= 2 * M_PI) {
            glVertex2f(x + length * cos(theta),
                       y + length * sin(theta));
            theta = theta + inc;
        }
    glEnd();
}

bool Polygon::contains(float mx, float my) {
    float dx = mx - x;
    float dy = my - y;
    if (dx >= -length && dx <= length &&
        dy >= -length && dy <= length)
        return true;
    else
        return false;
}

void Polygon::moveBy(float dx, float dy) {
    x = x + dx;
    y = y + dy;
}

void Polygon::resize(float factor) {
    length = length * factor;
    if (length < 0.05) {
        length = 0.05;
    }
}

void Polygon::setColor(float nr, float ng, float nb) {
    r = nr;
    g = ng;
    b = nb;
}
