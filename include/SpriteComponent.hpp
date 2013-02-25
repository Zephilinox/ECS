#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

//STD
#include <string>

//3RD

#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"
#include "Component.hpp"

class SpriteComponent : public Component
{
public:
    SpriteComponent();
    SpriteComponent(std::string);

    void setTexture(std::string);

    sf::Sprite sprite;
private:
    sf::Texture m_Texture;
};

#endif
