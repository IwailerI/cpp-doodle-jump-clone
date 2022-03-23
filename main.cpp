#include "allegro/Game.h"

int main() {
    AllegroBase::InitAllegroAddons();
    Game *al = &Game::Instance();
    al->Run();
    return 0;
}
