#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"

#ifndef SNAKE_H
#define SNAKE_H

enum eDirection {
    up = 0,
 right = 1,
  down = 2,
  left = 3
};

class Snake {
    private:
        std::array<std::vector<uint8_t>, 2> coordinates_;
        std::vector<uint8_t>* x_positions_;
        std::vector<uint8_t>* y_positions_;
        bool is_digesting_ = false;
        eDirection direction_ = up;

    public:
        Snake(uint8_t start_position)
        {
            x_positions_ = &coordinates_[0];
            y_positions_ = &coordinates_[1];
            x_positions_->push_back(start_position);
            y_positions_->push_back(start_position);
        }

        std::array<std::vector<uint8_t>, 2> get_coordinates() const;
        uint8_t length() const;
        eDirection direction() const;
        void eat();
        void digest();
        void move();
        void turn(eDirection new_direction);
        void draw(sf::RenderWindow &window, Grid &grid);
};

#endif // SNAKE_H