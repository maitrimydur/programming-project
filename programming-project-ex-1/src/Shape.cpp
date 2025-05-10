#include "Shape.h"

// Virtual destructor that ensures that the derived destructors are called correctly
Shape::~Shape() {
    //
}

// Makes sure that only Scribble returns true
bool Shape::isScribble() const {
    return false;
}
