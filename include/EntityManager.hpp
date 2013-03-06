#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

//STD
#include <vector>
#include <string>
#include <memory>

//3RD

//SELF
#include "Entity.hpp"

class EntityManager
{
public:
    EntityManager();
    std::shared_ptr<Entity>& createEnt();
    std::shared_ptr<Entity>& addEnt(Entity);
    bool deleteEnt(unsigned int);

    template <class T> std::vector<std::shared_ptr<Entity>> getEntsByComp();
    template <class T, class... Other> std::vector<std::shared_ptr<Entity>> getEntsByComps();

    std::shared_ptr<Entity>& getEntByID(unsigned int);
    static std::shared_ptr<Entity> nullEnt;
private:
    static std::vector<std::shared_ptr<Entity>> m_Ents;
    static unsigned int m_EntCount;
};

template <class T>
std::vector<std::shared_ptr<Entity>> EntityManager::getEntsByComp()
{
    std::vector<std::shared_ptr<Entity>> ents;

    for (unsigned int i = 0; i < m_Ents.size(); ++i)
    {
        if (m_Ents[i]->hasComp<T>())
        {
            ents.push_back(m_Ents[i]);
        }
    }

    return ents;
}

template <class T, class... Other> std::vector<std::shared_ptr<Entity>> EntityManager::getEntsByComps()
{
    std::vector<std::shared_ptr<Entity>> ents;

    for (unsigned int i = 0; i < m_Ents.size(); ++i)
    {
        if (m_Ents[i]->hasComps<T, Other...>())
        {
            ents.push_back(m_Ents[i]);
        }
    }

    return ents;
}

#endif
