//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include "objects/Sprite.h"
#include "objects/Collider.h"
#include "objects/platforms/Platform.h"
#include "ResourceManager.h"
#include <iostream> // debug TODO remove and  make normal death sequance

const double GRAVITY = 1.5;
const double JUMP_VELOCITY = 30;
const double MOVEMENT_SPEED = 10;

class Player: public Sprite, public Collider {
protected:
    Vector2 _velocity;

    void _update() override; // also handles input

public:
    explicit Player(Vector2 position);

    void onCollision(Collider *col) override;

    const Vector2 &getVelocity() const;
    void setVelocity(const Vector2 &velocity);

    Vector2 getColliderVelocity() const override;

    void die();

    Vector2 getPosition() const override;

    Vector2 getDimensions() const override;

    bool is_right_held = false;
    bool is_left_held = false;
};


#endif //PROJECT_PLAYER_H
