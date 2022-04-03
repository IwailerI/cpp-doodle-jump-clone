cmake_minimum_required(VERSION 3.21)
project(project)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Program\ Files/JetBrains/CLion\ 2021.3.2/bin/mingw)

add_executable(project

        main.cpp

        allegro/AllegroBase.hpp allegro/AllegroBase.cpp
        util/constants.h
        util/utils.h

        util/Vector2.cpp util/Vector2.h

        allegro/Game.cpp allegro/Game.h
        Player.cpp Player.h

        ScreenSaver.cpp ScreenSaver.h
        LevelManager.cpp LevelManager.h
        PhysicsServer.cpp PhysicsServer.h
        ResourceManager.cpp ResourceManager.h

        objects/GameObject.cpp objects/GameObject.h
        objects/Sprite.cpp objects/Sprite.h
        objects/Collider.cpp objects/Collider.h

        objects/platforms/PlatformFactory.h objects/platforms/PlatformFactory.cpp
        objects/platforms/Platform.cpp objects/platforms/Platform.h
        objects/platforms/FakePlatform.cpp objects/platforms/FakePlatform.h
        objects/platforms/MovingPlatform.cpp objects/platforms/MovingPlatform.h

        objects/enemies/EnemyFactory.h objects/enemies/EnemyFactory.cpp
        objects/enemies/Enemy.h objects/enemies/Enemy.cpp
        objects/enemies/BigEnemy.h

        objects/enemies/SmallEnemy.h objects/enemies/FlyingEnemy.h)

target_link_libraries(project
        allegro
        allegro_primitives
        allegro_image
        allegro_font
        allegro_ttf
        )
