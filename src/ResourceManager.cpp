#include "ResourceManager.hpp"

texMap ResourceManager::m_Textures;
fontMap ResourceManager::m_Fonts;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
    for (texMap::iterator i = m_Textures.begin(); i != m_Textures.end(); ++i)
    {
        delete i->second;
    }
}

sf::Texture* ResourceManager::texture(std::string filename)
{
    if (m_Textures.find(filename) != m_Textures.end())
    {
        //std::cout << "found " << filename << "\n";
        return m_Textures.find(filename)->second;
    }
    else
    {
        std::cout << "added " << filename << "\n";
        sf::Texture* t = new sf::Texture;

        if (!t->loadFromFile(("Textures/" + filename + ".png")))
        {
            filename = "Error";
            if (!t->loadFromFile("Textures/Error.png"))
            {
                std::cout << "Major Error: Could not find backup texture.";
            }
        }

        m_Textures.insert(std::pair<std::string, sf::Texture*>(filename, t));
        return m_Textures.find(filename)->second;
    }
}

sf::Font* ResourceManager::font(std::string filename)
{
    if (m_Fonts.find(filename) != m_Fonts.end())
    {
        //std::cout << "found " << filename << "\n";
        return m_Fonts.find(filename)->second;
    }
    else
    {
        std::cout << "added " << filename << "\n";
        sf::Font* f = new sf::Font;

        if (!f->loadFromFile(("Fonts/" + filename + ".ttf")))
        {
            filename = "arial";
            if (!f->loadFromFile("Fonts/arial.ttf"))
            {
                std::cout << "Major Error: Could not find backup font.";
                filename = "Error";
            }
        }

        m_Fonts.insert(std::pair<std::string, sf::Font*>(filename, f));
        return m_Fonts.find(filename)->second;
    }
}
