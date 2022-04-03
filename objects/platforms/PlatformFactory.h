//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_PLATFORMFACTORY_H
#define PROJECT_PLATFORMFACTORY_H

#include "Platform.h"
#include "FakePlatform.h"
#include "MovingPlatform.h"

#include "../content/Content.h"
#include "../content/Spring.h"

#include "../../util/utils.h"

class PlatformFactory {
private:
    static Platform *_random_platform(bool fake = false);
    static Content *_random_content();
public:
    static Platform *GetRandomPlatform(double height, bool fake = false);
};


#endif //PROJECT_PLATFORMFACTORY_H
