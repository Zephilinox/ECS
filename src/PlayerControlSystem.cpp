#include "PlayerControlSystem.hpp"

std::shared_ptr<Entity> PlayerControlSystem::m_Ent;
EntityManager PlayerControlSystem::m_EntMan;

PlayerControlSystem::PlayerControlSystem()
{
}

void PlayerControlSystem::run(float argDT)
{
    std::cout << "ControlEntity Run\n";

    if (m_Ent != nullptr)
    {
        if (m_Ent->hasComponent<SpriteComponent, VelocityComponent>() == false)
        {
            m_Ent = nullptr;
            break;
        }
    
        double entRadian = zge::degToRad(m_Ent->component<SpriteComponent>()->sprite.getRotation());
        double sinRadian = std::sin(entRadian);
        double cosRadian = std::cos(entRadian);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            m_Ent->component<VelocityComponent>()->velocity.x += 300 * sinRadian * argDT;
            m_Ent->component<VelocityComponent>()->velocity.y += -1 * 300 * cosRadian * argDT;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            m_Ent->component<SpriteComponent>()->sprite.rotate(-300 * argDT);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            m_Ent->component<VelocityComponent>()->velocity.x += -1 * 300 * sinRadian * argDT;
            m_Ent->component<VelocityComponent>()->velocity.y += 300 * cosRadian * argDT;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            m_Ent->component<SpriteComponent>()->sprite.rotate(300 * argDT);
        }
    }
}

void PlayerControlSystem::controlEntity(unsigned int argID)
{
    m_Ent = m_EntMan.getEntByID(argID);

    std::cout << "ControlEntity\n";

    if (!m_Ent->hasComponent<VelocityComponent, SpriteComponent>())
    {
        m_Ent = nullptr;
    }
}
