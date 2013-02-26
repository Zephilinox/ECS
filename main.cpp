//STD
#include <iostream>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "RenderSystem.hpp"
#include "CameraSystem.hpp"
#include "PlayerControlSystem.hpp"
#include "EntityMovementSystem.hpp"

#include "Component.hpp"
#include "HealthComponent.hpp"
#include "VelocityComponent.hpp"
#include "SpriteComponent.hpp"

EntityManager EntMan;
RenderSystem RenderSys;
CameraSystem CameraSys;
PlayerControlSystem PlyCntrlSys;
EntityMovementSystem EntMoveSys;

int main()
{
    sf::RenderWindow window(sf::VideoMode(constant::windowWidth, constant::windowHeight), "Template");
    window.setVerticalSyncEnabled(true);

    std::shared_ptr<Entity> Ent1 = EntMan.createEntity();

    {
        std::shared_ptr<SpriteComponent> Ent1Sprite = Ent1->component<SpriteComponent>();
        Ent1Sprite->setTexture("Textures/Asteroid.png");
        Ent1Sprite->sprite.setOrigin(Ent1Sprite->sprite.getTexture()->getSize().x / 2, Ent1Sprite->sprite.getTexture()->getSize().y / 2);
        Ent1Sprite->sprite.setPosition(constant::windowWidth / 2, constant::windowHeight / 2);
    }

    std::shared_ptr<Entity> Ent2 = EntMan.createEntity();

    {
        std::shared_ptr<SpriteComponent> Ent2Sprite = Ent2->component<SpriteComponent>();
        //Ent2Sprite->setTexture("Textures/Asteroid.png");
        Ent2Sprite->sprite.setOrigin(Ent2Sprite->sprite.getTexture()->getSize().x / 2, Ent2Sprite->sprite.getTexture()->getSize().y / 2);
        Ent2Sprite->sprite.setPosition(constant::windowWidth / 4, constant::windowHeight / 4);
    }


    CameraSys.followEntity(Ent1->id);
    PlyCntrlSys.controlEntity(Ent1->id);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Ent1->component<HealthComponent>()->health++;

        window.clear(sf::Color(100, 255, 100));

        CameraSys.run(window);
        PlyCntrlSys.run(1.f / 60.f);
        EntMoveSys.run(1.f / 60.f);

        //Ent1->component<SpriteComponent>()->sprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        //std::cout << Ent1->component<SpriteComponent>()->sprite.getPosition().x << "(" << sf::Mouse::getPosition(window).x << ") " << Ent1->component<SpriteComponent>()->sprite.getPosition().y << "(" << sf::Mouse::getPosition(window).y << ")\n";
        RenderSys.run(window);

        //std::cout << Ent1->component<HealthComponent>()->health << "\n";

        window.display();
    }


    return 0;
}
