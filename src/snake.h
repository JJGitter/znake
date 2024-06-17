#include <iostream>
#include <vector>
#include <cstdint>
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

        std::array<std::vector<uint8_t>, 2> get_coordinates() const
        {
            return coordinates_;
        }

        uint8_t length() const
        {
            return x_positions_->size();
        }

        eDirection direction() const
        {
            return direction_;
        }

        void eat()
        {
            is_digesting_ = true;
            uint8_t head_position_x = (*x_positions_)[this->length() - 1];
            uint8_t head_position_y = (*y_positions_)[this->length() - 1];

            x_positions_->push_back(head_position_x + 1);
            y_positions_->push_back(head_position_y);
        }

        void digest()
        {
            //grow when tail passes consumed food position
            //snake_x_position_.insert(snake_x_position_.begin(), snake_x_position_[0]);
        }

        void move()
        {
            uint8_t head_position_x = (*x_positions_)[this->length() - 1];
            uint8_t head_position_y = (*y_positions_)[this->length() - 1];
            switch(direction_)
            {
                case up:
                    x_positions_->erase(x_positions_->begin());
                    x_positions_->push_back(head_position_x);
                    y_positions_->erase(y_positions_->begin());
                    y_positions_->push_back(head_position_y - 1);
                    break;
                case right:
                    x_positions_->erase(x_positions_->begin());
                    x_positions_->push_back(head_position_x + 1);
                    y_positions_->erase(y_positions_->begin());
                    y_positions_->push_back(head_position_y);
                    break;
                case down:
                    x_positions_->erase(x_positions_->begin());
                    x_positions_->push_back(head_position_x);
                    y_positions_->erase(y_positions_->begin());
                    y_positions_->push_back(head_position_y + 1);
                    break;
                case left:
                    x_positions_->erase(x_positions_->begin());
                    x_positions_->push_back(head_position_x - 1);
                    y_positions_->erase(y_positions_->begin());
                    y_positions_->push_back(head_position_y);
                    break;
                default:
                    std::cerr << "Error: Invalid direction" << std::endl;
            }
        }

        void turn(eDirection new_direction)
        {
            switch (new_direction)
            {
            case up:
                direction_ = up;
                break;
            case right:
                direction_ = right;
                break;
            case down:
                direction_ = down;
                break;
            case left:
                direction_ = left;
                break;
            default:
                std::cerr << "Error: Invalid direction" << std::endl;
                break;
            }
        }
};

#endif // SNAKE_H