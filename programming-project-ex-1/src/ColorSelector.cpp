#include "ColorSelector.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <FL/fl_draw.H>
#include <GL/glext.h>
#include <bobcat_ui/textbox.h>
using namespace bobcat;

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

void ColorSelector::visualizeSelectedColor() {
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

void ColorSelector::onClick(bobcat::Widget* sender) {
    deselectAllColors();

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

    //
    Color selectedColor = getColor();

    int redInteger = selectedColor.getR() * 255.0 + 0.5;
    int greenInteger = selectedColor.getG() * 255.0 + 0.5;
    int blueInteger = selectedColor.getB() * 255.0 + 0.5;

    std::string redString = std::to_string(redInteger);
    std::string greenString = std::to_string(greenInteger);
    std::string blueString = std::to_string(blueInteger);


    ((Fl_Input*)redColorValue) -> value(redString.c_str());
    ((Fl_Input*)greenColorValue) -> value(greenString.c_str());
    ((Fl_Input*)blueColorValue) -> value(blueString.c_str());


    //

    redraw();

    if (onChangeCb) {
        onChangeCb(this);
    }
}

Color ColorSelector::getColor() const {
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

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group (x, y, w, h) {
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

    colorsText = new TextBox(10, 470, 700, 25, "Colors");
    colorsText -> labelsize(18);
    colorsText -> labelcolor(FL_BLACK);
    colorsText -> labelfont(FL_HELVETICA_BOLD);

    
    //
    // bobcat::TextBox* redColorText;
    //bobcat::IntInput* redColorValue;

    // bobcat::TextBox* greenColorText;
    // bobcat::TextBox* blueColorText;

    redColorText = new TextBox(300, 500, 450, 50, "R: ");
    redColorText -> labelsize(36);
    redColorText -> labelcolor(FL_BLACK);
    redColorText -> labelfont(FL_HELVETICA);
    redColorValue = new IntInput(350, 500, 100, 50, "");
    redColorValue -> labelsize(36);

    greenColorText = new TextBox(300, 560, 450, 50, "G: ");
    greenColorText -> labelsize(36);
    greenColorText -> labelcolor(FL_BLACK);
    greenColorText -> labelfont(FL_HELVETICA);
    greenColorValue = new IntInput(350, 560, 100, 50, "");
    greenColorValue -> labelsize(36);

    blueColorText = new TextBox(300, 620, 450, 50, "B: ");
    blueColorText -> labelsize(36);
    blueColorText -> labelcolor(FL_BLACK);
    blueColorText -> labelfont(FL_HELVETICA);
    blueColorValue = new IntInput(350, 620, 100, 50, "");
    blueColorValue -> labelsize(36);


    color = RED;

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

    visualizeSelectedColor();

    onClick(redButton);

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
}
