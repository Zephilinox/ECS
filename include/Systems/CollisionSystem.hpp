#ifndef COLLISIONSYSTEM_HPP
#define COLLISIONSYSTEM_HPP

//STD
#include <iostream>
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Components/Display.hpp"
#include "Components/Flags.hpp"
#include "Components/Movement.hpp"

class CollisionSystem
{
public:
    CollisionSystem();
    void run(double);
private:
    static std::vector<std::shared_ptr<Entity>> m_Ents;
    static EntityManager m_EntMan;
};

#endif
