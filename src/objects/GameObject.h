//
// Created by wailer on 01/03/2022.
//

#ifndef PROJECT_GAMEOBJECT_H
#define PROJECT_GAMEOBJECT_H

#include "../allegro/AllegroBase.hpp"
#include "../util/Vector2.h"

// Game object is something that can be placed in the world and drawn and
// updated (optionally)
class GameObject {
   protected:
    Vector2 _position = Vector2(0.0, 0.0);
    double _rotation = 0.0;
    Vector2 _scale = Vector2(1.0, 1.0);

    bool _visible = true;
    bool _sleeping = false;

    int _object_id = -1;
    bool _is_marked_for_deletion = false;

    virtual void _draw() = 0;
    virtual void _update() = 0;

   public:
    // constructors/destructors
    GameObject(const Vector2 &position, double rotation, const Vector2 &scale);
    GameObject();
    virtual ~GameObject() = default;

    Vector2 getPosition() const;
    void setPosition(const Vector2 &position);
    void Offset(const Vector2 &vec);

    virtual double getRotation() const;

    virtual void setRotation(double rotation);

    Vector2 getScale() const;
    void setScale(const Vector2 &scale);

    // setters/getters
    bool isVisible() const;
    void setVisible(bool visible);

    bool isSleeping() const;
    void setSleeping(bool sleeping);

    int getObjectId() const;
    void setObjectId(int objectId);

    inline void markForObjectDeletion() { _is_marked_for_deletion = true; }
    inline bool isMarkedForObjectDeletion() const {
        return _is_marked_for_deletion;
    }

    // methods
    void Draw();
    void Update();
};

#endif  // PROJECT_GAMEOBJECT_H
