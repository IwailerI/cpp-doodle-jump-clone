//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_PLATFORM_H
#define PROJECT_PLATFORM_H

#include "../Collider.h"
#include "../Sprite.h"

const double DELETE_TRESHOLD = SCREEN_H+30;

class Platform: public Sprite, public Collider {
public:
    Platform(Vector2 position);
    ~Platform() override = default;

    const Vector2 &getPosition() const override;
    const Vector2 &getDimensions() const override;
    void onCollision(Collider *col) override;

protected:
    void _update() override;

    void _suicide();
};


#endif //PROJECT_PLATFORM_H