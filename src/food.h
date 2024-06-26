#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "grid.h"


#ifndef FOOD_H
#define FOOD_H

class Food {
    private:
        std::array<uint8_t, 2> coordinates_;
        uint8_t* x_position_;
        uint8_t* y_position_;
        sf::CircleShape food_element_;

    public:
        Food()
        {
            x_position_ = &coordinates_[0];
            y_position_ = &coordinates_[1];
        }

        std::array<uint8_t, 2> get_coordinates() const;
        std::array<uint8_t, 2> spawn(uint8_t max_x);
        void draw(sf::RenderWindow &window, Grid &grid);
};

#endif // FOOD_H