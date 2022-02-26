#include "allegro/Allegro.h"
#include "ScreenSaver.h"

#include "shapes/Shape.h"
#include "shapes/Square.h"
#include "shapes/Circle.h"

int size = 10;
ScreenSaver ss = ScreenSaver::Instance();

void setup() {
    PShape shape;
    for (int i = 0; i < size/2; i++) {
        shape = new Square();
        shape->Randomize();
        ss.Add(shape);
    }

    for (int i = size/2; i < size; i++) {
        shape = new Circle();
        shape->Randomize();
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
