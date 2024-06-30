//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_SMALLENEMY_H
#define PROJECT_SMALLENEMY_H

#include "Enemy.h"

class SmallEnemy : public Enemy {
   public:
    explicit SmallEnemy(const Vector2 &position) : Enemy() {
        _position = position;
        _sprite = ResourceManager::Instance().sprite_enemy_small;
        _victory_sprite =
            ResourceManager::Instance().sprite_enemy_small_victory;
        _death_sprite = ResourceManager::Instance().sprite_enemy_small_dead;
        _player_interaction = PlayerInteraction::KillBounce;
    };
    ~SmallEnemy() override = default;
};

#endif  // PROJECT_SMALLENEMY_H
