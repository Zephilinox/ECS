#include "RenderSystem.hpp"

RenderSystem::RenderSystem()
{
}

void RenderSystem::run(sf::RenderWindow& window)
{
    m_Ents = m_EntMan.getEntsByComponent<SpriteComponent>();

    for (size_t i = 0; i < m_Ents.size(); ++i)
    {
        window.draw(m_Ents.at(i)->component<SpriteComponent>()->sprite);
    }
}
