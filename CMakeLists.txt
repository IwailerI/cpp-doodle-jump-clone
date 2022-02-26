cmake_minimum_required(VERSION 3.21)
project(project)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Program\ Files/JetBrains/CLion\ 2021.3.2/bin/mingw/include)

add_executable(project
        main.cpp
        allegro/AllegroBase.hpp allegro/AllegroBase.cpp
        allegro/Allegro.cpp allegro/Allegro.h
        util/Vector2.cpp util/Vector2.h
        shapes/Shape.cpp shapes/Shape.h
        shapes/Square.cpp shapes/Square.h
        shapes/Circle.cpp shapes/Circle.h
        ScreenSaver.cpp ScreenSaver.h
        shapes/ShapeFactory.cpp shapes/ShapeFactory.h)

target_link_libraries(project
        allegro
        allegro_primitives
        )