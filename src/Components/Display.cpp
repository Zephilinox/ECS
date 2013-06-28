#include "Components/Display.hpp"

Display::Display():
sprite(),
m_Texture()
{
    type = constant::Comp::Display;

}

Display::Display(std::string path):
sprite(),
m_Texture()
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
