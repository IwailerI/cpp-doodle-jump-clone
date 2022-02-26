//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_CIRCLE_H
#define PROJECT_CIRCLE_H

#include "Shape.h"

class Circle: public Shape{
protected:
    double _radius;

public:
    Circle(const Vector2 &position, const Vector2 &velocity, const ALLEGRO_COLOR &color, double radius);
    Circle();
    virtual ~Circle() = default;

    double getRadius() const;
    void setRadius(double radius);
    void setScale(double scale) override;

    Vector2 GetBoundaries() override;
    Vector2 GetClosestPointTo(Vector2 pos) override;
    Vector2 GetSurfaceNormalAt(Vector2 pos) override;

    void Draw() override;

    void Randomize() override;
};


#endif //PROJECT_CIRCLE_H
