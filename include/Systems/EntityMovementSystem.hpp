#ifndef ENTITYMOVEMENTSYSTEM_HPP
#define ENTITYMOVEMENTSYSTEM_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Components/Velocity.hpp"
#include "Components/Sprite.hpp"
#include "Vector.hpp"

class EntityMovementSystem
{
public:
    EntityMovementSystem();
    void run(float);
private:
    static std::vector<std::shared_ptr<Entity>> m_Ents;
    static EntityManager m_EntMan;
};

#endif
