#ifndef HEALTHCOMPONENT_HPP
#define HEALTHCOMPONENT_HPP

//STD

//3RD

//SELF
#include "Constants.hpp"
#include "Component.hpp"

class HealthComponent : public Component
{
public:
    HealthComponent();
    unsigned int health;
};

#endif
