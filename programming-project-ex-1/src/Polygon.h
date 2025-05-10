#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

// Polygon that represents a regular n-sided polygon (default 5 sides) with a position, size, and color
class Polygon : public Shape {
    float x;
    float y;
    int sides;
    float length;
    float r;
    float g;
    float b;

public:
    // Constructors that are default polygon or parameterized positioned with custom color
    Polygon();
    Polygon(float x, float y, float r, float g, float b);

    // Draws and hit-tests methods
    void draw() override;
    bool contains(float mx, float my) override;

    // Transformation and styling methods
    void moveBy(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float nr, float ng, float nb) override;
};

#endif
