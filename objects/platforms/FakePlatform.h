//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_FAKEPLATFORM_H
#define PROJECT_FAKEPLATFORM_H

#include "Platform.h"

class FakePlatform: public Platform {
public:
    explicit FakePlatform(const Vector2 &position);
    ~FakePlatform() override = default;

    void onCollision(Collider *col) override;

    void demolish();

protected:
    bool _broken = false;
    double _velocity = 0.0;

    void _update() override;
};


#endif //PROJECT_FAKEPLATFORM_H
