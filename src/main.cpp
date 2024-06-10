#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "grid.h"

const uint16_t window_pixel_width = 640;
const uint8_t grid_element_width = 8;
const uint8_t grid_width = window_pixel_width / grid_element_width;
const uint8_t start_position = grid_width / 2;

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(window_pixel_width, window_pixel_width),
        "Pro elite programmer, Marcus 'Elden Lord' Gladh");

    window.setFramerateLimit(10);

    Grid myGrid(grid_width, window_pixel_width);

    sf::RectangleShape head(sf::Vector2f(grid_element_width, grid_element_width));
    uint8_t grid_x = start_position;
    uint8_t grid_y = start_position;
    uint16_t pixel_x = 0;
    uint16_t pixel_y = 0;

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

        grid_x += 1;
        grid_y += 1;
        pixel_x = myGrid.get_pixel_x_from_coordinate_x(grid_x);
        pixel_y = myGrid.get_pixel_y_from_coordinate_y(grid_y);

        head.setPosition(pixel_x, pixel_y);

        window.clear(sf::Color(155,186,90,255));

        //draw everything here...
        window.draw(head);

        window.display();
    }

    return 0;
}