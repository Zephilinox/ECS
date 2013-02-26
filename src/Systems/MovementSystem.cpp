#include "Systems/MovementSystem.hpp"

std::vector<std::shared_ptr<Entity>> MovementSystem::m_Ents;
EntityManager MovementSystem::m_EntMan;

MovementSystem::MovementSystem()
{
}

void MovementSystem::run(double argDT)
{
    m_Ents = m_EntMan.getEntsByComponents<Movement, Display>();

    for (size_t i = 0; i < m_Ents.size(); ++i)
    {
        zge::Vector vel = m_Ents[i]->component<Movement>()->velocity;

        m_Ents[i]->component<Display>()->sprite.move(vel.x * argDT, vel.y * argDT);
    }
}
