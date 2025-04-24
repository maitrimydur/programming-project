#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
    float x, y, radius, r, g, b;
    
public:
    Circle();                                              
    Circle(float x, float y, float r, float g, float b);  

    void draw() override;

    bool contains(float mx, float my) override;
    void moveBy(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float nr, float ng, float nb) override;
};

#endif
