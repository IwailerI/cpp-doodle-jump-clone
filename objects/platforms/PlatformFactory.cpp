//
// Created by wailer on 03/04/2022.
//

#include "PlatformFactory.h"

Content *PlatformFactory::_random_content() {
    if (util::randf(0, 1) <= SPRING_CHANCE) {
        return new Spring();
    }
    return nullptr;
}

Platform *PlatformFactory::_random_platform(bool fake) {
    if (fake) {
        switch (std::rand()%1) {
            case 0:
                return new FakePlatform(Vector2());
                break;
        }
    } else {
        switch (std::rand()%10) {
            case 0:
                return new MovingPlatform(Vector2());
                break;
            default:
                return new Platform(Vector2());
                break;
        }
    }
    return nullptr;
}

// generates a new random platform, positioned on random (on screen) x and y=height
Platform *PlatformFactory::GetRandomPlatform(double height, bool fake) {
    Platform *p = _random_platform(fake);

    p->setPosition(Vector2(util::randf(0, SCREEN_W - p->GetImageSize().x), height));

    if (!fake)
        p->addContent(_random_content());

    return p;
}
