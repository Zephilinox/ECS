#include "Systems/MovementSystem.hpp"

std::vector<std::shared_ptr<Entity>> MovementSystem::m_Ents;
EntityManager MovementSystem::m_EntMan;

MovementSystem::MovementSystem()
{
}

void MovementSystem::run(double argDT)
{
    m_Ents = m_EntMan.getEntsByComps<Movement, Display>();

    for (size_t i = 0; i < m_Ents.size(); ++i)
    {
        Display* disp = m_Ents[i]->comp<Display>().get();
        Movement* mov = m_Ents[i]->comp<Movement>().get();

        disp->sprite.move(mov->velocity.x * argDT, mov->velocity.y * argDT);
    }
}
