//
// Created by wailer on 01/03/2022.
//

#ifndef PROJECT_GAMEOBJECT_H
#define PROJECT_GAMEOBJECT_H

#include "../util/Vector2.h"
#include "Transform.h"
#include "../allegro/Allegro.h"

// game object is something that can be placed in the world and drawn
class GameObject: public Transform {
protected:
    bool _visible = true;
    bool _sleeping = false;

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

    // methods
    void Draw();
    void Update();

};


#endif //PROJECT_GAMEOBJECT_H
