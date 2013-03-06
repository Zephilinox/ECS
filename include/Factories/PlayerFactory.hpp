#ifndef PLAYERFACTORY_HPP
#define PLAYERFACTORY_HPP

//STD
#include <memory>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

#include "ResourceManager.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Components/Movement.hpp"
#include "Components/Display.hpp"
#include "Components/Flags.hpp"

class PlayerFactory
{
public:
    PlayerFactory();

    void createPlayer(sf::Vector2f);
    void deletePlayer();
    static unsigned int playerID;

private:
    static EntityManager m_EntMan;
    static ResourceManager m_ResMan;
};

#endif
