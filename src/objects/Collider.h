//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_COLLIDER_H
#define PROJECT_COLLIDER_H

#include <memory>

#include "../util/Vector2.h"
#include "../util/constants.h"

enum class PlayerInteraction {
    IsPlayer,
    Bounce,
    Kill,
    KillBounce,
    Boost,
    Break,
    None,
};

class Collider {
   protected:
    int _physics_id = -1;
    PlayerInteraction _player_interaction = PlayerInteraction::None;
    bool _is_marked_for_deletion = false;

    virtual Vector2 _getDimensions(bool alternative) const = 0;
    virtual Vector2 _getColliderPosition(bool alternative) const = 0;

   public:
    virtual ~Collider() = default;

    // wrapper for _getDimensions, because virtual functions can't accept
    // default arguments?
    Vector2 getDimensions(bool alternative = false) const {
        return _getDimensions(alternative);
    }

    // same
    Vector2 getColliderPosition(bool alternative = false) const {
        return _getColliderPosition(alternative);
    };

    int getPhysicsId() const;
    void setPhysicsId(int physicsId);

    inline void markForDeletion() { _is_marked_for_deletion = true; }
    inline bool isMarkedForDeletion() const { return _is_marked_for_deletion; }

    PlayerInteraction getPlayerInteraction() const;

    bool isColliding(std::shared_ptr<Collider> col,
                     bool alternative = false) const;

    virtual void onCollision(std::shared_ptr<Collider> col) = 0;
};

#endif  // PROJECT_COLLIDER_H
