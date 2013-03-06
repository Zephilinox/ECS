#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

//STD
#include <map>
#include <string>
#include <memory>
#include <iostream>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

typedef std::map<std::string, sf::Texture*> texMap;
typedef std::map<std::string, sf::Font*> fontMap;

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    sf::Texture* texture(std::string);
    sf::Font* font(std::string);
private:
    static texMap m_Textures;
    static fontMap m_Fonts;
};

#endif
