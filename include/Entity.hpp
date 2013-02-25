#ifndef ENTITY_HPP
#define ENTITY_HPP

//STD
#include <vector>
#include <iostream>
#include <memory>
#include <bitset>

//3RD
#include <SFML/System.hpp>

//SELF
#include "Constants.hpp"
#include "Component.hpp"
class Entity
{
public:
    Entity(unsigned int);

    unsigned int id;

    template <class T> bool hasComponent();
    template <class T1, class T2, class... Other> bool hasComponent();

    template <class T> bool removeComponent();
    template <class T> std::shared_ptr<T> component();

    std::vector<std::shared_ptr<Component>> components;
    std::bitset<constant::maxComponents> componentFlags;
};

template <class T>
bool Entity::hasComponent()
{
    T comp;

    if (componentFlags.test(comp.type))
    {
        //std::cout << "Ent has " << comp.type << "\n";
        return true;
    }

    return false;
}

template <class T1, class T2, class... Other>
bool Entity::hasComponent()
{
    T1 comp;

    if (componentFlags.test(comp.type))
    {
        //std::cout << "Ent has " << comp.type << "\n";
        return (true && this->hasComponent<T2, Other...>());
    }

    //std::cout << "End does not have " << comp.type << "\n";
    return false;
}

template <class T>
bool Entity::removeComponent()
{
    T comp;

    for (unsigned int i = 0; i < components.size(); ++i)
    {
        if (components.at(i)->type == comp.type)
        {
            componentFlags.set(comp.type, false);
            components.erase(components.begin() + i);
            return true;
        }
    }

    return false;
}

template <class T>
std::shared_ptr<T> Entity::component()
{
    T comp;

    for (unsigned int i = 0; i < components.size(); ++i)
    {
        if (components.at(i)->type == comp.type)
        {
            //std::cout << "component: " << components.at(i)->name << "("<< i << ") == " << compType->name << "\n---\n";
            return std::dynamic_pointer_cast<T>(components.at(i));
        }
        else
        {
            //std::cout << "component: " << components.at(i)->name << "("<< i << ") != " << compType->name << "\n";
        }
    }

    //std::cout << "component: " << compType->name << " not found\n---\n";


    componentFlags.set(comp.type);
    components.push_back(std::shared_ptr<Component>(new T()));

    return std::dynamic_pointer_cast<T>(components.back());
}

#endif
