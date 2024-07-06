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
        std::array<std::vector<uint8_t>, 2> coordinates_;
        std::vector<uint8_t>* x_coordinates_;
        std::vector<uint8_t>* y_coordinates_;

    public:
        Walls(Grid &grid)
        {
            const uint8_t element_width = grid.get_pixel_width_of_single_element();
            wall_element_ = sf::RectangleShape(sf::Vector2f(element_width, element_width));
            wall_element_.setFillColor(sf::Color::Blue);
            x_coordinates_ = &coordinates_[0];
            y_coordinates_ = &coordinates_[1];
            init(grid.get_max_element_index());
        }
        void init(uint8_t max_x);
        void draw(sf::RenderWindow &window, Grid &grid);
        std::array<std::vector<uint8_t>, 2> get_coordinates() const;
        uint8_t length() const;
};

#endif // WALLS_H