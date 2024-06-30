//
// Created by wailer on 03/04/2022.
//

#include "EnemyFactory.h"

// generates a new random enemy, positioned on random (on screen) x and y=height
std::shared_ptr<Enemy> EnemyFactory::GetRandomEnemy(double height) {
    std::shared_ptr<Enemy> p = nullptr;

    switch (std::rand() % 4) {
        case 0:
            p = std::make_shared<Enemy>(Vector2());
            break;
        case 1:
            p = std::make_shared<BigEnemy>(Vector2());
            break;
        case 2:
            p = std::make_shared<SmallEnemy>(Vector2());
            break;
        case 3:
            p = std::make_shared<FlyingEnemy>(Vector2());
            break;
    }

    p->setPosition(
        Vector2(util::randf(0, SCREEN_W - p->GetImageSize().x), height));

    return p;
}
