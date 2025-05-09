# Programming Project

This paint application, built with the Bobcat UI framework and OpenGL, offers freehand drawing, shape creation, object selection and manipulation, color selection, and action controls. It uses a **TOOL** enum (`PENCIL`, `ERASER`, `SELECT`, `RECTANGLE`, `CIRCLE`, `TRIANGLE`, `POLYGON`) to switch modes and an **ACTION** enum (`NONE`, `UNDO`, `CLEAR`, `BRING_TO_FRONT`, `SEND_TO_BACK`, `RESIZE_UP`, `RESIZE_DOWN`) to perform canvas operations. Users can draw continuous scribbles, place geometric shapes with a click, erase or clear the canvas, undo the last change, reorder or resize objects, and apply color via twelve preset swatches (`RED`, `ORANGE`, `YELLOW`, `GREEN`, `BLUE`, `INDIGO`, `VIOLET`, `PINK`, `WHITE`, `LIGHT_GREY`, `DARK_GREY`, `BLACK`) or custom RGB values.

## **Code Structure**

All source code resides in `src/`, organized as follows:

- **Application:** (`Application.cpp`, `Application.h`): Sets up the window, instantiates the `Canvas`, `Toolbar`, and `ColorSelector`, and maps mouse and toolbar events to methods based on the `TOOL` and `ACTION` enums.
- **Canvas:** (`Canvas.cpp`, `Canvas.h`): Manages a single container of `Shape*` and `Scribble*` objects, handles OpenGL rendering, and implements methods such as `startScribble`, `addRectangle`, `selectAt`, `moveSelected`, `resizeSelectedUp/Down`, `recolorSelected`, `bringToFront`, `sendToBack`, `eraseAt`, `clear`, and `undo`.
- **Toolbar:** (`Toolbar.cpp`, `Toolbar.h`): Defines buttons for each tool and action, handles clicks to update the current `tool` or `action` enum, and visually highlights the active button.
- **ColorSelector:** (`ColorSelector.cpp`, `ColorSelector.h`): Implements an RGB slider widget with twelve preset color swatches and custom RGB inputs, firing change events to recolor the selected object.
- **Enums:** (`Enums.h`): Defines the `TOOL`, `ACTION`, and `COLOR` enums.
- **Shapes:** (`shapes/`): Contains `Shape.h` (abstract base class), `Rectangle.cpp/h`, `Circle.cpp/h`, `Triangle.cpp/h`, `Polygon.cpp/h` for geometric shapes, `Scribble.cpp/h` for freehand strokes, and `Point.cpp/h` as the primitive drawing unit.

## **Usage**

Once the executable is running:

1. Select a **tool** from the toolbar:
   - **PENCIL**: Click and drag to draw a single scribble object.
   - **RECTANGLE**, **CIRCLE**, **TRIANGLE**, **POLYGON**: Click the canvas to place the shape.
   - **ERASER**: Click an object to delete it.
   - **SELECT**: Click an object to activate move, resize, or recolor commands.
2. **Move** a selected object by dragging it on the canvas.
3. **Resize** using the **RESIZE_UP** (plus) and **RESIZE_DOWN** (minus) buttons.
4. **Recolor** the selected object by choosing one of the twelve swatches or entering custom RGB values in the sliders.
5. **BRING_TO_FRONT** or **SEND_TO_BACK** to change layer ordering.
6. **UNDO** to reverse the last action.
7. **CLEAR** to remove all objects from the canvas.
