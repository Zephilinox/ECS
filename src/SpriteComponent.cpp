#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
    type = constant::Component::SpriteComponent;

    if (m_Texture.loadFromFile("Textures/Blank.png"))
    {
        sprite.setTexture(m_Texture);
    }
}

SpriteComponent::SpriteComponent(std::string path)
{
    type = constant::Component::SpriteComponent;

    if (m_Texture.loadFromFile(path))
    {
        sprite.setTexture(m_Texture);
    }
}

void SpriteComponent::setTexture(std::string path)
{
    if (m_Texture.loadFromFile(path))
    {
        sprite.setTexture(m_Texture);
    }
}
