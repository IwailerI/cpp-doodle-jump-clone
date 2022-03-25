cmake_minimum_required(VERSION 3.21)
project(project)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Program\ Files/JetBrains/CLion\ 2021.3.2/bin/mingw)

add_executable(project
        main.cpp
        allegro/AllegroBase.hpp allegro/AllegroBase.cpp
        allegro/Game.cpp allegro/Game.h
        util/Vector2.cpp util/Vector2.h
        ScreenSaver.cpp ScreenSaver.h
        objects/GameObject.cpp objects/GameObject.h
        objects/Transform.cpp objects/Transform.h
        objects/Sprite.cpp objects/Sprite.h
        objects/Collider.cpp objects/Collider.h
        Player.cpp Player.h
        PhysicsServer.cpp PhysicsServer.h
        objects/platforms/Platform.cpp objects/platforms/Platform.h
        objects/enemies/Enemy.h objects/enemies/Enemy.cpp
        LevelManager.cpp LevelManager.h
        ResourceManager.cpp ResourceManager.h
        )

target_link_libraries(project
        allegro
        allegro_primitives
        allegro_image
        allegro_font
        allegro_ttf
        )
