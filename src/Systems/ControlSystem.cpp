#include "Systems/ControlSystem.hpp"

std::vector<std::shared_ptr<Entity>> ControlSystem::m_Ents;
EntityManager ControlSystem::m_EntMan;

ControlSystem::ControlSystem()
{
}

void ControlSystem::run(double argDT)
{
    m_Ents = m_EntMan.getEntsByComps<Display, Movement>();

    for (size_t i = 0; i < m_Ents.size(); ++i)
    {
        Display* disp = m_Ents[i]->comp<Display>().get();
        Movement* mov = m_Ents[i]->comp<Movement>().get();

        double rad = zge::degToRad(disp->sprite.getRotation());

        double sinRad = std::sin(rad);
        double cosRad = std::cos(rad);

        if (m_Ents[i]->hasComp<Flags>() && m_Ents[i]->comp<Flags>()->flags.test(constant::Flag::Player))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                mov->velocity.x += sinRad * mov->acceleration * argDT;
                mov->velocity.y += -1 * cosRad * mov->acceleration * argDT;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                mov->velocity.x += -1 * sinRad * mov->acceleration * argDT;
                mov->velocity.y += cosRad * mov->acceleration * argDT;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                disp->sprite.rotate(-mov->acceleration * argDT);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                disp->sprite.rotate(mov->acceleration * argDT);
            }
        }
    }
}
