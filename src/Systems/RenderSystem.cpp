#include "Systems/RenderSystem.hpp"

std::vector<std::shared_ptr<Entity>> RenderSystem::m_Ents;
EntityManager RenderSystem::m_EntMan;
bool RenderSystem::debug;

RenderSystem::RenderSystem()
{
    debug = false;
}

void RenderSystem::run(sf::RenderWindow& window)
{
    m_Ents = m_EntMan.getEntsByComponent<Sprite>();

    if (debug)
    {
        sf::VertexArray VA(sf::PrimitiveType::Lines, 2);
        VA[0].color = sf::Color(0, 255, 0);
        VA[1].color = sf::Color(0, 255, 0);

        for (size_t i = 0; i < m_Ents.size(); ++i)
        {
            if (m_Ents[i]->hasComponent<Velocity>())
            {
                VA[0].position = m_Ents[i]->component<Sprite>()->sprite.getPosition();
                VA[1].position = sf::Vector2f(m_Ents[i]->component<Sprite>()->sprite.getPosition().x + (m_Ents[i]->component<Velocity>()->velocity.x),
                                              m_Ents[i]->component<Sprite>()->sprite.getPosition().y + (m_Ents[i]->component<Velocity>()->velocity.y));

                window.draw(VA);
            }

            window.draw(m_Ents[i]->component<Sprite>()->sprite);
        }
    }
    else
    {
        for (size_t i = 0; i < m_Ents.size(); ++i)
        {
            window.draw(m_Ents[i]->component<Sprite>()->sprite);
        }
    }
}
