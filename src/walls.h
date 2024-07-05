#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "grid.h"


#ifndef WALLS_H
#define WALLS_H

class Walls {
    private:
        sf::RectangleShape wall_element_;

    public:
        Walls(Grid &grid)
        {
            const uint8_t element_width = grid.get_pixel_width_of_single_element();
            wall_element_ = sf::RectangleShape(sf::Vector2f(element_width, element_width));
            wall_element_.setFillColor(sf::Color::Blue);
        }

        void draw(sf::RenderWindow &window, Grid &grid);
};

#endif // WALLS_H