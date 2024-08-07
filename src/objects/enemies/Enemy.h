//
// Created by wailer on 23/03/2022.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "../../ResourceManager.h"
#include "../Collider.h"
#include "../Sprite.h"

class Enemy : public Sprite, public Collider {
   protected:
    Vector2 _getColliderPosition(bool alternative) const override;
    Vector2 _getDimensions(bool alternative) const override;

    img _victory_sprite;
    img _death_sprite;

    virtual void _victory();

    virtual void _delete();

    Vector2 _death_velocity;

    bool _is_dead = false;

    void _update() override;

    Enemy() : Sprite(){};

   public:
    explicit Enemy(Vector2 position);
    ~Enemy() override = default;

    void onCollision(std::shared_ptr<Collider> col) override;

    virtual void die();
    bool isDead() const { return _is_dead; };
};

#endif  // PROJECT_ENEMY_H
