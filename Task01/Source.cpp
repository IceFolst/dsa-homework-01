#include <SFML/Graphics.hpp>
#include "Flower.h"

// on ubuntu i have the version SFML 2.5.1 so it deosn't support the syntax for verison 3.x

// main for sfml 3.0
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "SFML works!");
    Flower flower(&window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        flower.mydraw(sf::Vector2f(200.f, 150.f));
        window.display();
    }
}



// main for sfml 2.5.1
/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    Flower flower(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        flower.mydraw(sf::Vector2f(200.f, 150.f)); // draw at center
        window.display();
    }

    return 0;
}
*/
