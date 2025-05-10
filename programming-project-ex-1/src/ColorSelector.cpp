#include "ColorSelector.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <FL/fl_draw.H>
#include <GL/glext.h>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/textbox.h>
#include <string>

using namespace bobcat;

// Helper function that clamps the integer to a [minVal, maxVal]
int clampInt(int value, int minVal, int maxVal) {
    if (value < minVal) {
        return minVal;
    }
    
    if (value > maxVal) {
        return maxVal;
    }

    return value;
}

// Deselects all the colors as default
void ColorSelector::deselectAllColors() {
    redButton -> label("");
    orangeButton -> label("");
    yellowButton -> label("");
    greenButton -> label("");
    blueButton -> label("");
    indigoButton -> label("");
    violetButton -> label("");
    pinkButton -> label("");
    whiteButton -> label("");
    lightGreyButton -> label("");
    darkGreyButton -> label("");
    blackButton -> label("");
}

// Highlights the chosen color button
void ColorSelector::visualizeSelectedColor() {
    deselectAllColors();

    if (usingCustomColor) {
        return;
    }
    
    if (color == RED) {
        redButton -> label("@+5square");
    }
    else if (color == ORANGE) {
        orangeButton -> label("@+5square");
    }
    else if (color == YELLOW) {
        yellowButton -> label("@+5square");
    }
    else if (color == GREEN) {
        greenButton -> label("@+5square");
    }
    else if (color == BLUE) {
        blueButton -> label("@+5square");
    }
    else if (color == INDIGO) {
        indigoButton -> label("@+5square");
    }
    else if (color == VIOLET) {
        violetButton -> label("@+5square");
    }
    else if (color == PINK) {
        pinkButton -> label("@+5square");
    }
    else if (color == WHITE) {
        whiteButton -> label("@+5square");
    }
    else if (color == LIGHT_GREY) {
        lightGreyButton -> label("@+5square");
    }
    else if (color == DARK_GREY) {
        darkGreyButton -> label("@+5square");
    }
    else if (color == BLACK) {
        blackButton -> label("@+5square");
    }
}

// Selects a color
void ColorSelector::onClick(bobcat::Widget* sender) {
    usingCustomColor = false;

    deselectAllColors();

    // Finds which color button was clicked
    if (sender == redButton) {
        color = RED;
    }
    else if (sender == orangeButton) { 
        color = ORANGE;
    }
    else if (sender == yellowButton) { 
        color = YELLOW;
    }
    else if (sender == greenButton) {  
        color = GREEN;
    }
    else if (sender == blueButton) {   
        color = BLUE;
    }
    else if (sender == indigoButton) {
        color = INDIGO;
    }
    else if (sender == violetButton) {
        color = VIOLET;
    }
    else if (sender == pinkButton) {   
        color = PINK;
    }
    else if (sender == whiteButton) { 
        color = WHITE;
    }
    else if (sender == lightGreyButton) {
        color = LIGHT_GREY;
    }
    else if (sender == darkGreyButton) {  
        color = DARK_GREY;
    }
    else if (sender == blackButton) {      
        color = BLACK;
    }

    visualizeSelectedColor();

    Color c = getColor();

    int redInt = int(c.getR() * 255 + 0.5);
    int greenInt = int(c.getG() * 255 + 0.5);
    int blueInt = int(c.getB() * 255 + 0.5);
    
    ((Fl_Input*)redColorValue) -> value(std::to_string(redInt).c_str());
    ((Fl_Input*)greenColorValue) -> value(std::to_string(greenInt).c_str());
    ((Fl_Input*)blueColorValue) -> value(std::to_string(blueInt).c_str());

    redraw();

    if (onChangeCb) {
        onChangeCb(this);
    }
}

// Retrieves the current color if its preset or a custom RGB
Color ColorSelector::getColor() const {
    if (usingCustomColor) {
        return Color(lastConfirmedR/255.0, lastConfirmedG/255.0, lastConfirmedB/255.0);
    }

    if (color == RED) {
        return Color(255/255.0, 0/255.0, 0/255.0);
    }
    else if (color == ORANGE) {
        return Color(255/255.0, 127/255.0, 0/255.0);
    }
    else if (color == YELLOW) {
        return Color(255/255.0, 255/255.0, 0/255.0);
    }
    else if (color == GREEN) {
        return Color(0/255.0, 255/255.0, 0/255.0);
    }
    else if (color == BLUE) {
        return Color(0/255.0, 0/255.0, 255/255.0);
    }
    else if (color == INDIGO) {
        return Color(75/255.0, 0/255.0, 130/255.0);
    }
    else if (color == VIOLET) {
        return Color(148/255.0, 0/255.0, 211/255.0);
    }
    else if (color == PINK) {
        return Color(255/255.0, 192/255.0, 203/255.0);
    }
    else if (color == WHITE) {
        return Color(255/255.0, 255/255.0, 255/255.0);
    }
    else if (color == LIGHT_GREY) {
        return Color(211/255.0, 211/255.0, 211/255.0);
    }
    else if (color == DARK_GREY) {
        return Color(169/255.0, 169/255.0, 169/255.0);
    }
    else if (color == BLACK) {
        return Color(0/255.0, 0/255.0, 0/255.0);
    }
    else {
        return Color();
    }
}

// Increments/decrements the RGB values before confirming to use a color
void ColorSelector::onAdjustColor(bobcat::Widget* sender) {
    int r = redColorValue->value();
    int g = greenColorValue->value();
    int b = blueColorValue->value();

    if (sender == increaseRedButton) {
        r = r + 1;
    }
    else if (sender == decreaseRedButton){   
        r = r - 1;
    }
    else if (sender == increaseGreenButton){
        g = g + 1;
    }
    else if (sender == decreaseGreenButton){
        g = g -1;
    }
    else if (sender == increaseBlueButton){
        b = b + 1;
    }
    else if (sender == decreaseBlueButton){
        b = b - 1;
    }

    r = clampInt(r, 0, 255);
    g = clampInt(g, 0, 255);
    b = clampInt(b, 0, 255);

    ((Fl_Input*)redColorValue) -> value(std::to_string(r).c_str());
    ((Fl_Input*)greenColorValue) -> value(std::to_string(g).c_str());
    ((Fl_Input*)blueColorValue) -> value(std::to_string(b).c_str());
}

// Clears the custom RGB input fields
void ColorSelector::onClearInputs(bobcat::Widget*) {
    ((Fl_Input*)redColorValue) -> value("");
    ((Fl_Input*)greenColorValue) -> value("");
    ((Fl_Input*)blueColorValue) -> value("");
}

// Applies the custom RGB values or falls back to the closest color present
void ColorSelector::onConfirmColor(bobcat::Widget*) {
    if (redColorValue -> empty() || greenColorValue -> empty() || blueColorValue -> empty()) {
        showMessage("Select or enter RGB of a color.");
        return;
    }

    lastConfirmedR = clampInt(redColorValue  -> value(), 0, 255);
    lastConfirmedG = clampInt(greenColorValue-> value(), 0, 255);
    lastConfirmedB = clampInt(blueColorValue -> value(), 0, 255);

    usingCustomColor = false;
    
    if (lastConfirmedR == 255 && lastConfirmedG == 0 && lastConfirmedB == 0) {
        color = RED;
    }
    else if (lastConfirmedR == 255 && lastConfirmedG == 127 && lastConfirmedB == 0) {
        color = ORANGE;
    }
    else if (lastConfirmedR == 255 && lastConfirmedG == 255 && lastConfirmedB == 0) {
        color = YELLOW;
    }
    else if (lastConfirmedR == 0 && lastConfirmedG == 255 && lastConfirmedB == 0) {
        color = GREEN;
    }
    else if (lastConfirmedR == 0 && lastConfirmedG == 0 && lastConfirmedB == 255) {
        color = BLUE;
    }
    else if (lastConfirmedR ==  75 && lastConfirmedG == 0 && lastConfirmedB == 130) {
        color = INDIGO;
    }
    else if (lastConfirmedR == 148 && lastConfirmedG == 0 && lastConfirmedB == 211) {
        color = VIOLET;
    }
    else if (lastConfirmedR == 255 && lastConfirmedG == 192 && lastConfirmedB == 203) {
        color = PINK;
    }
    else if (lastConfirmedR == 255 && lastConfirmedG == 255 && lastConfirmedB == 255) {
        color = WHITE;
    }
    else if (lastConfirmedR == 211 && lastConfirmedG == 211 && lastConfirmedB == 211) {
        color = LIGHT_GREY;
    }
    else if (lastConfirmedR == 169 && lastConfirmedG == 169 && lastConfirmedB == 169) {
        color = DARK_GREY;
    }
    else if (lastConfirmedR == 0 && lastConfirmedG == 0 && lastConfirmedB == 0) {
        color = BLACK;
    }
    else {
      usingCustomColor = true;
    }
    
    visualizeSelectedColor();

    if (onChangeCb) {
        onChangeCb(this);
    }

    redraw();
}

// Refreshes the text inputs so that they match the current selected color
void ColorSelector::updateRGBInputs() {
    Color c = getColor();

    int redVal = int(c.getR() * 255 + 0.5);
    int greenVal = int(c.getG() * 255 + 0.5);
    int blueVal = int(c.getB() * 255 + 0.5);

    ((Fl_Input*)redColorValue)  -> value(std::to_string(redVal).c_str());
    ((Fl_Input*)greenColorValue)-> value(std::to_string(greenVal).c_str());
    ((Fl_Input*)blueColorValue) -> value(std::to_string(blueVal).c_str());
}

// Initializes the buttons, sliders, and states of the default colors
ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    // Creates a button for the colors that are present on Canvas
    redButton = new Button(x + 10, y + 50, 50, 50, "");
    orangeButton = new Button(x + 70, y + 50, 50, 50, "");
    yellowButton = new Button(x + 130, y + 50, 50, 50, "");
    greenButton = new Button(x + 190, y + 50, 50, 50, "");
    blueButton = new Button(x + 10, y + 110, 50, 50, "");
    indigoButton = new Button(x + 70, y + 110, 50, 50, "");
    violetButton = new Button(x + 130, y + 110, 50, 50, "");
    pinkButton = new Button(x + 190, y + 110, 50, 50, "");
    whiteButton = new Button(x + 10, y + 170, 50, 50, "");
    lightGreyButton = new Button(x + 70, y + 170, 50, 50, "");
    darkGreyButton = new Button(x + 130, y + 170, 50, 50, "");
    blackButton = new Button(x + 190, y + 170, 50, 50, "");

    // Sets up the RGB values for the input fields and labels
    redColorValue = new IntInput(300, 520, 100, 30, "");
    greenColorValue = new IntInput(300, 580, 100, 30, "");
    blueColorValue = new IntInput(300, 640, 100, 30, "");

    // Controls the Clear and Confirm buttons
    clearButton = new Button(510, 520, 175, 60, "Clear");
    clearButton -> labelsize(36);
    clearButton -> labelfont(FL_HELVETICA);
    clearButton -> color(fl_rgb_color(245, 233, 211));
    clearButton -> labelcolor(fl_rgb_color(30, 41, 45));
    confirmButton = new Button(510, 610, 175, 60, "Confirm");
    confirmButton -> labelsize(36);
    confirmButton -> labelfont(FL_HELVETICA);
    confirmButton -> color(fl_rgb_color(245, 233, 211));
    confirmButton -> labelcolor(fl_rgb_color(30, 41, 45));

    // Initializes the default selection of color to RED
    color = RED;
    usingCustomColor = false;
    lastConfirmedR = 255;
    lastConfirmedG = 0;
    lastConfirmedB = 0;
    onClick(redButton); 

    // Creates and styles the section of labels and inputs
    colorsText = new TextBox(10, 470, 700, 25, "Colors");
    colorsText -> labelsize(18);
    colorsText -> labelcolor(fl_rgb_color(30, 41, 45));
    colorsText -> labelfont(FL_HELVETICA_BOLD);
    redColorText = new TextBox(300, 495, 450, 30, "R");
    redColorText -> labelsize(18);
    redColorText -> labelcolor(fl_rgb_color(30, 41, 45));
    redColorText -> labelfont(FL_HELVETICA_BOLD);
    redColorValue -> labelsize(18);
    redColorValue -> color(fl_rgb_color(245, 233, 211));
    greenColorText = new TextBox(300, 555, 450, 30, "G");
    greenColorText -> labelsize(18);
    greenColorText -> labelcolor(fl_rgb_color(30, 41, 45));
    greenColorText -> labelfont(FL_HELVETICA_BOLD);
    greenColorValue -> color(fl_rgb_color(245, 233, 211));
    greenColorValue -> labelsize(18);
    blueColorText = new TextBox(300, 615, 450, 30, "B");
    blueColorText -> labelsize(18);
    blueColorText -> labelcolor(fl_rgb_color(30, 41, 45));
    blueColorText -> labelfont(FL_HELVETICA_BOLD);
    blueColorValue -> labelsize(18);
    blueColorValue -> color(fl_rgb_color(245, 233, 211));

    // Makes an increase and decrease button to adjust RGB values
    increaseRedButton = new Button(415, 520, 30, 30, "+");
    increaseRedButton -> labelfont(FL_HELVETICA);
    increaseRedButton -> labelcolor(fl_rgb_color(30, 41, 45));
    increaseRedButton -> color(fl_rgb_color(245, 233, 211));
    increaseRedButton -> labelsize(18);
    decreaseRedButton = new Button(455, 520, 30, 30, "-");
    decreaseRedButton -> labelfont(FL_HELVETICA);
    decreaseRedButton -> labelcolor(fl_rgb_color(30, 41, 45));
    decreaseRedButton -> color(fl_rgb_color(245, 233, 211));
    increaseGreenButton = new Button(415, 580, 30, 30, "+");
    increaseGreenButton -> labelfont(FL_HELVETICA);
    increaseGreenButton -> labelcolor(fl_rgb_color(30, 41, 45));
    increaseGreenButton -> color(fl_rgb_color(245, 233, 211));
    decreaseGreenButton = new Button(455, 580, 30, 30, "-");
    decreaseGreenButton -> labelfont(FL_HELVETICA);
    decreaseGreenButton -> labelcolor(fl_rgb_color(30, 41, 45));
    decreaseGreenButton -> color(fl_rgb_color(245, 233, 211));
    increaseBlueButton = new Button(415, 640, 30, 30, "+");
    increaseBlueButton -> labelfont(FL_HELVETICA);
    increaseBlueButton -> labelcolor(fl_rgb_color(30, 41, 45));
    increaseBlueButton -> color(fl_rgb_color(245, 233, 211));
    decreaseBlueButton = new Button(455, 640, 30, 30, "-");
    decreaseBlueButton -> labelfont(FL_HELVETICA);
    decreaseBlueButton -> labelcolor(fl_rgb_color(30, 41, 45));
    decreaseBlueButton -> color(fl_rgb_color(245, 233, 211));

    // Adds color and border for the default 12 colors' buttons
    redButton->color(fl_rgb_color(255, 0, 0));
    redButton->labelcolor(FL_WHITE);
    orangeButton->color(fl_rgb_color(255, 127, 0));
    orangeButton->labelcolor(FL_WHITE);
    yellowButton->color(fl_rgb_color(255, 255, 0));
    yellowButton->labelcolor(FL_WHITE);
    greenButton->color(fl_rgb_color(0, 255, 0));
    greenButton->labelcolor(FL_WHITE);
    blueButton->color(fl_rgb_color(0, 0, 255));
    blueButton->labelcolor(FL_WHITE);
    indigoButton->color(fl_rgb_color(75, 0, 130));
    indigoButton->labelcolor(FL_WHITE);
    violetButton->color(fl_rgb_color(148, 0, 211));
    violetButton->labelcolor(FL_WHITE);
    pinkButton->color(fl_rgb_color(255, 192, 203));
    pinkButton->labelcolor(FL_WHITE);
    whiteButton->color(fl_rgb_color(255, 255, 255));
    whiteButton->labelcolor(FL_WHITE);
    lightGreyButton->color(fl_rgb_color(211, 211, 211));
    lightGreyButton->labelcolor(FL_WHITE);
    darkGreyButton->color(fl_rgb_color(169, 169, 169));
    darkGreyButton->labelcolor(FL_WHITE);
    blackButton->color(fl_rgb_color(0, 0, 0));
    blackButton->labelcolor(FL_WHITE);

    // Initializes the RGB text inputs to default values
    ((Fl_Input*)redColorValue) -> value("255");
    ((Fl_Input*)greenColorValue) -> value("0");
    ((Fl_Input*)blueColorValue) -> value("0");

    // Styles this Group container
    box(FL_FLAT_BOX);
    Group::color(fl_rgb_color(134, 158, 164));

    // Callbacks the register event
    ON_CLICK(redButton, ColorSelector::onClick);
    ON_CLICK(orangeButton, ColorSelector::onClick);
    ON_CLICK(yellowButton, ColorSelector::onClick);
    ON_CLICK(greenButton, ColorSelector::onClick);
    ON_CLICK(blueButton, ColorSelector::onClick);
    ON_CLICK(indigoButton, ColorSelector::onClick);
    ON_CLICK(violetButton, ColorSelector::onClick);
    ON_CLICK(pinkButton, ColorSelector::onClick);
    ON_CLICK(whiteButton, ColorSelector::onClick);
    ON_CLICK(lightGreyButton, ColorSelector::onClick);
    ON_CLICK(darkGreyButton, ColorSelector::onClick);
    ON_CLICK(blackButton, ColorSelector::onClick);
    ON_CLICK(increaseRedButton, ColorSelector::onAdjustColor);
    ON_CLICK(decreaseRedButton, ColorSelector::onAdjustColor);
    ON_CLICK(increaseGreenButton, ColorSelector::onAdjustColor);
    ON_CLICK(decreaseGreenButton, ColorSelector::onAdjustColor);
    ON_CLICK(increaseBlueButton, ColorSelector::onAdjustColor);
    ON_CLICK(decreaseBlueButton, ColorSelector::onAdjustColor);
    ON_CLICK(clearButton, ColorSelector::onClearInputs);
    ON_CLICK(confirmButton, ColorSelector::onConfirmColor);   

    // Highlights the current functions selected as default
    visualizeSelectedColor();
}
