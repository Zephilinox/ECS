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
#include "Components/Velocity.hpp"
#include "Components/Sprite.hpp"

EntityManager EntMan;
RenderSystem RenderSys;
CameraSystem CameraSys;
PlayerControlSystem PlyCntrlSys;
MovementSystem EntMoveSys;

int main()
{
    sf::RenderWindow window(sf::VideoMode(constant::windowWidth, constant::windowHeight), "Entity Component System");
    window.setVerticalSyncEnabled(true);

    std::shared_ptr<Entity> Ent1 = EntMan.createEntity();

    {
        std::shared_ptr<Sprite> Ent1Sprite = Ent1->component<Sprite>();
        //Ent1Sprite->setTexture("Textures/Asteroid.png");
        Ent1Sprite->sprite.setOrigin(Ent1Sprite->sprite.getTexture()->getSize().x / 2, Ent1Sprite->sprite.getTexture()->getSize().y / 2);
        Ent1Sprite->sprite.setPosition(constant::windowWidth / 2, constant::windowHeight / 2);
    }

    Ent1->component<Velocity>();

    std::shared_ptr<Entity> Ent2 = EntMan.createEntity();

    {
        std::shared_ptr<Sprite> Ent2Sprite = Ent2->component<Sprite>();
        Ent2Sprite->setTexture("Textures/Asteroid.png");
        Ent2Sprite->sprite.setOrigin(Ent2Sprite->sprite.getTexture()->getSize().x / 2, Ent2Sprite->sprite.getTexture()->getSize().y / 2);
        Ent2Sprite->sprite.setPosition(constant::windowWidth / 4, constant::windowHeight / 4);
    }


    CameraSys.followEntity(Ent1->id);
    PlyCntrlSys.controlEntity(Ent1->id);
    RenderSys.debug = true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(40, 40, 40));

        CameraSys.run(window);
        PlyCntrlSys.run(1.f / 60.f);
        EntMoveSys.run(1.f / 60.f);

        RenderSys.run(window);



        window.display();
    }


    return 0;
}
