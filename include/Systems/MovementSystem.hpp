#ifndef MovementSystem_HPP
#define MovementSystem_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Components/Movement.hpp"
#include "Components/Display.hpp"
#include "Utility/Vector.hpp"

class MovementSystem
{
public:
    MovementSystem();
    void run(double);
private:
    static std::vector<std::shared_ptr<Entity>> m_Ents;
    static EntityManager m_EntMan;
};

#endif
