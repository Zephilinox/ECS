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
#include "Components/Component.hpp"
#include "Components/Sprite.hpp"
#include "Components/Velocity.hpp"

class RenderSystem
{
public:
    RenderSystem();
    void run(sf::RenderWindow&);
    static bool debug;

private:
    static std::vector<std::shared_ptr<Entity>> m_Ents;
    static EntityManager m_EntMan;

};

#endif
