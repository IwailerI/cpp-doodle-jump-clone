//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_ALLEGRO_H
#define PROJECT_ALLEGRO_H

#include "AllegroBase.hpp"

typedef void ( *FpsCallback )();
typedef void ( *DrawCallback )();

class Allegro: public AllegroBase{
public:
    Allegro(void (*draw)(), void (*update)());

    virtual ~Allegro();

    void Fps() override;
    void Draw() override;

private:

    DrawCallback draw;
    FpsCallback update;
};


#endif //PROJECT_ALLEGRO_H
