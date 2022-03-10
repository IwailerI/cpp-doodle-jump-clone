//
// Created by wailer on 01/03/2022.
//

#include "Transform.h"

Transform::Transform(const Vector2 &position, double rotation, const Vector2 &scale):
        _position(position), _rotation(rotation), _scale(scale) {}

Vector2 Transform::getPosition() const {
    return _position;
}

void Transform::setPosition(const Vector2 &position) {
    Transform::_position = position;
}

double Transform::getRotation() const {
    return _rotation;
}

void Transform::setRotation(double rotation) {
    Transform::_rotation = rotation;
}

Vector2 Transform::getScale() const {
    return _scale;
}

void Transform::setScale(const Vector2 &scale) {
    Transform::_scale = scale;
}

Transform::Transform(): _position(Vector2(0, 0)), _rotation(0), _scale(Vector2(1, 1)){}

void Transform::Offset(const Vector2 &vec) {
    _position += vec;
}

