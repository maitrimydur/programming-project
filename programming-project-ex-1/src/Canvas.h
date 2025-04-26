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

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;
    Scribble* currentScribble;
    Shape* selected;
    
public:
    Canvas(int x, int y, int w, int h);
    ~Canvas();

    void startScribble(float x, float y, float r, float g, float b, int size);
    void addToScribble(float x, float y, float r, float g, float b, int size);
    void finishScribble();

    void addRectangle(float x, float y, float r, float g, float b);
    void addCircle(float x, float y, float r, float g, float b);
    void addTriangle(float x, float y, float r, float g, float b);
    void addPolygon(float x, float y, float r, float g, float b);

    void selectAt(float x, float y);
    void moveSelected(float dx, float dy);
    void resizeSelected(float factor);
    void recolorSelected(float r, float g, float b);
    void bringToFront();
    void sendToBack();
    void resizeSelectedUp();
    void resizeSelectedDown();

    void clear();
    void undo();
    void render() override;
};

#endif
