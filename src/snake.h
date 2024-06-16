#include <iostream>
#include <vector>
#include <cstdint>
#include <SFML/Graphics.hpp>

#ifndef SNAKE_H
#define SNAKE_H

enum direction {
    up = 0,
 right = 1,
  down = 2,
  left = 3
};

class Snake {
    private:
        std::vector<uint8_t> snake_x_position_;
        std::vector<uint8_t> snake_y_position_;
        bool is_digesting_ = false;
        uint8_t direction_ = up;

    public:
        Snake(uint8_t start_position_x, uint8_t start_position_y)
        {
            snake_x_position_.push_back(start_position_x);
            snake_y_position_.push_back(start_position_y);
        }

        std::vector<uint8_t> get_x_vector() const
        {
            return snake_x_position_;
        }

        std::vector<uint8_t> get_y_vector() const
        {
            return snake_y_position_;
        }

        uint8_t length() const
        {
            return snake_x_position_.size();
        }

        void eat()
        {
            is_digesting_ = true;
            uint8_t head_position_x = snake_x_position_[snake_x_position_.size() - 1];
            uint8_t head_position_y = snake_y_position_[snake_y_position_.size() - 1];

            snake_x_position_.push_back(head_position_x + 1);
            snake_y_position_.push_back(head_position_y);
        }

        void digest()
        {
            //grow when tail passes consumed food position
            //snake_x_position_.insert(snake_x_position_.begin(), snake_x_position_[0]);
        }

        void move()
        {
            uint8_t head_position_x = snake_x_position_[snake_x_position_.size() - 1];
            uint8_t head_position_y = snake_y_position_[snake_y_position_.size() - 1];
            switch(direction_)
            {
                case up:
                    snake_x_position_.erase(snake_x_position_.begin());
                    snake_x_position_.push_back(head_position_x);
                    snake_y_position_.erase(snake_y_position_.begin());
                    snake_y_position_.push_back(head_position_y - 1);
                    break;
                case right:
                    snake_x_position_.erase(snake_x_position_.begin());
                    snake_x_position_.push_back(head_position_x + 1);
                    snake_y_position_.erase(snake_y_position_.begin());
                    snake_y_position_.push_back(head_position_y);
                    break;
                case down:
                    snake_x_position_.erase(snake_x_position_.begin());
                    snake_x_position_.push_back(head_position_x);
                    snake_y_position_.erase(snake_y_position_.begin());
                    snake_y_position_.push_back(head_position_y + 1);
                    break;
                case left:
                    snake_x_position_.erase(snake_x_position_.begin());
                    snake_x_position_.push_back(head_position_x - 1);
                    snake_y_position_.erase(snake_y_position_.begin());
                    snake_y_position_.push_back(head_position_y);
                    break;
                default:
                    std::cerr << "Error: Invalid direction" << std::endl;
            }
        }
};

#endif // SNAKE_H