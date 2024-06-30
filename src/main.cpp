#include "allegro/Game.h"

int main() {
    if (!AllegroBase::InitAllegroAddons()) return 1;

    Game &game = Game::Instance();
    game.Run();

    return 0;
}
