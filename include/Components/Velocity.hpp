#ifndef Velocity_HPP
#define Velocity_HPP

//STD

//3RD

//SELF
#include "Constants.hpp"
#include "Components/Component.hpp"
#include "Vector.hpp"

class Velocity : public Component
{
public:
    Velocity();

    zge::Vector velocity;
};

#endif
