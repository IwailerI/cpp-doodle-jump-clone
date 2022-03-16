//
// Created by wailer on 16/03/2022.
//

#include "ResourceManager.h"

#include "iostream" // FIXME TODO DEBUG REMOVE

ResourceManager::ResourceManager() {
    // Player
    sprite_player = al_load_bitmap((FILEPATH+"player_look_right.png").c_str());

    // Platforms
    sprite_platform = al_load_bitmap((FILEPATH+"platform.png").c_str());

    // Enemies
    //

    // Fonts
    font = al_load_ttf_font((FILEPATH+"nasalization.otf").c_str(), 72, 0);
//    font = al_load_bitmap_font((FILEPATH+"font.ttf").c_str());

    std::cout << (FILEPATH+"font.ttf").c_str() << std::endl; // WHY
    std::cout << font << " <- _font of ResourceManager" << std::endl;
}
