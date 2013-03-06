#include "Systems/RenderSystem.hpp"

std::vector<std::shared_ptr<Entity>> RenderSystem::m_Ents;
EntityManager RenderSystem::m_EntMan;
ResourceManager RenderSystem::m_ResMan;

bool RenderSystem::debug;

RenderSystem::RenderSystem()
{
    debug = false;
}

void RenderSystem::run(sf::RenderWindow& window)
{
    m_Ents = m_EntMan.getEntsByComp<Display>();

    if (debug)
    {
        sf::VertexArray VA(sf::PrimitiveType::Lines, 2);

        for (size_t i = 0; i < m_Ents.size(); ++i)
        {
            Display* disp = m_Ents[i]->comp<Display>().get();
            window.draw(disp->sprite);

            if (!m_Ents[i]->hasComp<Flags>() || !(m_Ents[i]->comp<Flags>()->flags.test(constant::Flag::Tile)))
            {
                std::stringstream ss;
                ss << "(" << std::floor(disp->sprite.getPosition().x)  << ", " << std::floor(disp->sprite.getPosition().y) << ")";

                sf::Text info;
                info.setFont(*m_ResMan.font("arial"));
                info.setString(ss.str());
                info.setPosition(disp->sprite.getPosition().x - info.getGlobalBounds().width / 2, disp->sprite.getPosition().y - info.getGlobalBounds().height * 1.5);
                info.setColor(sf::Color(255, 180, 0));

                window.draw(info);
            }

            if (m_Ents[i]->hasComp<Movement>())
            {
                Movement* mov = m_Ents[i]->comp<Movement>().get();

                VA[0].position = disp->sprite.getPosition();
                VA[1].position = sf::Vector2f(disp->sprite.getPosition().x + mov->velocity.x,
                                              disp->sprite.getPosition().y + mov->velocity.y);

                VA[0].color = sf::Color(0, 255, 0);
                VA[1].color = sf::Color(0, 255, 0);

                //Velocity
                window.draw(VA);

                VA[0].position = disp->sprite.getPosition();
                VA[1].position = sf::Vector2f(disp->sprite.getPosition().x + (std::sin(zge::degToRad(disp->sprite.getRotation())) * 50),
                                              disp->sprite.getPosition().y + (std::cos(zge::degToRad(disp->sprite.getRotation())) * -50));

                VA[0].color = sf::Color(0, 100, 255);
                VA[1].color = sf::Color(0, 100, 255);

                //Rotation
                window.draw(VA);

                std::stringstream ss;
                ss << std::floor(mov->velocity.length()) << " (" << std::floor(mov->velocity.degrees()) + 180 << char(186) << ")";

                sf::Text info;
                info.setFont(*m_ResMan.font("arial"));
                info.setString(ss.str());
                info.setPosition(disp->sprite.getPosition().x + disp->sprite.getTexture()->getSize().x, disp->sprite.getPosition().y + disp->sprite.getTexture()->getSize().y);
                info.setColor(sf::Color(0, 255, 0));

                //Velocity
                window.draw(info);

                ss.str("");
                ss << std::floor(disp->sprite.getRotation()) << char(186);

                info.setString(ss.str());
                info.setPosition(disp->sprite.getPosition().x - info.getLocalBounds().width, disp->sprite.getPosition().y + info.getLocalBounds().height);
                info.setColor(sf::Color(0, 100, 255));

                //Rotation
                window.draw(info);
            }
        }
    }
    else
    {
        for (size_t i = 0; i < m_Ents.size(); ++i)
        {
            window.draw(m_Ents[i]->comp<Display>()->sprite);
        }
    }
}
