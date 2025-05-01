#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point : public Shape {
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;
    
public:
    Point();
    Point(float x, float y, float r, float g, float b, int size);

    void draw() override;
    bool contains(float mx, float my) override;
    void moveBy(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float nr, float ng, float nb) override;
};

#endif
