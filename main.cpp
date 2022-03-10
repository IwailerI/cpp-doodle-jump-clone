#include "allegro/Allegro.h"
#include "ScreenSaver.h"
#include "PhysicsServer.h"
#include "Player.h"
#include "objects/platforms/Platform.h"

void setup() {
    ScreenSaver &ss = ScreenSaver::Instance();
    PhysicsServer &ps = PhysicsServer::Instance();

    auto *player = new Player(Vector2(200, 200));
    ss.Add(player);
    ps.RegisterPlayer(player);

    auto *platform = new Platform(Vector2(200, 500));
    ss.Add(platform);
    ps.Add(platform);

    platform = new Platform(Vector2(150, 700));
    ss.Add(platform);
    ps.Add(platform);

}

int main() {
    al_init();

    Allegro *al = &Allegro::Instance();

    setup();

    al->Run();


    return 0;
}
