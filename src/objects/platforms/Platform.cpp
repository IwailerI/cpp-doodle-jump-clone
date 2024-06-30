//
// Created by wailer on 10/03/2022.
//

#include "Platform.h"

void Platform::_update() {
    // update content
    if (_content != nullptr) {
        auto is = GetImageSize();
        _content->UpdatePos(
            Vector2(_position.x + is.x * .5, _position.y - is.y * .5));
    }

    if (GameObject::_position.y >= OBJECT_DELETE_THRESHOLD) {
        if (_content != nullptr) {
            _content->destroy();
            _content = nullptr;
        }
        _destroy();
    }
}

void Platform::_destroy() {
    if (isMarkedForObjectDeletion() || isMarkedForDeletion()) return;

    _visible = false;
    if (_physics_id != -1 && _object_id != -1) {
        markForObjectDeletion();
        markForDeletion();
    } else if (_object_id != -1) {
        markForObjectDeletion();
    } else if (_physics_id != -1) {
        markForDeletion();
    } else
        delete this;
}

Platform::Platform(Vector2 position) : Sprite() {
    _sprite = ResourceManager::Instance().sprite_platform;
    _player_interaction = PlayerInteraction::Bounce;
    _position = position;
}

Vector2 Platform::_getColliderPosition(bool alternative) const {
    return _position;
}

Vector2 Platform::_getDimensions(bool alternative) const {
    return GetImageSize();
}

void Platform::onCollision(std::shared_ptr<Collider> col) {
    // do nothing
}

Platform::Platform(Vector2 position, ALLEGRO_BITMAP *sprite,
                   PlayerInteraction PI)
    : Sprite() {
    _position = position;
    _sprite = sprite;
    _player_interaction = PI;
}

void Platform::addContent(std::shared_ptr<Content> c) {
    if (_content != nullptr) _content->destroy();
    _content = c;
}
