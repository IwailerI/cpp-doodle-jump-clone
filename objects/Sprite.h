//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_SPRITE_H
#define PROJECT_SPRITE_H

#include "GameObject.h"

// TODO currently is a simple rect

class Sprite: public GameObject {
protected:
    // ALLEGRO_BITMAP _sprite;
    ALLEGRO_COLOR _color = al_map_rgb(255, 255, 255);
    Vector2 _dimensions = Vector2(0, 0);

    void _draw() override;
    void _update() override;

public:
    // Sprite(const Vector2 &position, double rotation, const Vector2 &scale, const ALLEGRO_BITMAP &sprite);
    // Sprite(const ALLEGRO_BITMAP &sprite);

    Sprite(const ALLEGRO_COLOR &color, const Vector2 &dimensions); // TODO remove

    Sprite() = default;
    ~Sprite() override = default;

//    const ALLEGRO_BITMAP &getSprite() const;
//    void setSprite(const ALLEGRO_BITMAP &sprite);


};


#endif //PROJECT_SPRITE_H
