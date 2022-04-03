//
// Created by wailer on 01/03/2022.
//

#include "GameObject.h"

GameObject::GameObject(const Vector2 &position, double rotation, const Vector2 &scale):
    _position(position), _rotation(rotation), _scale(scale), _marked_for_object_deletion(0)
    {}

GameObject::GameObject():
    _position(Vector2()), _rotation(0.0), _scale(Vector2(1.0, 1.0)), _marked_for_object_deletion(0)
    {}

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

Vector2 GameObject::getPosition() const {
    return _position;
}

void GameObject::setPosition(const Vector2 &position) {
    _position = position;
}

void GameObject::Offset(const Vector2 &vec) {
    _position += vec;
}

double GameObject::getRotation() const {
    return _rotation;
}

void GameObject::setRotation(double rotation) {
    _rotation = rotation;
}

Vector2 GameObject::getScale() const {
    return _scale;
}

void GameObject::setScale(const Vector2 &scale) {
    _scale = scale;
}
