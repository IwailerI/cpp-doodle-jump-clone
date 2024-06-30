//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_PLATFORM_H
#define PROJECT_PLATFORM_H

#include "../../ResourceManager.h"
#include "../Collider.h"
#include "../Sprite.h"
#include "../content/Content.h"

class Platform : public Sprite, public Collider {
   public:
    explicit Platform(Vector2 position);
    ~Platform() override = default;

    void onCollision(std::shared_ptr<Collider> col) override;

    void addContent(std::shared_ptr<Content> c);
    std::shared_ptr<Content> getContent() { return _content; }

   protected:
    Platform(Vector2 position, ALLEGRO_BITMAP *sprite,
             PlayerInteraction PE = PlayerInteraction::Bounce);
    Vector2 _getColliderPosition(bool alternative) const override;
    Vector2 _getDimensions(bool alternative) const override;

    std::shared_ptr<Content> _content = nullptr;

    void _update() override;

    void _destroy();
};

#endif  // PROJECT_PLATFORM_H