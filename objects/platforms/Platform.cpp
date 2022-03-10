//
// Created by wailer on 10/03/2022.
//

#include "Platform.h"

void Platform::_update() {
    if (GameObject::_position.y <= DELETE_TRESHOLD) {
        printf("SUICIDE");
        _suicide();
    }
}

void Platform::_suicide() {
    _visible = false;
    if (_physics_id != -1)
        PhysicsServer::Instance().Remove(_physics_id);
    else
        delete this;
}

Platform::Platform(Vector2 position):
    Sprite(al_map_rgb(255, 255, 0), Vector2(100, 20))
    {
    _player_interaction = Bounce;
    _position = position;
    printf("%d %d\n", position.x, position.y);
}

const Vector2 &Platform::getPosition() const {
    return _position;
}

const Vector2 &Platform::getDimensions() const {
    return _dimensions;
}

void Platform::onCollision(Collider *col) {
    // do nothing
}