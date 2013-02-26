#include "Components/Display.hpp"

Display::Display()
{
    type = constant::Component::Display;

    if (m_Texture.loadFromFile("Textures/Blank.png"))
    {
        sprite.setTexture(m_Texture);
    }
}

Display::Display(std::string path)
{
    type = constant::Component::Display;

    if (m_Texture.loadFromFile(path))
    {
        sprite.setTexture(m_Texture);
    }
}

void Display::setTexture(std::string path)
{
    if (m_Texture.loadFromFile(path))
    {
        sprite.setTexture(m_Texture);
    }
}
