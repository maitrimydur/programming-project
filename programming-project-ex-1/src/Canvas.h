#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Shape.h"
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Scribble.h"

// Canvas class that extends the Bobcat canvas widgets to store and manage the objects to draw
class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;
    Scribble* currentScribble;
    Shape* selected;
    
public:
    // Constructors a canvas at (x, y) postion with width w and height h
    Canvas(int x, int y, int w, int h);
    // Deletes all the shapes and cleans it up
    ~Canvas();

    // Methods to draw freehandedly
    void startScribble(float x, float y, float r, float g, float b, int size);
    void addToScribble(float x, float y, float r, float g, float b, int size);
    void finishScribble();

    // Creates shapes to add on Canvas
    void addRectangle(float x, float y, float r, float g, float b);
    void addCircle(float x, float y, float r, float g, float b);
    void addTriangle(float x, float y, float r, float g, float b);
    void addPolygon(float x, float y, float r, float g, float b);

    // Uses manipulation based on the selection
    void selectAt(float x, float y);
    void moveSelected(float dx, float dy);
    void resizeSelected(float factor);
    void recolorSelected(float r, float g, float b);
    void bringToFront();
    void sendToBack();
    void resizeSelectedUp();
    void resizeSelectedDown();

    // Controls that Canvas provides
    void clear();
    void undo();
    void render() override;
    void eraseAt(float x, float y);
};

#endif
