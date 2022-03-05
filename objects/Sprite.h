//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_SPRITE_H
#define PROJECT_SPRITE_H

#include "GameObject.h"

class Sprite: public GameObject {
protected:
    ALLEGRO_BITMAP _sprite;

    void _draw() override;
    void _update() override;

public:
    Sprite(const Vector2 &position, double rotation, const Vector2 &scale, const ALLEGRO_BITMAP &sprite);
    Sprite(const ALLEGRO_BITMAP &sprite);
    Sprite() = default;
    virtual ~Sprite() = default;

    const ALLEGRO_BITMAP &getSprite() const;
    void setSprite(const ALLEGRO_BITMAP &sprite);


};


#endif //PROJECT_SPRITE_H
