#include "allegro/Game.h"

int main() {
    al_init();
    Game *al = &Game::Instance();
    al->Run();
    return 0;
}
