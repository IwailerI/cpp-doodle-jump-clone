//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_SCREENSAVER_H
#define PROJECT_SCREENSAVER_H

#include "allegro/AllegroBase.hpp"
#include "objects/GameObject.h"
#include "objects/platforms/Platform.h"
#include "PhysicsServer.h"

#include <sstream>
#include <string>

const int MAX_OBJECTS = 200;

// Singleton
class ScreenSaver {
private:
    ScreenSaver();

protected:
    GameObject *_objects[MAX_OBJECTS]{};
    int _size;
    ALLEGRO_COLOR _background_color;
    ALLEGRO_COLOR _grid_color;

    Vector2 _offset;

    double _grid_pos = 0.0;

    double _score = 0.0;

    ALLEGRO_FONT *_font;

    //    Removes element at index i and optionally clears memmory
    void _remove(int i, bool clear = true);

public:
    // returns current singleton instance or creates a new one
    static ScreenSaver &Instance() {
        static ScreenSaver instance;
        return instance;
    }

    virtual ~ScreenSaver();

    void Draw();
    void Update();

    void DrawTitleScreen();
    void DrawPauseMenu();
    void DrawEndScreen();

    int Add(GameObject *s);
    void Offset(Vector2 v);

    void Clear();
};


#endif //PROJECT_SCREENSAVER_H
