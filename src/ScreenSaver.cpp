//
// Created by wailer on 22/02/2022.
//

#include "ScreenSaver.h"

ScreenSaver::ScreenSaver()
    : _background_color(rgb(255, 255, 255)),
      _grid_color(rgb(187, 204, 221)),
      _offset(Vector2(0, 0)) {
    _font = ResourceManager::Instance().font;
}

void ScreenSaver::Draw() {
    // draw background grid
    al_clear_to_color(_background_color);

    for (double y = -_grid_pos; y <= SCREEN_H + 18 * 4; y += 18)
        al_draw_line(0, y, SCREEN_W, y, _grid_color, 2.0);

    for (double x = 0; x <= SCREEN_W; x += 18)
        al_draw_line(x, 0, x, SCREEN_H, _grid_color, 2.0);

    al_draw_line(18 * 3, 0, 18 * 3, SCREEN_H, rgb(160, 187, 214), 3.0);

    for (int i = _objects.size() - 1; i >= 0; i--) {
        _objects[i]->Draw();
    }

    // draw score
    al_draw_text(_font, rgb(30, 5, 71), SCREEN_W * .5, SCREEN_H * .01,
                 ALLEGRO_ALIGN_CENTER, std::to_string(int(_score)).c_str());
}

void ScreenSaver::Update() {
    for (int i = 0; i < _objects.size(); i++) {
        if (_objects[i]->isMarkedForObjectDeletion()) {
            _remove(i);
            i--;
            continue;
        }
        _objects[i]->Offset(_offset);
        _objects[i]->Update();
    }
    _grid_pos += _offset.y;
    if (_grid_pos >= 18) _grid_pos -= 18;

    _score += _offset.y * .1;

    _offset = Vector2(0, 0);
}

int ScreenSaver::Add(std::shared_ptr<GameObject> s) {
    s->setObjectId(_objects.size());
    _objects.push_back(s);
    return s->getObjectId();
}

// Queses offset to be added on next physics frame
void ScreenSaver::Offset(Vector2 v) { _offset += v; }

void ScreenSaver::DrawTitleScreen() {
    al_clear_to_color(rgb(71, 83, 132));

    al_draw_text(_font, rgb(255, 255, 255), SCREEN_W * .5, SCREEN_H * .5 - 51,
                 ALLEGRO_ALIGN_CENTER, "Press [SPACE]");
    al_draw_text(_font, rgb(24, 63, 33), SCREEN_W * .5, SCREEN_H * .5 + 21,
                 ALLEGRO_ALIGN_CENTER, "to begin!");
}

void ScreenSaver::DrawEndScreen() {
    al_clear_to_color(rgb(179, 14, 8));

    al_draw_text(_font, rgb(255, 255, 255), SCREEN_W * .5, SCREEN_H * .5 - 144,
                 ALLEGRO_ALIGN_CENTER, "GAME OVER");
    al_draw_text(_font, rgb(255, 255, 255), SCREEN_W * .5, SCREEN_H * .5 - 72,
                 ALLEGRO_ALIGN_CENTER, "[SPACE]");
    al_draw_text(_font, rgb(44, 114, 61), SCREEN_W * .5, SCREEN_H * .5,
                 ALLEGRO_ALIGN_CENTER, "to restart");
    al_draw_text(_font, rgb(255, 255, 255), SCREEN_W * .5, SCREEN_H * .5 + 72,
                 ALLEGRO_ALIGN_CENTER, "[ESCAPE]");
    al_draw_text(_font, rgb(102, 8, 4), SCREEN_W * .5, SCREEN_H * .5 + 144,
                 ALLEGRO_ALIGN_CENTER, "to exit");
}

void ScreenSaver::DrawPauseMenu() {
    al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H,
                             al_map_rgba(0, 0, 0, 200));
    al_draw_text(_font, rgb(255, 255, 255), SCREEN_W * .5, SCREEN_H * .5 - 150,
                 ALLEGRO_ALIGN_CENTER, "PAUSED");
    al_draw_text(_font, rgb(255, 255, 255), SCREEN_W * .5, SCREEN_H * .5 - 78,
                 ALLEGRO_ALIGN_CENTER, "[SPACE]");
    al_draw_text(_font, rgb(44, 114, 61), SCREEN_W * .5, SCREEN_H * .5 + 6,
                 ALLEGRO_ALIGN_CENTER, "to continue");
    al_draw_text(_font, rgb(255, 255, 255), SCREEN_W * .5, SCREEN_H * .5 + 78,
                 ALLEGRO_ALIGN_CENTER, "[E]");
    al_draw_text(_font, rgb(186, 51, 54), SCREEN_W * .5, SCREEN_H * .5 + 150,
                 ALLEGRO_ALIGN_CENTER, "to exit");
}

// void ScreenSaver::Clear() {
//     _grid_pos = 0;
//     for (int i = 0; i < _size; i++)
//         if (_objects[i] != nullptr)
//             _remove(i, true);
// }

void ScreenSaver::_remove(int i) {
    _objects[i] = _objects.back();
    _objects.pop_back();
}

void ScreenSaver::Clear() { _objects.clear(); }
