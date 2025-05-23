#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>

// Shape is an abstract base class which defines the interface for all drawable objects
class Shape {

public: 
    // Core operations
    virtual void draw() = 0;
    virtual bool contains(float mx, float my) = 0;
    virtual void moveBy(float dx, float dy) = 0;
    virtual void resize(float factor) = 0;
    virtual void setColor(float r, float g, float b) = 0;

    // Identification and cleanup
    virtual bool isScribble() const;
    virtual ~Shape();
};

#endif
