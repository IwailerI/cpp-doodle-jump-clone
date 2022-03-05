cmake_minimum_required(VERSION 3.21)
project(project)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Program\ Files/JetBrains/CLion\ 2021.3.2/bin/mingw/include)

add_executable(project
        main.cpp
        allegro/AllegroBase.hpp allegro/AllegroBase.cpp
        allegro/Allegro.cpp allegro/Allegro.h
        util/Vector2.cpp util/Vector2.h
        ScreenSaver.cpp ScreenSaver.h
        objects/GameObject.cpp objects/GameObject.h
        objects/Transform.cpp objects/Transform.h
        objects/simpleShapes/ColorRect.cpp objects/simpleShapes/ColorRect.h
        objects/Sprite.cpp objects/Sprite.h
        objects/Collider.cpp objects/Collider.h)

target_link_libraries(project
        allegro
        allegro_primitives
        )