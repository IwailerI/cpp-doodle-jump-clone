cmake_minimum_required(VERSION 3.21)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project

        src/main.cpp

        src/allegro/AllegroBase.hpp src/allegro/AllegroBase.cpp
        src/util/constants.h
        src/util/utils.h

        src/util/Vector2.cpp src/util/Vector2.h

        src/allegro/Game.cpp src/allegro/Game.h
        src/Player.cpp src/Player.h

        src/ScreenSaver.cpp src/ScreenSaver.h
        src/LevelManager.cpp src/LevelManager.h
        src/PhysicsServer.cpp src/PhysicsServer.h
        src/ResourceManager.cpp src/ResourceManager.h

        src/objects/GameObject.cpp src/objects/GameObject.h
        src/objects/Sprite.cpp src/objects/Sprite.h
        src/objects/Collider.cpp src/objects/Collider.h

        src/objects/platforms/PlatformFactory.h src/objects/platforms/PlatformFactory.cpp
        src/objects/platforms/Platform.cpp src/objects/platforms/Platform.h
        src/objects/platforms/FakePlatform.cpp src/objects/platforms/FakePlatform.h
        src/objects/platforms/MovingPlatform.cpp src/objects/platforms/MovingPlatform.h

        src/objects/enemies/EnemyFactory.h src/objects/enemies/EnemyFactory.cpp
        src/objects/enemies/Enemy.h src/objects/enemies/Enemy.cpp
        src/objects/enemies/BigEnemy.h
        src/objects/enemies/SmallEnemy.h
        src/objects/enemies/FlyingEnemy.h

        src/objects/content/Content.cpp src/objects/content/Content.h
        src/objects/content/Spring.cpp src/objects/content/Spring.h

        )

target_link_libraries(project
        allegro
        allegro_primitives
        allegro_image
        allegro_font
        allegro_ttf
        )
