//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_SPRING_H
#define PROJECT_SPRING_H

#include "Content.h"

class Spring : public Content {
   public:
    Spring();

    void onCollision(std::shared_ptr<Collider> col) override;
};

#endif  // PROJECT_SPRING_H
