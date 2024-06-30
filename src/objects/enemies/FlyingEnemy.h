//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_FLYINGENEMY_H
#define PROJECT_FLYINGENEMY_H

#include "Enemy.h"

class FlyingEnemy : public Enemy {
   public:
    explicit FlyingEnemy(const Vector2 &position) : Enemy() {
        _position = position;
        _sprite = ResourceManager::Instance().sprite_enemy_flying;
        _victory_sprite =
            ResourceManager::Instance().sprite_enemy_flying_victory;
        _death_sprite = ResourceManager::Instance().sprite_enemy_flying_dead;
        _player_interaction = PlayerInteraction::KillBounce;
    };
    ~FlyingEnemy() override = default;
};

#endif  // PROJECT_FLYINGENEMY_H
