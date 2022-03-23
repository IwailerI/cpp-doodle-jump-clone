//
// Created by wailer on 22/02/2022.
//

#include "ScreenSaver.h"

ScreenSaver::ScreenSaver(): _size(0), _background_color(al_map_rgb(255, 255, 255)), _offset(Vector2(0, 0)) {
    memset(_objects, 0, sizeof(_objects));
    _font = ResourceManager::Instance().font;
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
    for (int i = _size-1; i >= 0; i--) {
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

void ScreenSaver::DrawTitleScreen() {
    al_clear_to_color(al_map_rgb(71, 83, 132));

    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5-51, ALLEGRO_ALIGN_CENTER, "Press [SPACE]");
    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5+21, ALLEGRO_ALIGN_CENTER, "to begin!");
}

void ScreenSaver::DrawEndScreen() {
    al_clear_to_color(al_map_rgb(179, 14, 8));

    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5-144, ALLEGRO_ALIGN_CENTER, "GAME OVER");
    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5-72, ALLEGRO_ALIGN_CENTER, "[SPACE]");
    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5, ALLEGRO_ALIGN_CENTER, "to restart");
    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5+72, ALLEGRO_ALIGN_CENTER, "[ESCAPE]");
    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5+144, ALLEGRO_ALIGN_CENTER, "to exit");
}

void ScreenSaver::DrawPauseMenu() {
    al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(0, 0, 0, 200));
    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5-150, ALLEGRO_ALIGN_CENTER, "PAUSED");
    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5-70, ALLEGRO_ALIGN_CENTER, "[SPACE]");
    al_draw_text(_font, al_map_rgb(255, 255, 255), SCREEN_W*.5, SCREEN_H*.5+2, ALLEGRO_ALIGN_CENTER, "to continue");

}

void ScreenSaver::Clear() {
    for (int i = 0; i < _size; i++)
        if (_objects[i] != nullptr)
            _remove(i, true);
}
