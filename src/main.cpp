#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

const int w_width = 640;
const int w_height = 640;

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(w_width, w_height),
        "Pro elite programmer, Marcus 'Elden Lord' Gladh");

    window.setFramerateLimit(5);

    sf::CircleShape circle(200);
    circle.setPosition(300, 200);
    circle.setFillColor(sf::Color::Black);

    sf::RectangleShape head(sf::Vector2f(20, 20));
    bool toggleShape = false;

    int x = 0;
    int y = 0;

    while (window.isOpen())
    {
        x += 5;
        y += 5;

        head.setPosition(x, y);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        toggleShape = !toggleShape;

        window.clear(sf::Color(155,186,90,255));

        //draw everything here...
        if (toggleShape)
        {
            window.draw(circle);
        }else{
            window.draw(head);
        }

        window.display();
    }

    return 0;
}