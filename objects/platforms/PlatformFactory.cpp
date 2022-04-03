//
// Created by wailer on 03/04/2022.
//

#include "PlatformFactory.h"

Platform *PlatformFactory::_random_platform(bool fake) {
    if (fake) {
        switch (std::rand()%1) {
            case 0:
                return new Platform(Vector2()); // TODO replace with actual fake platform
                break;
        }
    } else {
        switch (std::rand()%1) {
            case 0:
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

    return p;
}
