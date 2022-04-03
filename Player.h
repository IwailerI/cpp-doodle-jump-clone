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
    bool _is_dead = false;

    Vector2 _getDimensions(bool alternative) const override;

public:
    explicit Player(Vector2 position);

    void onCollision(Collider *col) override;

    const Vector2 &getVelocity() const;
    void setVelocity(const Vector2 &velocity);

    void die();

    Vector2 getPosition() const override;

    bool isDead() const { return _is_dead; }
    bool isCompletelyDead() {return isDead() && _position.y > SCREEN_H * 1.3;}

    bool is_right_held = false;
    bool is_left_held = false;
};


#endif //PROJECT_PLAYER_H
