#include "ScreenSaver.h"
#include "objects/simpleShapes/ColorRect.h"


int size = 10;
ScreenSaver ss = ScreenSaver::Instance();

void setup() {
    ColorRect *c = new ColorRect(Vector2(200, 200), al_map_rgb(255,255,255), Vector2(50, 100));
    ss.Add(c);
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
