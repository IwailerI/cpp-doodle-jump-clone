//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_SCREENSAVER_H
#define PROJECT_SCREENSAVER_H

#include <vector>

#include "allegro/AllegroBase.hpp"
#include "objects/platforms/Platform.h"

const int MAX_OBJECTS = 200;

#define rgb(r, g, b) al_map_rgb(r, g, b)

// Singleton
class ScreenSaver {
   private:
    ScreenSaver();

   protected:
    std::vector<std::shared_ptr<GameObject>> _objects;
    ALLEGRO_COLOR _background_color;
    ALLEGRO_COLOR _grid_color;

    Vector2 _offset;

    double _grid_pos = 0.0;

    double _score = 0.0;

    ALLEGRO_FONT *_font;

    //    Removes element at index i
    void _remove(int i);

   public:
    // returns current singleton instance or creates a new one
    static ScreenSaver &Instance() {
        static ScreenSaver instance;
        return instance;
    }

    virtual ~ScreenSaver() = default;

    void Draw();
    void Update();

    void DrawTitleScreen();
    void DrawPauseMenu();
    void DrawEndScreen();

    int Add(std::shared_ptr<GameObject> s);
    void Offset(Vector2 v);

    void Clear();
};

#endif  // PROJECT_SCREENSAVER_H
