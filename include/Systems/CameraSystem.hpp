#ifndef CAMERASYSTEM_HPP
#define CAMERASYSTEM_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Components/Display.hpp"

class CameraSystem
{
public:
    CameraSystem();
    void run(sf::RenderWindow&);
    void followEntity(unsigned int);

private:
    sf::View m_Camera;
    static std::shared_ptr<Entity> m_Ent;

    static EntityManager m_EntMan;
};

#endif
