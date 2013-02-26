#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

namespace constant
{
    const double pi = 3.141592653;

    enum Component
    {
        Base = 0, Health, Movement, Display
    };

    const int windowWidth = 800;
    const int windowHeight = 800;
    const int maxComponents = 128;
}


#endif
