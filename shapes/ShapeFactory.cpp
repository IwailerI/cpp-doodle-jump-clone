//
// Created by wailer on 26/02/2022.
//

#include "ShapeFactory.h"

Shape *ShapeFactory::RandomShape(ShapeFactory::Type t) {
    Shape *s = nullptr;
    switch (t) {
        case TCircle:
            return RandomCircle();
        case TSquare:
            return RandomSquare();
        default:
            return nullptr;
    }
}

Shape *ShapeFactory::NewShape(
        ShapeFactory::Type t, Vector2 pos, Vector2 direction, double velocity, double size, ALLEGRO_COLOR color) {
    switch (t) {
        case TCircle:
            return NewCircle(pos, direction, velocity, size*.5, color);
        case TSquare:
            return NewSquare(pos, direction, velocity, size, color);
    }
    return nullptr;
}

Circle *ShapeFactory::RandomCircle() {
    Circle *s = new Circle();
    s->Randomize();
    return s;
}

Circle *ShapeFactory::NewCircle(Vector2 pos, Vector2 direction, double velocity, double radius, ALLEGRO_COLOR color) {
    return new Circle(pos, direction*velocity, color, radius);
}

Square *ShapeFactory::RandomSquare() {
    Square *s = new Square();
    s->Randomize();
    return s;
}

Square *ShapeFactory::NewSquare(Vector2 pos, Vector2 direction, double velocity, double side, ALLEGRO_COLOR color) {
    return new Square(pos, direction*velocity, color, side);
}
