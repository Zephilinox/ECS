#include "Systems/CameraSystem.hpp"

std::shared_ptr<Entity> CameraSystem::m_Ent;

EntityManager CameraSystem::m_EntMan;

CameraSystem::CameraSystem()
{
    m_Ent = nullptr;
}

void CameraSystem::run(sf::RenderWindow& window)
{
    if (m_Ent != nullptr)
    {
        if (!m_Ent->hasComp<Display>())
        {
            m_Ent = nullptr;
        }
        else
        {
            m_Camera.setCenter(m_Ent->comp<Display>()->sprite.getPosition());
            m_Camera.setSize(constant::windowWidth, constant::windowHeight);
            m_Camera.zoom(1);

            window.setView(m_Camera);
        }
    }
    else
    {
        std::cout << "t.t\n";
    }
}

void CameraSystem::followEntity(unsigned int argID)
{
    m_Ent = m_EntMan.getEntByID(argID);

    if (!m_Ent->hasComp<Display>())
    {
        m_Ent = nullptr;
    }
}
