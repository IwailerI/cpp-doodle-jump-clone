//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_PLATFORM_H
#define PROJECT_PLATFORM_H

#include "../Collider.h"
#include "../Sprite.h"
#include "../../ResourceManager.h"

class Platform: public Sprite, public Collider {
public:
    explicit Platform(Vector2 position);
    ~Platform() override = default;

    void onCollision(Collider *col) override;

    static Vector2 PlatformDimensions();

protected:
    Vector2 _getColliderPosition(bool alternative) const override;
    Vector2 _getDimensions(bool alternative) const override;

    void _update() override;

    void _suicide();
};


#endif //PROJECT_PLATFORM_H