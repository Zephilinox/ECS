#include "EntityManager.hpp"

std::shared_ptr<Entity>  EntityManager::nullEnt;
std::vector<std::shared_ptr<Entity>> EntityManager::m_Ents;

unsigned int EntityManager::m_EntCount = 0;

EntityManager::EntityManager()
{
    this->nullEnt = nullptr;
}

std::shared_ptr<Entity>& EntityManager::createEnt()
{
    std::shared_ptr<Entity> ent(new Entity(++m_EntCount));

    m_Ents.push_back(ent);
    return m_Ents.back();
}

std::shared_ptr<Entity>& EntityManager::addEnt(Entity argEnt)
{
    std::shared_ptr<Entity> ent(new Entity(argEnt));
    ent->id = ++m_EntCount;
    m_Ents.push_back(ent);

    return m_Ents.back();
}

bool EntityManager::deleteEnt(unsigned int argID)
{
    for (unsigned int i = 0; i < m_Ents.size(); ++i)
    {
        if (m_Ents[i]->id == argID)
        {
            m_Ents.erase(m_Ents.begin() + i);
            return true;
        }
    }

    return false;
}

std::shared_ptr<Entity>& EntityManager::getEntByID(unsigned int argID)
{
    for (unsigned int i = 0; i < m_Ents.size(); ++i)
    {
        if (m_Ents[i]->id == argID)
        {
            return m_Ents[i];
        }
    }

    return this->nullEnt;
}
