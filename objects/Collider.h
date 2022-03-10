//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_COLLIDER_H
#define PROJECT_COLLIDER_H

#include "../util/Vector2.h"

enum PlayerInteraction {Ignore, Bounce, Kill, Boost};

class Collider {
protected:
    int _physics_id = -1;
    int _player_interaction = -1;
    bool _oneway = false;
public:
    virtual ~Collider() = default;

    virtual const Vector2 &getPosition() const = 0;
    virtual const Vector2 &getDimensions() const = 0;

    virtual Vector2 getColliderVelocity() const;

    int getPhysicsId() const;
    void setPhysicsId(int physicsId);

    bool isOneway() const {return _oneway;}

    int getPlayerInteraction() const;

    bool isColliding(Collider *col) const;

    virtual void onCollision(Collider *col) = 0;
};


#endif //PROJECT_COLLIDER_H
