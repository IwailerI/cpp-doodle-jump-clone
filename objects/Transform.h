//
// Created by wailer on 01/03/2022.
//

#ifndef PROJECT_TRANSFORM_H
#define PROJECT_TRANSFORM_H

#include "../util/Vector2.h"

// Transform is a set of basic characteristic, applicable, but not limited to, GameObject, CollisionAreas
class Transform {
protected:
    Vector2 _position = Vector2(0.0, 0.0);
    double _rotation = 0.0;
    Vector2 _scale = Vector2(1.0, 1.0);

public:
    // constructors/destructors
    Transform(const Vector2 &position, double rotation, const Vector2 &scale);
    Transform();
    virtual ~Transform() = default;

    // getters/setters
    Vector2 getPosition() const;
    void setPosition(const Vector2 &position);
    void Offset(const Vector2 &vec);

    virtual double getRotation() const;

    virtual void setRotation(double rotation);

    Vector2 getScale() const;
    void setScale(const Vector2 &scale);
};


#endif //PROJECT_TRANSFORM_H
