#include "RenderSystem.hpp"

std::vector<std::shared_ptr<Entity>> RenderSystem::m_Ents;
EntityManager RenderSystem::m_EntMan;

RenderSystem::RenderSystem()
{
}

void RenderSystem::run(sf::RenderWindow& window)
{
    m_Ents = m_EntMan.getEntsByComponent<SpriteComponent>();

    for (size_t i = 0; i < m_Ents.size(); ++i)
    {
        window.draw(m_Ents[i]->component<SpriteComponent>()->sprite);
    }
}
