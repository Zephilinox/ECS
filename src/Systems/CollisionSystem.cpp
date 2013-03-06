#include "Systems/CollisionSystem.hpp"

std::vector<std::shared_ptr<Entity>> CollisionSystem::m_Ents;
EntityManager CollisionSystem::m_EntMan;

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::run(double argDT)
{
    m_Ents = m_EntMan.getEntsByComps<Display, Flags>();
}

