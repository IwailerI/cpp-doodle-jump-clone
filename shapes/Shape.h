//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_SHAPE_H
#define PROJECT_SHAPE_H

#include "../util/Vector2.h"
#include "../allegro/Allegro.h"

class Shape {
protected:
    Vector2 _position;
    Vector2 _direction;

    double _velocity;

    // scale is a lie, we are only changing _radius or _side, this value is only used in 2 cases:
    // 1) getScale()
    // 2) get(Side|Radius)(), to calculate starting side/radius

    double _scale = 1.0;

    ALLEGRO_COLOR _color{};

    double _thickness = 1;

    bool _collided = false;

private:
    static float randf() ;

public:
    const int MAX_SPEED = 7;
    const int MIN_SPEED = 1;

    virtual ~Shape() = default;
    Shape(const Vector2 &position, Vector2 velocity, const ALLEGRO_COLOR &color);
    Shape();

    const Vector2 &getPosition() const;
    void setPosition(const Vector2 &position);

    const Vector2 &getDirection() const;
    void setDirection(const Vector2 &direction);

    double getVelocity() const;
    void setVelocity(double velocity);

    const ALLEGRO_COLOR &getColor() const;
    void setColor(const ALLEGRO_COLOR &color);

    bool hasCollided() const;
    void setCollided(bool collided);

    double getScale() const;
    virtual void setScale(double scale) = 0; // don't do anything, scaling a point is useless.

//    returns a normal vector, of surface, with which we have collided
    virtual Vector2 GetBoundaries();

//    returns a point, that is still within the shape, closest to pos
    virtual Vector2 GetClosestPointTo(Vector2 pos) = 0;

//    returns (normalized) normal of shape's surface,
//    at point on the edge of surface, between center and pos
    virtual Vector2 GetSurfaceNormalAt(Vector2 pos) = 0;

    void Move();

    void Collide(Vector2 normal);

    virtual void Draw() = 0;

    virtual void Randomize();
};


#endif //PROJECT_SHAPE_H
