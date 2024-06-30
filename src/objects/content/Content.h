//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_CONTENT_H
#define PROJECT_CONTENT_H

#include "../../ResourceManager.h"
#include "../Collider.h"
#include "../Sprite.h"

class Content : public Sprite, public Collider {
   protected:
    Vector2 _getDimensions(bool alternative) const override;
    Vector2 _getColliderPosition(bool alternative) const override;

   public:
    Content() = default;
    ~Content() override = default;

    void UpdatePos(Vector2 position);

    // only content host will call this
    void destroy();
};

#endif  // PROJECT_CONTENT_H
