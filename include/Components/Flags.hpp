#ifndef FLAGS_HPP
#define FLAGS_HPP

//STD
#include <bitset>

//3RD

//SELF
#include "Constants.hpp"
#include "Components/Component.hpp"

class Flags : public Component
{
public:
    Flags();
    std::bitset<constant::maxFlags> flags;
private:
};

#endif
