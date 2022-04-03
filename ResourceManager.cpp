//
// Created by wailer on 16/03/2022.
//

#include "ResourceManager.h"

#include "iostream" // FIXME TODO DEBUG REMOVE

ResourceManager::ResourceManager() {
    if (!al_change_directory(FILEPATH.c_str())) {
        std::cout << "Invalid filepath for resource directory\n";
        std::cout << "Check ResourceManager.h constant FILEPATH" << std::endl;
        exit(1);
    }



    // Player
    sprite_player_right = al_load_bitmap("player_look_right.png");
    if (sprite_player_right == nullptr) {
        std::cout << "Unable to find player_look_right.png" << std::endl;
        exit(1);
    }

    sprite_player_left = al_load_bitmap("player_look_left.png");
    if (sprite_player_left == nullptr) {
        std::cout << "Unable to find player_look_left.png" << std::endl;
        exit(1);
    }

    sprite_player_dead = al_load_bitmap("player_dead_left.png");
    if (sprite_player_dead == nullptr) {
        std::cout << "Unable to find player_dead_left.png" << std::endl;
        exit(1);
    }



    // Platforms
    sprite_platform = al_load_bitmap("platform.png");
    if (sprite_platform == nullptr) {
        std::cout << "Unable to find platform.png" << std::endl;
        exit(1);
    }

    sprite_platform_fake = al_load_bitmap("fake_platform.png");
    if (sprite_platform_fake == nullptr) {
        std::cout << "Unable to find fake_platform.png" << std::endl;
        exit(1);
    }

    sprite_platform_fake_broken = al_load_bitmap("fake_platform_broken.png");
    if (sprite_platform_fake_broken == nullptr) {
        std::cout << "Unable to find fake_platform_broken.png" << std::endl;
        exit(1);
    }

    sprite_platform_moving = al_load_bitmap("moving_platform.png");
    if (sprite_platform_moving == nullptr) {
        std::cout << "Unable to find moving_platform.png" << std::endl;
        exit(1);
    }


    // Enemies
    sprite_enemy_simple = al_load_bitmap("enemy_simple.png");
    if (sprite_enemy_simple == nullptr) {
        std::cout << "Unable to find enemy_simple.png" << std::endl;
        exit(1);
    }

    sprite_enemy_simple_victory = al_load_bitmap("enemy_simple_grin.png");
    if (sprite_enemy_simple_victory == nullptr) {
        std::cout << "Unable to find enemy_simple_grin.png" << std::endl;
        exit(1);
    }

    sprite_enemy_simple_dead = al_load_bitmap("enemy_simple_dead.png");
    if (sprite_enemy_simple_dead == nullptr) {
        std::cout << "Unable to find enemy_simple_dead.png" << std::endl;
        exit(1);
    }

    // Fonts
    font = al_load_ttf_font("font.ttf", 72, 0);
    if (font == nullptr) {
        std::cout << "Unable to find font.ttf" << std::endl;
        exit(1);
    }
//    font = al_load_bitmap_font((FILEPATH+"font.ttf").c_str());
}
