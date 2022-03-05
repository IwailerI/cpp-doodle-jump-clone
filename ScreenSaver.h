//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_SCREENSAVER_H
#define PROJECT_SCREENSAVER_H

#include "objects/GameObject.h"
#include "allegro/Allegro.h"

const int MAX_OBJECTS = 200;

// Singleton
class ScreenSaver {
private:
    ScreenSaver();

protected:
    GameObject *_objects[MAX_OBJECTS]{};
    int _size;

    const ALLEGRO_COLOR _background_color = al_map_rgb(0, 0, 0);

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

//    Removes element at index i and clears it space
    void Remove(int i);
};


#endif //PROJECT_SCREENSAVER_H
