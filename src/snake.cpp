#include "snake.h"

std::array<std::vector<uint8_t>, 2> Snake::get_coordinates() const
{
    return coordinates_;
}

uint8_t Snake::length() const
{
    return x_positions_->size();
}

eDirection Snake::direction() const
{
    return direction_;
}

void Snake::eat()
{
    is_digesting_ = true;
    uint8_t head_position_x = (*x_positions_)[this->length() - 1];
    uint8_t head_position_y = (*y_positions_)[this->length() - 1];

    x_positions_->push_back(head_position_x + 1);
    y_positions_->push_back(head_position_y);
}

void Snake::digest()
{
    //grow when tail passes consumed food position
    //snake_x_position_.insert(snake_x_position_.begin(), snake_x_position_[0]);
}

void Snake::move()
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

void Snake::turn(eDirection new_direction)
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

void Snake::draw(sf::RenderWindow &window, Grid &grid) const
{
    uint8_t grid_element_width = grid.get_pixel_width_of_single_element();
    sf::RectangleShape snake_element(sf::Vector2f(grid_element_width, grid_element_width));
    std::array<std::vector<uint8_t>, 2> coordinates = this->get_coordinates();
    uint16_t snake_pixels_x = 0;
    uint16_t snake_pixels_y = 0;

    for (uint8_t i = 0; i < this->length(); i++)
    {
        snake_pixels_x = grid.get_pixel_x_from_coordinate_x(coordinates[0][i]);
        snake_pixels_y = grid.get_pixel_y_from_coordinate_y(coordinates[1][i]);
        snake_element.setPosition(snake_pixels_x, snake_pixels_y);
        window.draw(snake_element);
    }
}