#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

//STD
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <cmath>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Components/Component.hpp"
#include "Components/Display.hpp"
#include "Components/Movement.hpp"
#include "Components/Flags.hpp"

class RenderSystem
{
public:
    RenderSystem();
    void run(sf::RenderWindow&);
    static bool debug;

private:
    static std::vector<std::shared_ptr<Entity>> m_Ents;
    static EntityManager m_EntMan;
    static ResourceManager m_ResMan;

};

#endif
