//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_SPRITE_H
#define PROJECT_SPRITE_H

#include "GameObject.h"

class Sprite : public GameObject {
   protected:
    ALLEGRO_BITMAP *_sprite;

    void _draw() override;
    void _update() override;

    Vector2 _sprite_offset = Vector2();

   public:
    Sprite(const Vector2 &position, ALLEGRO_BITMAP *sprite);

    Sprite() = default;
    ~Sprite() override = default;

    const Vector2 GetImageSize() const;
};

#endif  // PROJECT_SPRITE_H
