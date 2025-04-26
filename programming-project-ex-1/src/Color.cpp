#include "Color.h"

Color::Color() {
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Color::Color(float red, float green, float blue) {
    r = red;
    g = green;
    b = blue;
}

float Color::getR() const { 
    return r; 
}
float Color::getG() const { 
    return g; 
}
float Color::getB() const {
    return b; 
}
