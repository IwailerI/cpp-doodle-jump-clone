//
// Created by wailer on 03/04/2022.
//

#include "Content.h"

void Content::suicide() {
    if (_marked_for_object_deletion != 0 || _marked_for_physics_deletion != 0) return;

    _visible = false;
    if (_physics_id != -1 && _object_id != -1) {
        markForObjectDeletion(true);
        markForPhysicsDeletion(false);
    } else if (_object_id != -1) {
        markForObjectDeletion(true);
    } else if (_physics_id != -1) {
        markForPhysicsDeletion(true);
    } else
        delete this;
}

Vector2 Content::_getDimensions(bool alternative) const {
    return GetImageSize();
}

Vector2 Content::_getColliderPosition(bool alternative) const {
    return _position;
}

void Content::UpdatePos(Vector2 position) {
    _position = position-Vector2(GetImageSize().x*.5, 0.0);
}
