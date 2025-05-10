#ifndef ENUMS_H
#define ENUMS_H

// Tools that are available to draw and to change modes 
enum TOOL {PENCIL, ERASER, CIRCLE, TRIANGLE, RECTANGLE, POLYGON, SELECT};

// Colors that are available to select with a custom color maker 
enum COLOR {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET, PINK, WHITE, LIGHT_GREY, DARK_GREY, BLACK, CUSTOM};

// Actions that canvas commands when triggered by toolbar
enum ACTION {NONE, UNDO, CLEAR, BRING_TO_FRONT, SEND_TO_BACK, RESIZE_UP, RESIZE_DOWN};

#endif
