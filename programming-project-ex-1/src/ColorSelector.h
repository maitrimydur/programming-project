#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/textbox.h>
#include "Color.h"
#include "Enums.h"

class ColorSelector : public bobcat::Group {
    bobcat::Button* redButton;
    bobcat::Button* orangeButton;
    bobcat::Button* yellowButton;
    bobcat::Button* greenButton;
    bobcat::Button* blueButton;
    bobcat::Button* indigoButton;
    bobcat::Button* violetButton;
    bobcat::Button* pinkButton;
    bobcat::Button* whiteButton;
    bobcat::Button* lightGreyButton;
    bobcat::Button* darkGreyButton;
    bobcat::Button* blackButton;

    bobcat::Button* increaseRedButton;
    bobcat::Button* decreaseRedButton;
    bobcat::Button* increaseGreenButton;
    bobcat::Button* decreaseGreenButton;
    bobcat::Button* increaseBlueButton;
    bobcat::Button* decreaseBlueButton;
    bobcat::Button* clearButton;
    bobcat::Button* confirmButton;

    bobcat::TextBox* colorsText;
    bobcat::TextBox* redColorText;
    bobcat::IntInput* redColorValue;
    bobcat::TextBox* greenColorText;
    bobcat::IntInput* greenColorValue;
    bobcat::TextBox* blueColorText;
    bobcat::IntInput* blueColorValue;

    COLOR color;

    bool usingCustomColor;
    int lastConfirmedR;
    int lastConfirmedG;
    int lastConfirmedB;

    void deselectAllColors();
    void visualizeSelectedColor();
    void onClick(bobcat::Widget* sender);
    void onAdjustColor(bobcat::Widget* sender);
    void onClearInputs(bobcat::Widget* sender);
    void onConfirmColor(bobcat::Widget* sender);
    
public:
    void updateRGBInputs();
    ColorSelector(int x, int y, int w, int h);
    Color getColor() const;
};

#endif
