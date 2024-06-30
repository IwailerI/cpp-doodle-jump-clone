//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <random>

class util {
   public:
    inline static double randf(double min, double max) {
        double f = std::rand();
        f /= RAND_MAX;
        f *= max - min;
        return f + min;
    }

    inline static double clamp(double n, double low, double high) {
        return max(min(n, high), low);
    }

    inline static double min(double a, double b) { return (a < b) ? a : b; }

    inline static double max(double a, double b) { return (a > b) ? a : b; }
};
#endif  // PROJECT_UTILS_H
