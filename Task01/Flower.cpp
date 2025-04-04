#include "Flower.h"

Flower::Flower(sf::RenderWindow *w) : window(w)
{
    // outer petal
    outerPetal.setRadius(50.f);
    outerPetal.setFillColor(sf::Color::Red);
    outerPetal.setOrigin({ 50.f, 50.f });

    // inner center
    center.setRadius(30.f);
    center.setFillColor(sf::Color::Yellow);
    center.setOrigin({ 30.f, 30.f });

    // stem
    stem.setSize(sf::Vector2f(10.f, 100.f));
    stem.setFillColor(sf::Color::Green);
    stem.setOrigin({ 5.f, 5.f });

    // leaf
    leaf.setPointCount(3);
    leaf.setPoint(0, sf::Vector2f(0.f, 0.f));
    leaf.setPoint(1, sf::Vector2f(50.f, -20.f));
    leaf.setPoint(2, sf::Vector2f(70.f, 10.f));
    leaf.setFillColor(sf::Color::Green);

    // sun
    sun.setRadius(sunSize);
    sun.setFillColor(sf::Color::Yellow);
    sun.setOrigin({ sunSize, sunSize });
    sun.setPosition({ 30.f, 30.f });
}

void Flower::updateAnimation()
{
    sf::Time t = frameClock.getElapsedTime();
    if (t.asMilliseconds() > 100)
    {
        if (shrink)
        {
            sunSize -= 1.f;
            if (sunSize <= 15.f)
            {
                shrink = false;
            }
        }
        else
        {
            sunSize += 1.f;
            if (sunSize >= 20.f)
            {
                shrink = true;
            }
        }
        sun.setRadius(sunSize);
        sun.setOrigin({ sunSize, sunSize });
        
        frameClock.restart();
    }
}

void Flower::mydraw(sf::Vector2f pos)
{
    if (!window) return;

    updateAnimation();

    window->draw(sun);

    stem.setPosition({ pos.x, pos.y + 50.f });
    window->draw(stem);

    leaf.setPosition({ pos.x + 5.f, pos.y + 80.f });
    window->draw(leaf);

    outerPetal.setPosition(pos);
    window->draw(outerPetal);

    center.setPosition(pos);
    window->draw(center);
}
