#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

namespace constant
{
    const double pi = 3.141592653;

    enum Component
    {
        BaseComponent = 0, HealthComponent, VelocityComponent, SpriteComponent
    };

    const int windowWidth = 800;
    const int windowHeight = 800;
    const int maxComponents = 100;
}


#endif
