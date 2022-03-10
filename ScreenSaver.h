//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_SCREENSAVER_H
#define PROJECT_SCREENSAVER_H

#include "allegro/AllegroBase.hpp"
#include "objects/GameObject.h"

const int MAX_OBJECTS = 200;

// Singleton
class ScreenSaver {
private:
    ScreenSaver();

protected:
    GameObject *_objects[MAX_OBJECTS]{};
    int _size;
    ALLEGRO_COLOR _background_color;

    Vector2 _offset;

    //    Removes element at index i and optionally clears memmory
    void remove(int i, bool clear = true);

public:
    // returns current singleton instance or creates a new one
    static ScreenSaver &Instance() {
        static ScreenSaver instance;
        return instance;
    }

    virtual ~ScreenSaver();

    void Draw();
    void Update();

    int Add(GameObject *s);

    void Offset(Vector2 v);
};


#endif //PROJECT_SCREENSAVER_H
