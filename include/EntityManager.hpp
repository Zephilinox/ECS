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
    std::shared_ptr<Entity> createEntity();
    bool deleteEntity(unsigned int);

    template <class T> std::vector<std::shared_ptr<Entity>> getEntsByComponent();
    template <class T, class... Other> std::vector<std::shared_ptr<Entity>> getEntsByComponents();

    std::shared_ptr<Entity> getEntByID(unsigned int);

private:
    static std::vector<std::shared_ptr<Entity>> m_Entities;
    static unsigned int m_EntityCount;
};

template <class T>
std::vector<std::shared_ptr<Entity>> EntityManager::getEntsByComponent()
{
    std::vector<std::shared_ptr<Entity>> ents;

    for (unsigned int i = 0; i < m_Entities.size(); ++i)
    {
        if (m_Entities.at(i)->hasComponent<T>())
        {
            ents.push_back(m_Entities.at(i));
        }
    }

    return ents;
}

template <class T, class... Other> std::vector<std::shared_ptr<Entity>> EntityManager::getEntsByComponents()
{
    std::vector<std::shared_ptr<Entity>> ents;

    //std::cout << "GetComps Start\n";

    for (unsigned int i = 0; i < m_Entities.size(); ++i)
    {
        //std::cout << "calling hasComponent<T, Other...>()\n";
        if (m_Entities.at(i)->hasComponent<T, Other...>())
        {
            //std::cout << "pushing back Ent " << m_Entities.at(i)->id << "\n";
            ents.push_back(m_Entities.at(i));
        }
    }

    //std::cout << "GetComps End\n";
    return ents;
}

#endif
