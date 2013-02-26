#ifndef Display_HPP
#define Display_HPP

//STD
#include <string>

//3RD

#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"
#include "Components/Component.hpp"

class Display : public Component
{
public:
    Display();
    Display(std::string);

    void setTexture(std::string);

    sf::Sprite sprite;
private:
    sf::Texture m_Texture;
};

#endif
