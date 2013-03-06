#include "Components/Display.hpp"

Display::Display()
{
    type = constant::Comp::Display;

}

Display::Display(std::string path)
{
    type = constant::Comp::Display;

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
