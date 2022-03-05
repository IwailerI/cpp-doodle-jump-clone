//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include "objects/Sprite.h"
#include "objects/Collider.h"

#include <iostream> // debug TODO remove

class Player: public Sprite, public Collider {
protected:
    Vector2 _velocity;

    void _update() override; // also handles input
    // TODO: override _draw(), to play custom animations

public:
    void onCollision(Collider *col) override;

};


#endif //PROJECT_PLAYER_H
