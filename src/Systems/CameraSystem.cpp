#include "Systems/CameraSystem.hpp"

std::shared_ptr<Entity> CameraSystem::m_Ent;
EntityManager CameraSystem::m_EntMan;

CameraSystem::CameraSystem()
{
}

void CameraSystem::run(sf::RenderWindow& window)
{
    if (!m_Ent->hasComponent<Sprite>())
    {
        m_Ent = nullptr;
    }

    if (m_Ent != nullptr)
    {
        m_Camera.setCenter(m_Ent->component<Sprite>()->sprite.getPosition());
        m_Camera.setSize(constant::windowWidth, constant::windowHeight);
        window.setView(m_Camera);

    }

}

void CameraSystem::followEntity(unsigned int argID)
{
    m_Ent = m_EntMan.getEntByID(argID);

    if (!m_Ent->hasComponent<Sprite>())
    {
        m_Ent = nullptr;
    }
}
