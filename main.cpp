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

#include "Component.hpp"
#include "HealthComponent.hpp"
#include "VelocityComponent.hpp"
#include "SpriteComponent.hpp"

EntityManager EntMan;
RenderSystem RenderSys;
CameraSystem CameraSys;

int main()
{
    sf::RenderWindow window(sf::VideoMode(constant::windowWidth, constant::windowHeight), "Template");

    std::shared_ptr<Entity> Ent1 = EntMan.createEntity();

    /*std::cout << Ent1->componentFlags.to_string() << "\n";
    std::cout << Ent1->component<Component>()->type << "\n\n";
    std::cout << Ent1->componentFlags.to_string() << "\n";
    std::cout << Ent1->component<HealthComponent>()->type << "\n\n";
    std::cout << Ent1->componentFlags.to_string() << "\n";
    std::cout << Ent1->component<VelocityComponent>()->type << "\n\n";
    std::cout << Ent1->componentFlags.to_string() << "\n";
    std::cout << Ent1->component<SpriteComponent>()->type << "\n\n";
    std::cout << Ent1->componentFlags.to_string() << "\n\n";
    */

    {
        std::shared_ptr<SpriteComponent> Ent1Sprite = Ent1->component<SpriteComponent>();
        Ent1Sprite->setTexture("Textures/Asteroid.png");
        Ent1Sprite->sprite.setOrigin(Ent1Sprite->sprite.getTexture()->getSize().x / 2, Ent1Sprite->sprite.getTexture()->getSize().y / 2);
        Ent1Sprite->sprite.setPosition(constant::windowWidth / 2, constant::windowHeight / 2);
    }


    //Ent1->component<HealthComponent>()->health = 10;
    //Ent1->component<SpriteComponent>();

    //std::vector<std::shared_ptr<Entity>> ents = EntMan.getEntsByComponents<HealthComponent, SpriteComponent>();

    //std::cout << "ents with hp and vel: " << ents.size() << "\n";

    std::shared_ptr<Entity> Ent2 = EntMan.createEntity();

    {
        std::shared_ptr<SpriteComponent> Ent2Sprite = Ent2->component<SpriteComponent>();
        //Ent2Sprite->setTexture("Textures/Asteroid.png");
        Ent2Sprite->sprite.setOrigin(Ent2Sprite->sprite.getTexture()->getSize().x / 2, Ent2Sprite->sprite.getTexture()->getSize().y / 2);
        Ent2Sprite->sprite.setPosition(constant::windowWidth / 4, constant::windowHeight / 4);
    }


    CameraSys.followEntity(Ent1->id);

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

        Ent1->component<SpriteComponent>()->sprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        std::cout << Ent1->component<SpriteComponent>()->sprite.getPosition().x << "(" << sf::Mouse::getPosition(window).x << ") " << Ent1->component<SpriteComponent>()->sprite.getPosition().y << "(" << sf::Mouse::getPosition(window).y << ")\n";
        RenderSys.run(window);

        //std::cout << Ent1->component<HealthComponent>()->health << "\n";

        window.display();
    }


    return 0;
}
