//
// Created by wailer on 26/02/2022.
//

#ifndef PROJECT_SHAPEFACTORY_H
#define PROJECT_SHAPEFACTORY_H

#include "Shape.h"
#include "Square.h"
#include "Circle.h"

#include "../util/Vector2.h"
#include "../allegro/AllegroBase.hpp"

class ShapeFactory {
public:
    enum Type {
        TCircle,
        TSquare,
    };

    static Circle *RandomCircle();
    static Circle *NewCircle(
            Vector2 pos = Vector2(),
            Vector2 direction = Vector2(),
            double velocity = 0.0,
            double radius = 1.0,
            ALLEGRO_COLOR color = al_map_rgb(255, 255, 255)
            );

    static Square *RandomSquare();
    static Square *NewSquare(
            Vector2 pos = Vector2(),
            Vector2 direction = Vector2(),
            double velocity = 0.0,
            double side = 1.0,
            ALLEGRO_COLOR color = al_map_rgb(255, 255, 255)
    );

    // size means total width of figure
    // size = side for squares
    // size = 2 * radius for circles

    // wrappers for variable types
    static Shape *RandomShape(Type t);
    static Shape *NewShape(
            Type t,
            Vector2 pos = Vector2(),
            Vector2 direction = Vector2(),
            double velocity = 0.0,
            double size = 1.0,
            ALLEGRO_COLOR color = al_map_rgb(255, 255, 255)
    );
};


#endif //PROJECT_SHAPEFACTORY_H
