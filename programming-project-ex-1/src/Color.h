#ifndef COLOR_H 
#define COLOR_H

// Gives a storage for the color channels
class Color {
    float r;
    float g;
    float b;

public:
    // Constructors with default color as black and parameterized the channels
    Color();
    Color(float r, float g, float b);

    // Accessor that retrieves individual channel values
    float getR() const;
    float getG() const;
    float getB() const;
};

#endif
