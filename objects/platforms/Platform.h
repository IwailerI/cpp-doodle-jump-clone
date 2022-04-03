//
// Created by wailer on 10/03/2022.
//

#ifndef PROJECT_PLATFORM_H
#define PROJECT_PLATFORM_H

#include "../Collider.h"
#include "../Sprite.h"
#include "../../ResourceManager.h"
#include "../content/Content.h"

class Platform: public Sprite, public Collider {
public:
    explicit Platform(Vector2 position);
    ~Platform() override = default;

    void onCollision(Collider *col) override;

    void addContent(Content *c);
    Content *getContent() {return _content;}

protected:
    Platform (Vector2 position, ALLEGRO_BITMAP* sprite, PlayerInteraction PE = Bounce);
    Vector2 _getColliderPosition(bool alternative) const override;
    Vector2 _getDimensions(bool alternative) const override;

    Content *_content = nullptr;

    void _update() override;

    void _suicide();
};


#endif //PROJECT_PLATFORM_H