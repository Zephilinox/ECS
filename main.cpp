//STD
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

#include "ResourceManager.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Systems/RenderSystem.hpp"
#include "Systems/CameraSystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Systems/ControlSystem.hpp"
#include "Systems/CollisionSystem.hpp"

#include "Components/Component.hpp"
#include "Components/Health.hpp"
#include "Components/Movement.hpp"
#include "Components/Display.hpp"
#include "Components/Flags.hpp"

#include "Factories/PlayerFactory.hpp"

EntityManager EntMan;
ResourceManager ResMan;

RenderSystem RenderSys;
CameraSystem CameraSys;
MovementSystem MoveSys;
ControlSystem ControlSys;
CollisionSystem ColSys;

PlayerFactory PlayerFact;

int main()
{
    std::srand(std::time(0));

    sf::RenderWindow window(sf::VideoMode(constant::windowWidth, constant::windowHeight), "Entity Component System");
    window.setFramerateLimit(60);

    RenderSys.debug = true;

    PlayerFact.createPlayer(sf::Vector2f(constant::windowWidth / 2 - 24, constant::windowHeight / 2 - 48));

    CameraSys.followEntity(PlayerFact.playerID);

    // Records amount of time it took to process one game loop(frame)
    sf::Clock prevFrameTime;

    // Used to calculate the amount of time it took for each function in main to complete
    sf::Clock funcCompTime;

    // Stores the amount of seconds it took to process the previous game loop
    double dt = 0;

    while (window.isOpen())
    {
        //accurate seconds
        dt = prevFrameTime.restart().asMicroseconds() / 1000000.f;

        funcCompTime.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::cout << "Event Time: " << funcCompTime.restart().asMilliseconds() << "\n";

        ControlSys.run(dt);
        std::cout << "ControlSys Time: " << funcCompTime.restart().asMilliseconds() << "\n";

        MoveSys.run(dt);
        std::cout << "MoveSys Time: " << funcCompTime.restart().asMilliseconds() << "\n";

        ColSys.run(dt);
        std::cout << "ColSys Time: " << funcCompTime.restart().asMilliseconds() << "\n";

        window.clear(sf::Color(40, 40, 40));

        CameraSys.run(window);
        std::cout << "CameraSys Time: " << funcCompTime.restart().asMilliseconds() << "\n";

        RenderSys.run(window);
        std::cout << "RenderSys Time: " << funcCompTime.restart().asMilliseconds() << "\n";

        window.display();

        std::cout << std::floor(1.f / dt) << " FPS\n\n";
    }

    return 0;
}
