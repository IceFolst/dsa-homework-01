#pragma once

#include <SFML/Graphics.hpp>

class Flower{
private:
    sf::RenderWindow* window;
    sf::CircleShape outerPetal;
    sf::CircleShape center;
    sf::RectangleShape stem;
    sf::ConvexShape leaf;
    sf::CircleShape sun;
    sf::Clock frameClock;
    float sunSize = 20.f;
    bool shrink = true;

public:
    Flower(sf::RenderWindow *window);
    void mydraw(sf::Vector2f pos);
    void updateAnimation();
};
