#ifndef PLAYERCONTROLSYSTEM_HPP
#define PLAYERCONTROLSYSTEM_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Components/Movement.hpp"
#include "Components/Display.hpp"
#include "Vector.hpp"

class PlayerControlSystem
{
public:
    PlayerControlSystem();
    void run(double);
    void controlEntity(unsigned int);

private:
    static std::shared_ptr<Entity> m_Ent;
    static EntityManager m_EntMan;

};

#endif
