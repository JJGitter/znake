#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "food.h"

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
        eDirection direction_ = up;
        sf::RectangleShape snake_element_;
        bool is_digesting_ = false;
        std::array<uint8_t, 2> position_of_food_being_digested_;

    public:
        Snake(Grid &grid)
        {
            const uint8_t start_position = grid.get_width_in_nr_of_elements() / 2;
            const uint8_t starting_length = 5;
            const uint8_t element_width = grid.get_pixel_width_of_single_element();
            x_positions_ = &coordinates_[0];
            y_positions_ = &coordinates_[1];
            for (uint8_t i = 0; i < starting_length; i++)
            {
                x_positions_->push_back(start_position + i);
                y_positions_->push_back(start_position);
            }
            snake_element_= sf::RectangleShape(sf::Vector2f(element_width, element_width));
        }

        std::array<std::vector<uint8_t>, 2> get_coordinates() const;
        std::array<uint8_t, 2> get_head_position() const;
        std::array<uint8_t, 2> get_tail_position() const;
        uint8_t length() const;
        bool is_digesting() const;
        eDirection direction() const;
        void eat();
        void digest(Food food);
        void move();
        void turn(eDirection new_direction);
        void draw(sf::RenderWindow &window, Grid &grid);
        void check_for_food(Food food, Grid grid);
};

#endif // SNAKE_H