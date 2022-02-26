//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_SQUARE_H
#define PROJECT_SQUARE_H

#include "Shape.h"

class Square: public Shape{
protected:
    double _side{};

private:
    static double clamp(double n, double min, double max);

public:
    Square(const Vector2 &position, const Vector2 &velocity, const ALLEGRO_COLOR &color, double side);
    Square();

    virtual ~Square() = default;

    double getSide() const;
    void setSide(double side);

    void setScale(double scale) override;

    Vector2 GetClosestPointTo(Vector2 pos) override;
    Vector2 GetSurfaceNormalAt(Vector2 pos) override;
    Vector2 GetBoundaries() override;

    void Draw() override;

    void Randomize() override;
};


#endif //PROJECT_SQUARE_H
