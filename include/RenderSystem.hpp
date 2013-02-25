#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

//STD
#include <iostream>
#include <vector>
#include <memory>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "SpriteComponent.hpp"

class RenderSystem
{
public:
    RenderSystem();
    void run(sf::RenderWindow&);

private:
    std::vector<std::shared_ptr<Entity>> m_Ents;
    EntityManager m_EntMan;
};

#endif
