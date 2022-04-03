//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H

// global project settings
const int FPS = 60;
const int SCREEN_W = 480;
const int SCREEN_H = 854;

// player settings
const double GRAVITY = 1.5;
const double JUMP_VELOCITY = 30;
const double MOVEMENT_SPEED = 10;

// object delete treshold, when going offscreen
const double OBJECT_DELETE_TRESHOLD = SCREEN_H + 50;

// platforms

const double MIN_PLATFORM_SPEED = 1;
const double MAX_PLATFORM_SPEED = 10;

// generator settings, best to leave them be
const int SCROLL_TRESHOLD = SCREEN_H/3;
const double MAX_PLATFORM_DISTANCE = 210;
const double MIN_PLATFORM_DISTANCE = 40;
const double MAX_ENEMY_DISTANCE = 7500;
const double MIN_ENEMY_DISTANCE = 1000;
const double DISTANCE_RAMPUP = SCREEN_H*25;
const double OBJECT_SPAWN_TRESHOLD = -10;
const double FAKE_PLATFORM_CHANCE = .25;
const double ASSUMED_PLATFORM_HEIGHT = 30;

#endif //PROJECT_CONSTANTS_H
