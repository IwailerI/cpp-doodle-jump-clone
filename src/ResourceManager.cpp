//
// Created by wailer on 16/03/2022.
//

#include "ResourceManager.h"

#include <sstream>

img load_img(const char* path) {
    auto p = al_load_bitmap(path);
    if (p == nullptr) {
        std::stringstream msg;
        msg << "Unable to find " << path;
        throw str_exception(msg.str());
    }
    return p;
}

ResourceManager::ResourceManager() {
    if (!al_change_directory(FILEPATH.c_str())) {
        throw str_exception(
            "Invalid filepath for resource directory. Check ResourceManager.h "
            "constant FILEPATH.");
    }

    // Player
    sprite_player_right = load_img("player_look_right.png");
    sprite_player_left = load_img("player_look_left.png");
    sprite_player_dead = load_img("player_dead_left.png");

    // Platforms
    sprite_platform = load_img("platform.png");
    sprite_platform_fake = load_img("fake_platform.png");
    sprite_platform_fake_broken = load_img("fake_platform_broken.png");
    sprite_platform_moving = load_img("moving_platform.png");

    // Enemies
    sprite_enemy_simple = load_img("enemy_simple.png");
    sprite_enemy_simple_victory = load_img("enemy_simple_grin.png");
    sprite_enemy_simple_dead = load_img("enemy_simple_dead.png");
    sprite_enemy_large = load_img("enemy_large.png");
    sprite_enemy_large_victory = load_img("enemy_large_grin.png");
    sprite_enemy_large_dead = load_img("enemy_large_dead.png");
    sprite_enemy_small = load_img("enemy_small.png");
    sprite_enemy_small_victory = load_img("enemy_small_grin.png");
    sprite_enemy_small_dead = load_img("enemy_small_dead.png");
    sprite_enemy_flying = load_img("enemy_flying.png");
    sprite_enemy_flying_victory = load_img("enemy_flying_grin.png");
    sprite_enemy_flying_dead = load_img("enemy_flying_dead.png");

    // Contents
    sprite_spring = load_img("spring_1.png");
    sprite_spring_triggered = load_img("spring_2.png");

    // Fonts
    font = al_load_ttf_font("font.ttf", 72, 0);
    if (font == nullptr) {
        throw str_exception("Unable to find font.ttf");
    }
}
