#include "allegro/Allegro.h"
#include "ScreenSaver.h"
#include "shapes/ShapeFactory.h"

#include "shapes/Shape.h"

int size = 10;
ScreenSaver ss = ScreenSaver::Instance();

void setup() {
    PShape shape;
    for (int i = 0; i < size/2; i++) {
        shape = ShapeFactory::RandomSquare();
        ss.Add(shape);
    }

    for (int i = size/2; i < size; i++) {
        shape = ShapeFactory::RandomCircle();
        ss.Add(shape);
    }
}

void update(){
    ss.Update();
}

void draw() {
    ss.Draw();
}

int main() {
    srand(time(0));

    Allegro allegro = Allegro(draw, update);

    allegro.Init(SCREEN_W, SCREEN_H, FPS);

    setup();

    allegro.Run();

    return 0;
}
