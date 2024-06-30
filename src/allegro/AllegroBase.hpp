#pragma once

//namespace AllegroBase;

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>
// #include "windows.h"
// #include <allegro5/allegro_windows.h>

#include "../util/constants.h"


class AllegroBase
{
public:
    AllegroBase();
    virtual ~AllegroBase();

    bool Init( int screenWidth, int screenHeight, int fps );
    static bool InitAllegroAddons();

    void Destroy();

    virtual void Run();
    void Exit();

    // See help for ALLEGRO_KEYBOARD_STATE
    bool IsPressed( int keycode );

    // void FocusGraphicWin();

    virtual void Fps() = 0;
    virtual void Draw() = 0;
    virtual void OnKeyDown( const ALLEGRO_KEYBOARD_EVENT &keyboard ) {};
    virtual void OnKeyUp( const ALLEGRO_KEYBOARD_EVENT &keyboard ) {};

protected:
    ALLEGRO_DISPLAY *alDisplay_;
    ALLEGRO_EVENT_QUEUE *alEventQueue_;
    ALLEGRO_TIMER *alTimer_;
    bool pressedKeys_[ALLEGRO_KEY_MAX];

private:
    bool exit_;

};
