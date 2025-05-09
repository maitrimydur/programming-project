# Programming Project
The programming project is a Paint Application that is a simple drawing program built with the Bobcat UI framework and OpenGL. It lets users draw smooth freehand strokes––scribbles––place geometric shapes––rectangle, circle, triangle, polygon––and then click any object to move, resize, or change its color. An eraser tool and a clear-screen action removes unwanted marks, while an undo function reverses the last change. Layer ordering––bring to front/send to back––keeps overlapping shapes organized. Under the hood, all shapes and scribbles live in one shared list, and toolbar clicks and mouse events––defined by **TOOL** and **ACTION** enums––drive the Canvas methods that render and manipulate objects. This structures makes the code easy to extend and maintain.

## Code Structure
All source files are under **src/**, organized as follows:
**Application.cpp:** 
- Instantiates Window, Canvas, Toolbar, ColorSelector.
- Constructor sets up window and widgets.
- Event callbacks: onCanvasMouseDown, onCanvasDrag, onCanvasMouseUp.
- Maps TOOL enum (PENCIL, ERASER, SELECT, RECTANGLE, CIRCLE, TRIANGLE, POLYGON) to Canvas methods, and ACTION enum (UNDO, CLEAR, BRING_TO_FRONT, SEND_TO_BACK, RESIZE_UP, RESIZE_DOWN) to toolbar actions.
**Application.h**
- Declaration of Application class and event handlers.
**Canvas.cpp**
- Implements Canvas class––extends bobcat::Canvas_.
- Stores all Shape* and Scribble* in a single vector.
- Rendering logic: render() draws each shape via OpenGL.
- Interaction methods:
    - startScribble/addToScribble/finishScribble.
    - addRectangle/Circle/Triangle/Polygon
    - selectAt / moveSelected / resizeSelectedUp/Down
    - recolorSelected / bringToFront / sendToBack
    - eraseAt / clear / undo
**Canvas.h**
- Declaration of Canvas class and its public API.
**Toolbar.cpp**
- Implements Toolbar widget (extends Group).
- Buttons for each TOOL and ACTION.
- onClick(): updates `tool` or `action` enums, calls onChangeCb.
- visualizeSelectedTool(): highlights current selection.
**Toolbar.h**
- Declaration of Toolbar class, TOOL and ACTION
**ColorSelector.cpp**
- Declaration of Toolbar class, TOOL and ACTION getters.
- Three sliders for R, G, B.
- getColor(): returns current Color.
- Fires onChange to recolor selection.
**ColorSelector.h**
- Declaration of ColorSelector widget.
