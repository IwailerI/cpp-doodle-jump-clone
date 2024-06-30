//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_PLATFORMFACTORY_H
#define PROJECT_PLATFORMFACTORY_H

#include "../../util/utils.h"
#include "../content/Content.h"
#include "../content/Spring.h"
#include "FakePlatform.h"
#include "MovingPlatform.h"
#include "Platform.h"

class PlatformFactory {
   private:
    static std::shared_ptr<Platform> _random_platform(bool fake = false);
    static std::shared_ptr<Content> _random_content();

   public:
    static std::shared_ptr<Platform> GetRandomPlatform(double height,
                                                       bool fake = false);
};

#endif  // PROJECT_PLATFORMFACTORY_H
