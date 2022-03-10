//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include "objects/Sprite.h"
#include "objects/Collider.h"
//#include "PhysicsServer.h"
#include "objects/platforms/Platform.h"
#include "allegro/Allegro.h"
#include <iostream> // debug TODO remove

const double GRAVITY = 1.5;
const double JUMP_VELOCITY = 30;

class Player: public Sprite, public Collider {
protected:
    Vector2 _velocity;

    void _update() override; // also handles input
    // TODO: override _draw(), to play custom animations
    // TODO: make player hitbox a little taller then sprite

public:
    explicit Player(Vector2 position);

    void onCollision(Collider *col) override;

    const Vector2 &getVelocity() const;
    void setVelocity(const Vector2 &velocity);

    const Vector2 &getPosition() const override;
    const Vector2 &getDimensions() const override;

    Vector2 getColliderVelocity() const override;
};


#endif //PROJECT_PLAYER_H
