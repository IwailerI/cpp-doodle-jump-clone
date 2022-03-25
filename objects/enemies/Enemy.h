//
// Created by wailer on 23/03/2022.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "../Sprite.h"
#include "../Collider.h"
#include "../../ResourceManager.h"

class Enemy: public Sprite, public Collider {
public:
    Vector2 getPosition() const override;
    Vector2 getDimensions() const override;
    void onCollision(Collider *col) override;

    explicit Enemy(Vector2 position);

    void die();
};


#endif //PROJECT_ENEMY_H
