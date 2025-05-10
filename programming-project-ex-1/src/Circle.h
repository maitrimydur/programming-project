#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

// Circle implements based on the Shape class and stores position, size, and color
class Circle : public Shape {
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;
    
public:
    // Default constructor and parameterized constructor
    Circle();                                              
    Circle(float x, float y, float r, float g, float b);

    // Methods to help draw and interact with circle
    void draw() override;
    bool contains(float mx, float my) override;
    void moveBy(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float nr, float ng, float nb) override;
};

#endif
