//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_ENEMYFACTORY_H
#define PROJECT_ENEMYFACTORY_H

#include "Enemy.h"
#include "BigEnemy.h"
#include "FlyingEnemy.h"
#include "SmallEnemy.h"
#include "../../util/utils.h"

class EnemyFactory {
public:
    static Enemy *GetRandomEnemy(double height);
};

#endif //PROJECT_ENEMYFACTORY_H
