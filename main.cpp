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

int main()
{
    sf::RenderWindow window(sf::VideoMode(constant::windowWidth, constant::windowHeight), "Entity Component System");
    window.setFramerateLimit(120);

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

    // Records amount of time it took to process one game loop
    sf::Clock prevFrameTime;

    // Accumulates dt
    double accDT = 0;

    // Stores the amount of seconds it took to process the previous game loop
    double dt = 0;

    // Number of updates per second
    double timeStep = 1.f / 100.f;

    // updates per second / frameSkip = logic limit for FPS, if FPS goes below the result then logic slows down, not just drawing
    int frameSkip = 20;

    // Number of logic updates per frame
    int loops = 0;

    // Determines if we should re-draw or not
    bool updated = true;

    while (window.isOpen())
    {
        dt = prevFrameTime.restart().asMicroseconds() / 1000000.f; //accurate seconds
        //std::cout << "FPS: " << 1.f / dt << "\n";
        accDT += dt;
        //std::cout << "accTime: " << accDT << "\n";

        // This basically processes our accumulated dt, consuming it and running a logic update
        while (accDT >= timeStep && loops <= frameSkip)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            PlyCntrlSys.run(timeStep);
            EntMoveSys.run(timeStep);

            accDT -= timeStep;
            updated = true;
            loops++;
        }
        //std::cout << "Updates: " << loops << "\n";

        // ensures we don't keep rendering the same frame, wasting time.
        if (updated)
        {
            window.clear(sf::Color(40, 40, 40));

            CameraSys.run(window);
            RenderSys.run(window);

            window.display();

            updated = false;
        }

        loops = 0;
    }

    return 0;
}
