//
// Created by wailer on 03/04/2022.
//

#include "PlatformFactory.h"

std::shared_ptr<Content> PlatformFactory::_random_content() {
    if (util::randf(0, 1) <= SPRING_CHANCE) {
        return std::make_shared<Spring>();
    }
    return nullptr;
}

std::shared_ptr<Platform> PlatformFactory::_random_platform(bool fake) {
    if (fake) {
        if (std::rand() % 1 == 0) {
            return std::make_shared<FakePlatform>(Vector2());
        }
    } else {
        if (std::rand() % 10 == 0) {
            return std::make_shared<MovingPlatform>(Vector2());
        } else {
            return std::make_shared<Platform>(Vector2());
        }
    }
    return nullptr;
}

// generates a new random platform, positioned on random (on screen) x and
// y=height
std::shared_ptr<Platform> PlatformFactory::GetRandomPlatform(double height,
                                                             bool fake) {
    auto p = _random_platform(fake);

    p->setPosition(
        Vector2(util::randf(0, SCREEN_W - p->GetImageSize().x), height));

    if (!fake) p->addContent(_random_content());

    return p;
}
