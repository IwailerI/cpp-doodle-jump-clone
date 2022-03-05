//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_COLLIDER_H
#define PROJECT_COLLIDER_H

#include "Transform.h"

class Collider: public Transform {
protected:
    Vector2 _dimensions;
    bool _oneway = false;

public:
    Collider(Vector2 position, Vector2 dimensions, bool oneway = false);
    Collider();
    ~Collider() override = default;

    const Vector2 &getDimensions() const;
    void setDimensions(const Vector2 &dimensions);

    bool isColliding(Collider &col);
};


#endif //PROJECT_COLLIDER_H
