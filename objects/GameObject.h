//
// Created by wailer on 01/03/2022.
//

#ifndef PROJECT_GAMEOBJECT_H
#define PROJECT_GAMEOBJECT_H

#include "../util/Vector2.h"
#include "Transform.h"
#include "../allegro/AllegroBase.hpp"

// game object is something that can be placed in the world and drawn
class GameObject: public Transform {
protected:
    bool _visible = true;
    bool _sleeping = false;

    int _object_id = -1;
    int _marked_for_object_deletion = 0; // 0 - no, 1 - yes, delete only from list, 2 - yes, also clear memmory

    virtual void _draw() = 0;
    virtual void _update() = 0;
public:
    // constructors/destructors
    GameObject(const Vector2 &position, double rotation, const Vector2 &scale);
    GameObject();
    ~GameObject() override = default;

    // setters/getters
    bool isVisible() const;
    void setVisible(bool visible);

    bool isSleeping() const;
    void setSleeping(bool sleeping);

    int getObjectId() const;
    void setObjectId(int objectId);

    void markForObjectDeletion(bool clear = false) { _marked_for_object_deletion = 1 + clear;}
    int getObjectDeletionMark() const {return _marked_for_object_deletion;}

    // methods
    void Draw();
    void Update();

};


#endif //PROJECT_GAMEOBJECT_H
