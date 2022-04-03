//
// Created by wailer on 03/04/2022.
//

#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <random>

class util {
public:
    static double randf(double min, double max) {
        double f = std::rand();
        f /= RAND_MAX;
        f *= max - min;
        return f + min;
    }

    static double clamp(double n, double min, double max) {
        if (n > max) return max;
        else if (n < min) return min;
        return n;
    }

    static double min(double a, double b) {
        if (a < b) return a;
        return b;
    }
};
#endif //PROJECT_UTILS_H
