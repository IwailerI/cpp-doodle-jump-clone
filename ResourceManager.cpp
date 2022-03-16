//
// Created by wailer on 16/03/2022.
//

#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    // Player
    sprite_player = al_load_bitmap((FILEPATH+"player_look_right.png").c_str());

    // Platforms
    sprite_platform = al_load_bitmap((FILEPATH+"platform.png").c_str());

    // Enemies
    //

    // Other?
    //
}
