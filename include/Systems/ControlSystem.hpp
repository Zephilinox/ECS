#ifndef CONTROLSYSTEM_HPP
#define CONTROLSYSTEM_HPP

//STD
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Components/Movement.hpp"
#include "Components/Display.hpp"
#include "Components/Flags.hpp"

#include "Utility/Vector.hpp"

class ControlSystem
{
public:
    ControlSystem();
    void run(double);
private:
    static std::vector<std::shared_ptr<Entity>> m_Ents;
    static EntityManager m_EntMan;
};

#endif
