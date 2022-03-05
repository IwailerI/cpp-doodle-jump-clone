//
// Created by wailer on 01/03/2022.
//

#ifndef PROJECT_COLORRECT_H
#define PROJECT_COLORRECT_H

#include "../GameObject.h"

class ColorRect: public GameObject{
protected:
    ALLEGRO_COLOR _color;
    Vector2 _dimensions;

    bool _filled = true;
    float _thickness;

    void _draw() override;

    void _update() override;

private:
    // make rectangle unable to be rotated
    void setRotation(double rotation) override;



public:
    // constructors/destructors
    ColorRect(const Vector2 &position, const ALLEGRO_COLOR &color, const Vector2 &dimensions);
    ColorRect(const Vector2 &position, const Vector2 &dimensions);
    ColorRect();
    ~ColorRect() override = default;

    // setters/getters
    const ALLEGRO_COLOR &getColor() const;
    void setColor(const ALLEGRO_COLOR &color);

    const Vector2 &getDimensions() const;
    void setDimensions(const Vector2 &dimensions);

    bool isFilled() const;
    void setFilled(bool filled);

    double getThickness() const;
    void setThickness(float thickness);

    // overrides
    // always returns zero, rectangle can't be rotated
    double getRotation() const override;
};


#endif //PROJECT_COLORRECT_H
