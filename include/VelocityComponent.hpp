#ifndef VELOCITYCOMPONENT_HPP
#define VELOCITYCOMPONENT_HPP

//STD

//3RD

//SELF
#include "Constants.hpp"
#include "Component.hpp"
#include "Vector.hpp"

class VelocityComponent : public Component
{
public:
    VelocityComponent();

    zge::Vector velocity;
};

#endif
