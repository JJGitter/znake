#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "snake.h"

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

    Grid grid(grid_width, window_pixel_width);
    Snake snake(start_position, start_position);

    uint16_t snake_pixels_x = 0;
    uint16_t snake_pixels_y = 0;

    sf::RectangleShape snake_element(sf::Vector2f(grid_element_width, grid_element_width));

    snake.eat();
    snake.eat();
    snake.eat();
    snake.eat();
    snake.eat();
    snake.eat();
    // snake.eat();
    // snake.eat();
    // snake.eat();
    // snake.eat();
    // snake.eat();
    // snake.eat();
    // snake.eat();
    // snake.eat();
    // snake.eat();
    // snake.eat();

    std::array<std::vector<uint8_t>, 2> snake_coordinates = snake.get_coordinates();

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

        window.clear(sf::Color(155,186,90,255));

        snake.move();
        snake_coordinates = snake.get_coordinates();

        //draw everything here...
        for (uint8_t i = 0; i < snake.length(); i++)
        {
            snake_pixels_x = grid.get_pixel_x_from_coordinate_x(snake_coordinates[0][i]);
            snake_pixels_y = grid.get_pixel_y_from_coordinate_y(snake_coordinates[1][i]);
            snake_element.setPosition(snake_pixels_x, snake_pixels_y);
            window.draw(snake_element);
        }
        window.display();
    }

    return 0;
}