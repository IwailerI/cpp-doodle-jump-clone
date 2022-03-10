//
// Created by wailer on 22/02/2022.
//

#include "Allegro.h"

Allegro::Allegro(): _screen_saver(ScreenSaver::Instance()), _physics_server(PhysicsServer::Instance()) {
    Init(SCREEN_W, SCREEN_H, FPS);
}

void Allegro::Fps() {
    _physics_server.Update();
    _screen_saver.Update();
}

void Allegro::Draw() {
    _screen_saver.Draw();
}

void Allegro::Run() {
    AllegroBase::Run();
}
