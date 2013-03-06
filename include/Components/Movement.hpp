#ifndef Movement_HPP
#define Movement_HPP

//STD

//3RD

//SELF
#include "Constants.hpp"
#include "Components/Component.hpp"
#include "Utility/Vector.hpp"

class Movement : public Component
{
public:
    Movement();

    zge::Vector velocity;
    int acceleration;
};

#endif
