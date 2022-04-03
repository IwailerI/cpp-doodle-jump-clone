//
// Created by wailer on 03/04/2022.
//

#include "EnemyFactory.h"

// generates a new random enemy, positioned on random (on screen) x and y=height
Enemy *EnemyFactory::GetRandomEnemy(double height) {
    Enemy *p = nullptr;

    switch (std::rand()%1) {
        case 0:
            p = new Enemy(Vector2());
            break;
    }

    p->setPosition(Vector2(util::randf(0, SCREEN_W - p->GetImageSize().x), height));

    return p;
}
