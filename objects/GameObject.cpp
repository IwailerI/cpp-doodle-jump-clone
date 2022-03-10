//
// Created by wailer on 01/03/2022.
//

#include "GameObject.h"

GameObject::GameObject(const Vector2 &position, double rotation, const Vector2 &scale):
    Transform(position, rotation, scale), _marked_for_object_deletion(0) {}

GameObject::GameObject(): Transform(), _marked_for_object_deletion(0) {}

bool GameObject::isVisible() const {
    return _visible;
}

void GameObject::setVisible(bool visible) {
    _visible = visible;
}

bool GameObject::isSleeping() const {
    return _sleeping;
}

void GameObject::setSleeping(bool sleeping) {
    _sleeping = sleeping;
}

void GameObject::Draw() {
    if (_visible)
        _draw();
}

void GameObject::Update() {
    if (!_sleeping)
        _update();
}

int GameObject::getObjectId() const {
    return _object_id;
}

void GameObject::setObjectId(int objectId) {
    _object_id = objectId;
}
