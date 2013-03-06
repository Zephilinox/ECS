#ifndef COMPONENT_HPP
#define COMPONENT_HPP

//STD

//3RD

//SELF
#include "Constants.hpp"

class Component
{
public:
    Component();
    virtual ~Component();
    Component& operator=(const Component&);
    constant::Comp type = constant::Comp::Base;
};

#endif
