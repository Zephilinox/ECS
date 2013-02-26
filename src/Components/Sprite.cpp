#include "Components/Sprite.hpp"

Sprite::Sprite()
{
    type = constant::Component::Sprite;

    if (m_Texture.loadFromFile("Textures/Blank.png"))
    {
        sprite.setTexture(m_Texture);
    }
}

Sprite::Sprite(std::string path)
{
    type = constant::Component::Sprite;

    if (m_Texture.loadFromFile(path))
    {
        sprite.setTexture(m_Texture);
    }
}

void Sprite::setTexture(std::string path)
{
    if (m_Texture.loadFromFile(path))
    {
        sprite.setTexture(m_Texture);
    }
}
