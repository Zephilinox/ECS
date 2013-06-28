#ifndef ENTITY_HPP
#define ENTITY_HPP

//STD
#include <vector>
#include <iostream>
#include <memory>
#include <bitset>
#include <typeinfo>

//3RD
#include <SFML/System.hpp>

//SELF
#include "Constants.hpp"
#include "Components/Component.hpp"

class Entity
{
public:
    Entity(unsigned int = 0);

    // All entities should use an id, assigned by the Entity Manager, to differentiate between them.
    unsigned int id;

    template <class T> bool hasComp();

    // Variadic template will allow users and systems to check if an entity has any number of specific entities
    template <class T1, class T2, class... Other> bool hasComps();

    template <class T> bool removeComp();

    template <class T> std::shared_ptr<T> comp();

private:
    std::vector<std::shared_ptr<Component>> m_Comps;

    // This is used to register a component, so that I can quickly check if it has the component or several components without iterating through the vector of components
    std::bitset<constant::maxComps> m_CompFlags;

    // Disambiguate Recursive Variadic Template
    template <class T> bool hasComps()
    {
        return this->hasComp<T>();
    }
};

template <class T>
bool Entity::hasComp()
{
    T comp;

    if (m_CompFlags.test(comp.type))
    {
        return true;
    }

    return false;
}

template <class T1, class T2, class... Other>
bool Entity::hasComps()
{
    T1 comp;

    if (m_CompFlags.test(comp.type))
    {
        return (true && this->hasComps<T2, Other...>());
    }

    return false;
}

template <class T>
bool Entity::removeComp()
{
    T comp;

    for (unsigned int i = 0; i < m_Comps.size(); ++i)
    {
        if (m_Comps[i]->type == comp.type)
        {
            //unregister component from flags
            m_CompFlags.set(comp.type, false);

            m_Comps.erase(m_Comps.begin() + i);
            return true;
        }
    }

    return false;
}

template <class T>
std::shared_ptr<T> Entity::comp()
{
    T comp;

    for (unsigned int i = 0; i < m_Comps.size(); ++i)
    {
        if (m_Comps[i]->type == comp.type)
        {
            return std::static_pointer_cast<T>(m_Comps[i]);
        }
    }

    m_CompFlags.set(comp.type);
    m_Comps.push_back(std::shared_ptr<Component>(new T()));

    return std::static_pointer_cast<T>(m_Comps.back());
}

#endif
