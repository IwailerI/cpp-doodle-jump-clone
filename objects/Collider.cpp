//
// Created by wailer on 05/03/2022.
//

#include "Collider.h"

const Vector2 &Collider::getDimensions() const {
    return _dimensions;
}

void Collider::setDimensions(const Vector2 &dimensions) {
    _dimensions = dimensions;
}

Collider::Collider(Vector2 position, Vector2 dimensions, bool oneway):
        Transform(_position, 0, Vector2(1, 1)), _dimensions(dimensions), _oneway(oneway)
        {}

Collider::Collider():
    Transform(), _dimensions(Vector2(0, 0)), _oneway(false)
    {}

bool Collider::isColliding(Collider &col) {
    Vector2 p1 = col._position + col._dimensions;
    Vector2 p2 = _position + _dimensions;

    // return pos is within other col or pos+dimensions is within other col

    return ((_position.x <= p2.x && _position.x >= col._position.x) || (p1.x <= p2.x && p1.x >= col._position.x))
        && ((_position.y <= p2.y && _position.y >= col._position.y) || (p1.y <= p2.y && p1.y >= col._position.y));
}
