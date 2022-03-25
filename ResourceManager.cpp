//
// Created by wailer on 16/03/2022.
//

#include "ResourceManager.h"

#include "iostream" // FIXME TODO DEBUG REMOVE

ResourceManager::ResourceManager() {
    // Player
    sprite_player_right = al_load_bitmap((FILEPATH+"player_look_right.png").c_str());
    if (sprite_player_right == nullptr) {
        std::cout << "Unable to find " + FILEPATH << std::endl;
        return;
    }
    sprite_player_left = al_load_bitmap((FILEPATH+"player_look_left.png").c_str());


    // Platforms
    sprite_platform = al_load_bitmap((FILEPATH+"platform.png").c_str());

    // Enemies
    sprite_enemy_simple = al_load_bitmap((FILEPATH+"enemy_simple.png").c_str());

    // Fonts
    font = al_load_ttf_font((FILEPATH+"font.ttf").c_str(), 72, 0);
//    font = al_load_bitmap_font((FILEPATH+"font.ttf").c_str());
}
