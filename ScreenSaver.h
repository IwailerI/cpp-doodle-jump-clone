//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_SCREENSAVER_H
#define PROJECT_SCREENSAVER_H

#include "shapes/Shape.h"

const int MAX_BODIES = 100;

typedef Shape* PShape;
class ScreenSaver {
protected:
    PShape _bodies[MAX_BODIES];
    int _size;

public:
    ScreenSaver();
    virtual ~ScreenSaver();

    void Draw();
    void Update();

    void Add(PShape s);

//    Removes element at index i and clears it space
    void Remove(int i);
};


#endif //PROJECT_SCREENSAVER_H
