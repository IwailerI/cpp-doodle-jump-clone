//
// Created by wailer on 22/02/2022.
//

#include "Game.h"
#include "../Player.h"
#include <exception>

Game::Game(): _screen_saver(ScreenSaver::Instance()), _physics_server(PhysicsServer::Instance()), _level_manager(LevelManager::Instance()) {
    if (!Init(SCREEN_W, SCREEN_H, FPS)) throw std::exception();;
}

void Game::Fps() {
    if (_state == INGAME) {

        // pause
        if (IsPressed(ALLEGRO_KEY_ESCAPE)) {
            _state = PAUSE;
            return;
        }

        // check for players death
        if (_player->isCompletelyDead()) {
            _state = END;
            return;
        }

        _update_player_input();
        _physics_server.Update();
        _level_manager.Update();
        _screen_saver.Update();
    } else if (_state == PAUSE) {
        // unpause
        if (IsPressed(ALLEGRO_KEY_SPACE))
           _state = INGAME;
        if (IsPressed(ALLEGRO_KEY_E))
            Exit();

    } else if (_state == TITLE) {
        if (IsPressed(ALLEGRO_KEY_SPACE)) {
            // start the game
            _start_game();
            _state = INGAME;
        }
    } else if (_state == END) {
        if (IsPressed(ALLEGRO_KEY_SPACE)) {
            _level_manager.Reset();
            _physics_server.Clear(true);
            _screen_saver.Clear(false);
            _start_game();
            _state = INGAME;
        } else if (IsPressed(ALLEGRO_KEY_ESCAPE)) {
            Exit();
        }
    }
}

void Game::Draw() {
    if (_state == INGAME) {
        _screen_saver.Draw();
    } else if (_state == PAUSE) {
        _screen_saver.Draw();
        _screen_saver.DrawPauseMenu();
    } else if (_state == TITLE) {
        _screen_saver.DrawTitleScreen();
    } else {
        _screen_saver.DrawEndScreen();
    }
}

void Game::Run() {
    AllegroBase::Run();
}

void Game::_start_game() {
    _player = new Player(Vector2(150, 600));
    _screen_saver.Add(_player);
    _physics_server.RegisterPlayer(_player);
    _level_manager.RegisterPlayer(_player);

    auto p = new Platform(Vector2(150, 700));
    _physics_server.Add(p);
    _screen_saver.Add(p);
}

void Game::_update_player_input() {
    _player->is_left_held = IsPressed(ALLEGRO_KEY_LEFT) || IsPressed(ALLEGRO_KEY_A);
    _player->is_right_held = IsPressed(ALLEGRO_KEY_RIGHT) || IsPressed(ALLEGRO_KEY_D);
}
