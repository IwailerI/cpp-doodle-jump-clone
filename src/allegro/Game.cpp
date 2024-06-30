//
// Created by wailer on 22/02/2022.
//

#include "Game.h"

#include <exception>
#include <memory>

#include "../Player.h"

Game::Game()
    : _screen_saver(ScreenSaver::Instance()),
      _physics_server(PhysicsServer::Instance()),
      _level_manager(LevelManager::Instance()) {
    if (!Init(SCREEN_W, SCREEN_H, FPS)) throw std::exception();
}

void Game::Fps() {
    switch (_state) {
        case State::IN_GAME:
            if (IsPressed(ALLEGRO_KEY_ESCAPE)) {
                _state = State::PAUSE;
                return;
            }

            if (_player->isDeathAnimationFinished()) {
                _state = State::END;
                return;
            }

            _update_player_input();
            _physics_server.Update();
            _level_manager.Update();
            _screen_saver.Update();
            break;
        case State::PAUSE:
            if (IsPressed(ALLEGRO_KEY_SPACE)) {
                _state = State::IN_GAME;
            } else if (IsPressed(ALLEGRO_KEY_E)) {
                Exit();
            }
            break;
        case State::TITLE:
            if (IsPressed(ALLEGRO_KEY_SPACE)) {
                _state = State::IN_GAME;
                _start_game();
            }
            break;
        case State::END:
            if (IsPressed(ALLEGRO_KEY_SPACE)) {
                _level_manager.Reset();
                _physics_server.Clear();
                _screen_saver.Clear();
                _state = State::IN_GAME;
                _start_game();
            } else if (IsPressed(ALLEGRO_KEY_ESCAPE)) {
                Exit();
            }
            break;
    }
}

void Game::Draw() {
    switch (_state) {
        case State::IN_GAME:
            _screen_saver.Draw();
            break;
        case State::PAUSE:
            _screen_saver.Draw();
            _screen_saver.DrawPauseMenu();
            break;
        case State::TITLE:
            _screen_saver.DrawTitleScreen();
            break;
        case State::END:
            _screen_saver.DrawEndScreen();
            break;
    }
}

void Game::Run() { AllegroBase::Run(); }

void Game::_start_game() {
    _player = std::make_shared<Player>(Vector2(150, 600));
    _screen_saver.Add(_player);
    _physics_server.RegisterPlayer(_player);
    _level_manager.RegisterPlayer(_player);

    auto p = std::make_shared<Platform>(Vector2(150, 700));

    _physics_server.AddCollider(p);
    _screen_saver.Add(p);
}

void Game::_update_player_input() {
    _player->is_left_held =
        IsPressed(ALLEGRO_KEY_LEFT) || IsPressed(ALLEGRO_KEY_A);
    _player->is_right_held =
        IsPressed(ALLEGRO_KEY_RIGHT) || IsPressed(ALLEGRO_KEY_D);
}
