#ifndef Health_HPP
#define Health_HPP

//STD

//3RD

//SELF
#include "Constants.hpp"
#include "Components/Component.hpp"

class Health : public Component
{
public:
    Health();
    unsigned int health;
};

#endif
