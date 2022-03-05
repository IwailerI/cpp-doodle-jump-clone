//
// Created by wailer on 22/02/2022.
//

#include "ScreenSaver.h"

ScreenSaver::ScreenSaver(): _size(0) {
    memset(_objects, 0, sizeof(_objects));
}

ScreenSaver::~ScreenSaver() {
    for (int i = 0; i < _size; i++) {
        delete _objects[i];
        _objects[i] = nullptr;
    }
}

void ScreenSaver::Draw() {
    al_clear_to_color(_background_color);
    for (int i = 0; i < _size; i++) {
        _objects[i]->Draw();
    }
}

void ScreenSaver::Update() {
    for (int i = 0; i< _size; i++) {
        _objects[i]->Update();
    }
}

void ScreenSaver::Add(GameObject *s) {
    if (_size >= MAX_OBJECTS) return;
    _objects[_size++] = s;
}

void ScreenSaver::Remove(int i) {
    _objects[i] = _objects[_size-1];
    delete _objects[_size-1];
    _objects[_size--] = nullptr;
}