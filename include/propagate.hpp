#ifndef PROPAGATE_HPP
#define PROPAGATE_HPP

#include <iostream>
#include <cmath>
#include "include/Layer.hpp"

enum PropagationType {
    BACKWARD,
    FORWARD
};

class Propagate {
private:
    PropagationType type;

public:
    Propagate(PropagationType type) : type(type) {}

    void executePropagation(Layer& layer);

#endif
