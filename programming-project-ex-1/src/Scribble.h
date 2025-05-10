#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

// Scribble is a freehand stroke that is composed of multiple Point objects
class Scribble: public Shape {
    // Stores the sequences of points comprising the strokes as private
    std::vector<Point*> points;

public:
    // Manages the stroke content and implements the Shape interface
    void addPoint(float x, float y, float r, float g, float b, int size);
    void draw() override;
    bool contains(float mx, float my) override;
    void moveBy(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float r, float g, float b) override;
    bool isScribble() const override;

    ~Scribble();
};

#endif
