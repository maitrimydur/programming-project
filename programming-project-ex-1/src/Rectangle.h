#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

// Rectangle that is a centered shape with configurable size and color
class Rectangle : public Shape {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
// Constructors that are default or positioned with a custom color
    Rectangle();
    Rectangle(float x, float y, float r, float g, float b);

    // Rendering and hit-testing methods
    void draw() override;
    bool contains(float mx, float my) override;

    // Transformation and styling methods
    void moveBy(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float nr, float ng, float nb) override;
};

#endif
