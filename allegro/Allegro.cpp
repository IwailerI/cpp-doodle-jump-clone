//
// Created by wailer on 22/02/2022.
//

#include "Allegro.h"

void Allegro::Fps() {
    update();
}

void Allegro::Draw() {
    draw();
}

Allegro::Allegro(void (*draw)(), void (*update)()) : draw(draw), update(update) {}

Allegro::~Allegro() {

}