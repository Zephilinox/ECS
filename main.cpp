//STD
#include <iostream>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Systems/RenderSystem.hpp"
#include "Systems/CameraSystem.hpp"
#include "Systems/PlayerControlSystem.hpp"
#include "Systems/MovementSystem.hpp"

#include "Components/Component.hpp"
#include "Components/Health.hpp"
#include "Components/Movement.hpp"
#include "Components/Display.hpp"

EntityManager EntMan;
RenderSystem RenderSys;
CameraSystem CameraSys;
PlayerControlSystem PlyCntrlSys;
MovementSystem EntMoveSys;

sf::Clock PrevFrameTime;
double dt;

int main()
{
    sf::RenderWindow window(sf::VideoMode(constant::windowWidth, constant::windowHeight), "Entity Component System");
    window.setVerticalSyncEnabled(true);

    std::shared_ptr<Entity> Ent1 = EntMan.createEntity();

    {
        std::shared_ptr<Display> Ent1Display = Ent1->component<Display>();
        //Ent1Display->setTexture("Textures/Asteroid.png");
        Ent1Display->sprite.setOrigin(Ent1Display->sprite.getTexture()->getSize().x / 2, Ent1Display->sprite.getTexture()->getSize().y / 2);
        Ent1Display->sprite.setPosition(constant::windowWidth / 2, constant::windowHeight / 2);
    }

    Ent1->component<Movement>();

    std::shared_ptr<Entity> Ent2 = EntMan.createEntity();

    {
        std::shared_ptr<Display> Ent2Display = Ent2->component<Display>();
        Ent2Display->setTexture("Textures/Asteroid.png");
        Ent2Display->sprite.setOrigin(Ent2Display->sprite.getTexture()->getSize().x / 2, Ent2Display->sprite.getTexture()->getSize().y / 2);
        Ent2Display->sprite.setPosition(constant::windowWidth / 4, constant::windowHeight / 4);
    }

    CameraSys.followEntity(Ent1->id);
    PlyCntrlSys.controlEntity(Ent1->id);
    RenderSys.debug = true;

    while (window.isOpen())
    {
        dt = PrevFrameTime.getElapsedTime().asSeconds();
        PrevFrameTime.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(40, 40, 40));

        CameraSys.run(window);
        PlyCntrlSys.run(dt);
        EntMoveSys.run(dt);

        RenderSys.run(window);



        window.display();
    }


    return 0;
}
