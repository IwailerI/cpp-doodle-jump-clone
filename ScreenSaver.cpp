//
// Created by wailer on 22/02/2022.
//

#include "ScreenSaver.h"

ScreenSaver::ScreenSaver(): _size(0), _background_color(al_map_rgb(0, 0, 0)), _offset(Vector2(0, 0)) {
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
//    al_clear_to_color(al_map_rgb(255, 255, 255));
    for (int i = 0; i < _size; i++) {
        _objects[i]->Draw();
    }
}

void ScreenSaver::Update() {
    for (int i = 0; i < _size; i++) {
        if (_objects[i]->getObjectDeletionMark() != 0) {
            _remove(i, _objects[i]->getObjectDeletionMark() - 1);
            i--;
            continue;
        }
        _objects[i]->Offset(_offset);
        _objects[i]->Update();
    }
    _offset = Vector2(0, 0);
}

int ScreenSaver::Add(GameObject *s) {
    if (_size >= MAX_OBJECTS) return -1;
    s->setObjectId(_size);
    _objects[_size++] = s;
    return _size-1;
}

void ScreenSaver::_remove(int i, bool clear) {
    if (clear)
        delete _objects[i];
    _objects[i] = _objects[--_size];
    _objects[_size] = nullptr;
}

// Queses offset to be added on next physics frame
void ScreenSaver::Offset(Vector2 v) {
    _offset += v;
}

void ScreenSaver::_endScreen() {

}

void ScreenSaver::_startGame() {
    auto p = new Platform(Vector2(150, 700));
    Add(p);
    PhysicsServer::Instance().Add(p);
}

void ScreenSaver::_titleScreen() {

}

void ScreenSaver::_drawPause() {
    al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(0, 0, 0, 128));

}

void ScreenSaver::ChangeState(int state) {
    if (state == INGAME && _state != PAUSE) {
        _clear();
        _startGame();
    } else if (state == TITLE) {
        _clear();
    } else if (state == END) {
        _clear();
    }
    _state =  state;
}

void ScreenSaver::_clear() {
    for (int i = 0; i < _size; i++)
        _remove(i, true);
}
