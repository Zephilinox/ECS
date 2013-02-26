#ifndef Sprite_HPP
#define Sprite_HPP

//STD
#include <string>

//3RD

#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"
#include "Components/Component.hpp"

class Sprite : public Component
{
public:
    Sprite();
    Sprite(std::string);

    void setTexture(std::string);

    sf::Sprite sprite;
private:
    sf::Texture m_Texture;
};

#endif
