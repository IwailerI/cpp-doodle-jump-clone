//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_COLLIDER_H
#define PROJECT_COLLIDER_H

#include "../util/Vector2.h"

enum PlayerInteraction {IsPlayer, Ignore, Bounce, Kill, KillBounce, Boost, Break};

class Collider {
protected:
    int _physics_id = -1;
    int _player_interaction = -1;
    int _marked_for_physics_deletion = 0; // 0 - no, 1 - yes, delete only from list, 2 - yes, also clear memmory

    virtual Vector2 _getDimensions(bool alternative) const = 0;
    virtual Vector2 _getColliderPosition(bool alternative) const = 0;

public:
    virtual ~Collider() = default;


    // wrapper for _getDimensions, because virtual functions can't accept default arguments?
    Vector2 getDimensions(bool alternative = false) const {return _getDimensions(alternative);}

    // same
    Vector2 getColliderPosition(bool alternative = false) const {return _getColliderPosition(alternative);};

    int getPhysicsId() const;
    void setPhysicsId(int physicsId);

    void markForPhysicsDeletion(bool clear = false) { _marked_for_physics_deletion = 1 + clear;}
    int getPhysicsDeletionMark() const {return _marked_for_physics_deletion;}

    int getPlayerInteraction() const;

    bool isColliding(Collider *col, bool alternative = false) const;

    virtual void onCollision(Collider *col) = 0;
};


#endif //PROJECT_COLLIDER_H
