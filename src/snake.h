#include <iostream>
#include <SFML/Graphics.hpp>

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
        Snake(uint8_t start_position_x, uint8_t start_position_y)
        {
            x_positions_ = &coordinates_[0];
            y_positions_ = &coordinates_[1];
            x_positions_->push_back(start_position_x);
            y_positions_->push_back(start_position_y);
        }

        std::array<std::vector<uint8_t>, 2> get_coordinates() const;

        uint8_t length() const;

        eDirection direction() const;

        void eat();

        void digest();

        void move();

        void turn(eDirection new_direction);
};

#endif // SNAKE_H