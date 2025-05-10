#include "Color.h"

// Default constructor zeros all Color channel storage
Color::Color() {
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

// Parameterized sets the give values
Color::Color(float red, float green, float blue) : Color() {
    r = red;
    g = green;
    b = blue;
}

// Accessors that return individual color channel value
float Color::getR() const { 
    return r; 
}

float Color::getG() const { 
    return g; 
}

float Color::getB() const {
    return b; 
}
