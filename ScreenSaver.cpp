//
// Created by wailer on 22/02/2022.
//

#include "ScreenSaver.h"

ScreenSaver::ScreenSaver(): _size(0) {
    memset(_bodies, 0, sizeof(_bodies));
}

ScreenSaver::~ScreenSaver() {
    for (int i = 0; i < _size; i++) {
        delete _bodies[i];
        _bodies[i] = nullptr;
    }
}

void ScreenSaver::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
//    fancy trails
//    al_draw_filled_rectangle(0,0,SCREEN_W,SCREEN_H, al_map_rgba(0,0,0,50));
    for (int i = 0; i < _size; i++) {
        _bodies[i]->Draw();
    }
}

void ScreenSaver::Update() {
//    move bodies
    for (int i = 0; i < _size; i++) {
        _bodies[i]->Move();
        _bodies[i]->setCollided(false); // reset collided
    }

//    handle collision of bodies
//    O(n^2), but with small sizes (100) should be fine
    Vector2 normal, p1, p2;
    for (int i = 0; i < _size; i++) {
        _bodies[i]->setCollided(true); // mark that we have done all calculations for this body
        // screen borders collisions
        normal = _bodies[i]->GetBoundaries();
        // Vector2(0,0) is returned, not calculated, so it's ok to compare it with != or ==
        if (normal != Vector2(0 ,0)) {
            _bodies[i]->Collide(normal);
            break; // don't collide with other bodies, walls are priority
        }
        for (int j = 0; j < _size; j++) {
            if (i==j || _bodies[j]->hasCollided()) continue;
            p1 = _bodies[i]->GetClosestPointTo(_bodies[j]->getPosition());
            p2 = _bodies[j]->GetClosestPointTo(p1);
            // it's okay to compare double based values here,
            // because in most cases we are returning pos from GetClosestPointTo
            // instead of calculating it
            if (p1 == p2) {
                // we have a collision
                _bodies[i]->Collide(_bodies[i]->GetSurfaceNormalAt(p2));
                _bodies[j]->Collide(_bodies[j]->GetSurfaceNormalAt(p2));
            }
        }
    }
}

void ScreenSaver::Add(PShape s) {
    if (_size >= MAX_BODIES) return;
    _bodies[_size++] = s;
}

void ScreenSaver::Remove(int i) {
    _bodies[i] = _bodies[_size-1];
    delete _bodies[_size-1];
    _bodies[_size--] = nullptr;
}
