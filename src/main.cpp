#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

const int w_width = 640;
const int w_height = 480;

int main()
{
    sf::Window window(
        sf::VideoMode(w_width, w_height),
        "Pro elite programmer, Marcus 'Elden Lord' Gladh");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}