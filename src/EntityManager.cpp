#include "EntityManager.hpp"

std::vector<std::shared_ptr<Entity>> EntityManager::m_Entities;

unsigned int EntityManager::m_EntityCount = 0;

EntityManager::EntityManager()
{
}

std::shared_ptr<Entity> EntityManager::createEntity()
{
    std::shared_ptr<Entity> ent(new Entity(++m_EntityCount));

    m_Entities.push_back(ent);
    return m_Entities.back();
}

bool EntityManager::deleteEntity(unsigned int argID)
{
    for (unsigned int i = 0; i < m_Entities.size(); ++i)
    {
        if (m_Entities[i]->id == argID)
        {
            m_Entities.erase(m_Entities.begin() + i);
            return true;
        }
    }

    return false;
}

std::shared_ptr<Entity> EntityManager::getEntByID(unsigned int argID)
{
    for (unsigned int i = 0; i < m_Entities.size(); ++i)
    {
        if (m_Entities[i]->id == argID)
        {
            return m_Entities[i];
        }
    }

    return nullptr;
}
