#ifndef POINT_H
#define POINT_H

#include "Shape.h"

// Creates point with a drawable dot that is used for a freehand scribble
class Point : public Shape {
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;
    
public:
    // Default and parameterized constructors that initialize the points
    Point();
    Point(float x, float y, float r, float g, float b, int size);

    // Draws the point and tests if the coordinate lies within its area
    void draw() override;
    bool contains(float mx, float my) override;

    // Moves, resizes, and recolors the point
    void moveBy(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float nr, float ng, float nb) override;
};

#endif
