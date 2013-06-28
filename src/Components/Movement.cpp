#include "Components/Movement.hpp"

Movement::Movement():
velocity(0, 0),
acceleration(0)
{
    type = constant::Comp::Movement;
}
