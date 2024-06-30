//
// Created by wailer on 03/04/2022.
//

#include "Content.h"

void Content::destroy() {
    if (isMarkedForDeletion() || isMarkedForObjectDeletion()) return;
    _visible = false;
    if (_physics_id != -1) {
        markForDeletion();
    }
    if (_object_id != -1) {
        markForObjectDeletion();
    }
}

Vector2 Content::_getDimensions(bool alternative) const {
    return GetImageSize();
}

Vector2 Content::_getColliderPosition(bool alternative) const {
    return _position;
}

void Content::UpdatePos(Vector2 position) {
    _position = position - Vector2(GetImageSize().x * 0.5, 0.0);
}
