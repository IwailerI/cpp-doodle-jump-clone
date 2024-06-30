//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_ENEMYFACTORY_H
#define PROJECT_ENEMYFACTORY_H

#include "../../util/utils.h"
#include "BigEnemy.h"
#include "Enemy.h"
#include "FlyingEnemy.h"
#include "SmallEnemy.h"

class EnemyFactory {
   public:
    static std::shared_ptr<Enemy> GetRandomEnemy(double height);
};

#endif  // PROJECT_ENEMYFACTORY_H
