#include "Factories/PlayerFactory.hpp"

unsigned int PlayerFactory::playerID;
EntityManager PlayerFactory::m_EntMan;
ResourceManager PlayerFactory::m_ResMan;

PlayerFactory::PlayerFactory()
{
}

void PlayerFactory::createPlayer(sf::Vector2f argPos)
{
    if (playerID)
    {
        this->deletePlayer();
    }

    Entity ent(0);

    sf::Texture* t = m_ResMan.texture("Player");

    ent.comp<Display>()->sprite.setTexture(*t);
    ent.comp<Display>()->sprite.setPosition(argPos);
    ent.comp<Display>()->sprite.setOrigin(ent.comp<Display>()->sprite.getTexture()->getSize().x / 2, ent.comp<Display>()->sprite.getTexture()->getSize().y / 2);

    ent.comp<Movement>()->acceleration = 300;

    ent.comp<Flags>()->flags.set(constant::Flag::Collidable);
    ent.comp<Flags>()->flags.set(constant::Flag::Player);

    playerID = m_EntMan.addEnt(ent)->id;
}

void PlayerFactory::deletePlayer()
{
    m_EntMan.deleteEnt(playerID);
    playerID = 0;
}
