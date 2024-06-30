//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_MOVINGPLATFORM_H
#define PROJECT_MOVINGPLATFORM_H

#include "../../util/utils.h"
#include "Platform.h"

class MovingPlatform : public Platform {
   protected:
    void _update() override;
    double _velocity;
    double _width;

   public:
    explicit MovingPlatform(const Vector2 &position);
    ~MovingPlatform() override = default;
};

#endif  // PROJECT_MOVINGPLATFORM_H
