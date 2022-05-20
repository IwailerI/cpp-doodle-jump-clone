//
// Created by wailer on 16/03/2022.
//

#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    if (!al_change_directory(FILEPATH.c_str())) {
        throw str_exception("Invalid filepath for resource directory. Check ResourceManager.h constant FILEPATH.");
    }

    // Player
    sprite_player_right = al_load_bitmap("player_look_right.png");
    if (sprite_player_right == nullptr) {
        throw str_exception("Unable to find player_look_right.png");
    }

    sprite_player_left = al_load_bitmap("player_look_left.png");
    if (sprite_player_left == nullptr) {
        throw str_exception("Unable to find player_look_left.png");
    }

    sprite_player_dead = al_load_bitmap("player_dead_left.png");
    if (sprite_player_dead == nullptr) {
        throw str_exception("Unable to find player_dead_left.png");
    }



    // Platforms
    sprite_platform = al_load_bitmap("platform.png");
    if (sprite_platform == nullptr) {
        throw str_exception("Unable to find platform.png");
    }

    sprite_platform_fake = al_load_bitmap("fake_platform.png");
    if (sprite_platform_fake == nullptr) {
        throw str_exception("Unable to find fake_platform.png");
    }

    sprite_platform_fake_broken = al_load_bitmap("fake_platform_broken.png");
    if (sprite_platform_fake_broken == nullptr) {
        throw str_exception("Unable to find fake_platform_broken.png");
    }

    sprite_platform_moving = al_load_bitmap("moving_platform.png");
    if (sprite_platform_moving == nullptr) {
        throw str_exception("Unable to find moving_platform.png");
    }


    // Enemies
    sprite_enemy_simple = al_load_bitmap("enemy_simple.png");
    if (sprite_enemy_simple == nullptr) {
        throw str_exception("Unable to find enemy_simple.png");
    }

    sprite_enemy_simple_victory = al_load_bitmap("enemy_simple_grin.png");
    if (sprite_enemy_simple_victory == nullptr) {
        throw str_exception("Unable to find enemy_simple_grin.png");
    }

    sprite_enemy_simple_dead = al_load_bitmap("enemy_simple_dead.png");
    if (sprite_enemy_simple_dead == nullptr) {
        throw str_exception("Unable to find enemy_simple_dead.png");
    }


    sprite_enemy_large = al_load_bitmap("enemy_large.png");
    if (sprite_enemy_large == nullptr) {
        throw str_exception("Unable to find enemy_large.png");
    }

    sprite_enemy_large_victory = al_load_bitmap("enemy_large_grin.png");
    if (sprite_enemy_large_victory == nullptr) {
        throw str_exception("Unable to find enemy_large_grin.png");
    }

    sprite_enemy_large_dead = al_load_bitmap("enemy_large_dead.png");
    if (sprite_enemy_large_dead == nullptr) {
        throw str_exception("Unable to find enemy_large_dead.png");
    }

    sprite_enemy_small = al_load_bitmap("enemy_small.png");
    if (sprite_enemy_small == nullptr) {
        throw str_exception("Unable to find enemy_small.png");
    }

    sprite_enemy_small_victory = al_load_bitmap("enemy_small_grin.png");
    if (sprite_enemy_small_victory == nullptr) {
        throw str_exception("Unable to find enemy_small_grin.png");
    }

    sprite_enemy_small_dead = al_load_bitmap("enemy_small_dead.png");
    if (sprite_enemy_small_dead == nullptr) {
        throw str_exception("Unable to find enemy_small_dead.png");
    }

    sprite_enemy_flying = al_load_bitmap("enemy_flying.png");
    if (sprite_enemy_flying == nullptr) {
        throw str_exception("Unable to find enemy_flying.png");
    }

    sprite_enemy_flying_victory = al_load_bitmap("enemy_flying_grin.png");
    if (sprite_enemy_flying_victory == nullptr) {
        throw str_exception("Unable to find enemy_flying_grin.png");
    }

    sprite_enemy_flying_dead = al_load_bitmap("enemy_flying_dead.png");
    if (sprite_enemy_flying_dead == nullptr) {
        throw str_exception("Unable to find enemy_flying_dead.png");
    }


    // Contents
    sprite_spring = al_load_bitmap("spring_1.png");
    if (sprite_spring == nullptr) {
        throw str_exception("Unable to find spring_1.png");
    }
    sprite_spring_triggered = al_load_bitmap("spring_2.png");
    if (sprite_spring_triggered == nullptr) {
        throw str_exception("Unable to find spring_2.png");
    }


    // Fonts
    font = al_load_ttf_font("font.ttf", 72, 0);
    if (font == nullptr) {
        throw str_exception("Unable to find font.ttf");
    }
}
