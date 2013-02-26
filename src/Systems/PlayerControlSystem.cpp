#include "Systems/PlayerControlSystem.hpp"

std::shared_ptr<Entity> PlayerControlSystem::m_Ent;
EntityManager PlayerControlSystem::m_EntMan;

PlayerControlSystem::PlayerControlSystem()
{
    //std::cout << "PCS Created\n";
}

void PlayerControlSystem::run(float argDT)
{
    //std::cout << "ControlEntity Run\n";

    if (m_Ent->hasComponent<Sprite, Velocity>())
    {
        //std::cout << "doing stuff\n";

        double entRadian = zge::degToRad(m_Ent->component<Sprite>()->sprite.getRotation());
        double sinRadian = std::sin(entRadian);
        double cosRadian = std::cos(entRadian);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            m_Ent->component<Velocity>()->velocity.x += 300 * sinRadian * argDT;
            m_Ent->component<Velocity>()->velocity.y += -1 * 300 * cosRadian * argDT;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            m_Ent->component<Sprite>()->sprite.rotate(-300 * argDT);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            m_Ent->component<Velocity>()->velocity.x += -1 * 300 * sinRadian * argDT;
            m_Ent->component<Velocity>()->velocity.y += 300 * cosRadian * argDT;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            m_Ent->component<Sprite>()->sprite.rotate(300 * argDT);
        }
    }
    else
    {
        //std::cout << "ent does not have comps\n";
        std::cout << m_Ent->componentFlags.to_string() << "\n";
    }

}

void PlayerControlSystem::controlEntity(unsigned int argID)
{
    m_Ent = m_EntMan.getEntByID(argID);
}
