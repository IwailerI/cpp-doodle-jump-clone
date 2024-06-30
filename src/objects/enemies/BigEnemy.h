//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_BIGENEMY_H
#define PROJECT_BIGENEMY_H

#include "Enemy.h"

class BigEnemy: public Enemy{
public:
    explicit BigEnemy(const Vector2 &position) : Enemy() {
        _position = position;
        _sprite = ResourceManager::Instance().sprite_enemy_large;
        _victory_sprite = ResourceManager::Instance().sprite_enemy_large_victory;
        _death_sprite = ResourceManager::Instance().sprite_enemy_large_dead;
        _player_interaction = KillBounce;
    };
    ~BigEnemy() override = default;
};


#endif //PROJECT_BIGENEMY_H
