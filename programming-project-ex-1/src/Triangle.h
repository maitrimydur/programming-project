#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

// Triangle is an isosceles triangle shape with the position, the size, and the color
class Triangle : public Shape {
    float x;
    float y;
    float base;
    float height;
    float r;
    float g;
    float b;

public:
    // Constructors that have default centered as a black triangle or positioned and colored
    Triangle();
    Triangle(float x, float y, float r, float g, float b);

    // Drawing and hit-testing methods
    void draw() override;
    bool contains(float mx, float my) override;
    
    // Transformation and styling methods
    void moveBy(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float nr, float ng, float nb) override;
};

#endif
