//
// Created by wailer on 03/04/2022.
//

#include "EnemyFactory.h"

// generates a new random enemy, positioned on random (on screen) x and y=height
Enemy *EnemyFactory::GetRandomEnemy(double height) {
    Enemy *p = nullptr;

    switch (std::rand()%4) {
        case 0:
            p = new Enemy(Vector2());
            break;
        case 1:
            p = new BigEnemy(Vector2());
            break;
        case 2:
            p = new SmallEnemy(Vector2());
            break;
        case 3:
            p = new FlyingEnemy(Vector2());
            break;
    }

    p->setPosition(Vector2(util::randf(0, SCREEN_W - p->GetImageSize().x), height));

    return p;
}
