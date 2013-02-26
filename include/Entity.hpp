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

    /// All entities should use an id, assigned by the Entity Manager, to differentiate between them.
    unsigned int id;

    /// Variadic template will allow users and systems to check if an entity has any number of specific entities
    template <class T> bool hasComponent();
    template <class T1, class T2, class... Other> bool hasComponent();

    template <class T> bool removeComponent();

    /**
     Need to figure out if:
         I should return std::shared_ptr, std::weak_ptr, pointer, or reference

         shared_ptr allows you to use '->' to directly access the underlying pointer, and you can get the underlying pointer yourself with .get()
         however, it becomes impossible to know when the object is deleted, since the returned shared_ptr can be stored by anyone thus increasing its reference count

         weak_ptr requires you to use .lock() which returns a shared_ptr, doesn't increase the reference count of it so you can store it, but results in uglyness due to the .lock() requirement
         storing a weak_ptr will mean you have to deal with an empty shared_ptr returning from .lock() if object is deleted

         a normal pointer will allow you to directly access the object, while also allowing you to store it without increasing reference count
         if you store a normal pointer and the object is deleted, if you try and access it it will access garbage and probably crash, so this isn't a good idea.

        a reference will allow you to access an object like a pointer, you can also store it, it also suffers from the same problem.

        So I can either keep shared_ptr and let users store it forever, or deal with ugly .lock() from weak_ptr
        or, I can keep shared_ptr and hope the user (which will most likely be me) stores it using a weak_ptr
    */

    template <class T> std::shared_ptr<T> component();

    std::vector<std::shared_ptr<Component>> components;

    /// This is used to register a component, so that I can quickly check if it has the component or several components without iterating through the vector of components
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
        if (components[i]->type == comp.type)
        {
            //unregister component from flags
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
        if (components[i]->type == comp.type)
        {
            //std::cout << "component: " << components[i]->name << "("<< i << ") == " << compType->name << "\n---\n";
            return std::static_pointer_cast<T>(components[i]);
        }
        else
        {
            //std::cout << "component: " << components[i]->name << "("<< i << ") != " << compType->name << "\n";
        }
    }

    //std::cout << "component: " << compType->name << " not found\n---\n";


    componentFlags.set(comp.type);
    components.push_back(std::shared_ptr<Component>(new T()));

    return std::static_pointer_cast<T>(components.back());
}

#endif
