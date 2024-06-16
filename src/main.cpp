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

    uint8_t grid_x = start_position;
    uint8_t grid_y = start_position;
    uint16_t pixel_x = 0;
    uint16_t pixel_y = 0;

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
    std::vector<uint8_t> snake_x_vector = snake.get_x_vector();
    std::vector<uint8_t> snake_y_vector = snake.get_y_vector();

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

        snake.move();
        snake_x_vector = snake.get_x_vector();
        snake_y_vector = snake.get_y_vector();

        window.clear(sf::Color(155,186,90,255));

        //draw everything here...
        for (uint8_t i = 0; i < snake.length(); i++)
        {
            pixel_x = grid.get_pixel_x_from_coordinate_x(snake_x_vector[i]);
            pixel_y = grid.get_pixel_y_from_coordinate_y(snake_y_vector[i]);
            // std::cout << static_cast<int>(snake_x_vector[i]) << std::endl;
            snake_element.setPosition(pixel_x, pixel_y);
            window.draw(snake_element);
        }
        window.display();
    }

    return 0;
}