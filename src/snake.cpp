#include "snake.h"

std::array<std::vector<uint8_t>, 2> Snake::get_coordinates() const
{
    return coordinates_;
}

std::array<uint8_t, 2> Snake::get_head_position() const
{
    uint8_t head_position_x = (*x_positions_)[this->length() - 1];
    uint8_t head_position_y = (*y_positions_)[this->length() - 1];
    return {head_position_x, head_position_y};
}

std::array<uint8_t, 2> Snake::get_tail_position() const
{
    uint8_t tail_position_x = (*x_positions_)[this->length() - 1];
    uint8_t tail_position_y = (*y_positions_)[this->length() - 1];
    return {tail_position_x, tail_position_y};
}

uint8_t Snake::length() const
{
    return x_positions_->size();
}

bool Snake::is_digesting() const
{
    return is_digesting_;
}

eDirection Snake::direction() const
{
    return direction_;
}

bool Snake::check_for_collision(Walls &walls)
{
    bool has_collided = false;
    std::array<uint8_t, 2> head_position = this->get_head_position();
    std::array<std::vector<uint8_t>, 2> walls_coordinates = walls.get_coordinates();
    std::array<uint8_t, 2> walls_element;
    std::array<uint8_t, 2> snake_element;
    uint8_t snake_length = this->length();

    //Check wall collision
    for (uint8_t i = 0; i < walls.length(); i++)
    {
        walls_element = {walls_coordinates[0][i], walls_coordinates[1][i]};
        if (head_position == walls_element)
        {
            has_collided = true;
            std::cout << "YOU DIED BY KARUCHI!" << std::endl;
            std::cout << "Snake length: " << static_cast<int>(snake_length) << std::endl;
            break;
        }
    }

    //Check self collision
    for (uint8_t i = 0; i < snake_length - 1; i++)
    {
        snake_element = {(*x_positions_)[i], (*y_positions_)[i]};
        if (head_position == snake_element)
        {
            has_collided = true;
            std::cout << "YOU DIED!" << std::endl;
            std::cout << "Don't eat yourself next time." << std::endl;
            std::cout << "Snake length: " << static_cast<int>(snake_length) << std::endl;
            break;
        }
    }

    return has_collided;
}


void Snake::check_for_food(Food &food, Grid &grid)
{
    std::array<uint8_t, 2> head_position = this->get_head_position();

    if (food.get_coordinates() == head_position)
    {
        is_digesting_ = true;
        position_of_food_being_digested_ = head_position;
        food.spawn(grid.get_max_element_index());
    }
}

void Snake::digest()
{
    std::array<uint8_t, 2> tail_position = this->get_tail_position();
    if (tail_position == position_of_food_being_digested_)
    {
        this->eat();
    }
}

void Snake::eat()
{
    is_digesting_ = false;
    std::array<uint8_t, 2> tail_position = this->get_tail_position();

    //TODO: THIS SWITCH CASE SHOULD PROBABLY CONSIDER THE tail_direction_ INSTEAD OF THE head_direction_
    //ON SECOND THOUGHT, THIS ELEMENT WILL ONLY BE DISPLAYED FOR A FRACTION OF A SECOND. CAN WE SIMPLY DRAW IT ON THE NEXT ITERATION INSTEAD?
    switch(direction_)
    {
        case up:
            x_positions_->insert(x_positions_->begin(), tail_position[0]);
            y_positions_->insert(y_positions_->begin(), tail_position[1] + 1);
            break;
        case right:
            x_positions_->insert(x_positions_->begin(), tail_position[0] - 1);
            y_positions_->insert(y_positions_->begin(), tail_position[1]);
            break;
        case down:
            x_positions_->insert(x_positions_->begin(), tail_position[0]);
            y_positions_->insert(y_positions_->begin(), tail_position[1] + 1);
            break;
        case left:
            x_positions_->insert(x_positions_->begin(), tail_position[0] + 1);
            y_positions_->insert(y_positions_->begin(), tail_position[1]);
            break;
        default:
            std::cerr << "Error: Invalid direction" << std::endl;
    }
}

void Snake::move()
{
    std::array<uint8_t, 2> head_position = this->get_head_position();
    uint8_t head_position_x = head_position[0];
    uint8_t head_position_y = head_position[1];

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

void Snake::draw(sf::RenderWindow &window, Grid &grid)
{
    std::array<std::vector<uint8_t>, 2> coordinates = this->get_coordinates();
    uint16_t snake_pixels_x = 0;
    uint16_t snake_pixels_y = 0;

    for (uint8_t i = 0; i < this->length(); i++)
    {
        snake_pixels_x = grid.get_pixel_x_from_coordinate_x(coordinates[0][i]);
        snake_pixels_y = grid.get_pixel_y_from_coordinate_y(coordinates[1][i]);
        snake_element_.setPosition(snake_pixels_x, snake_pixels_y);
        window.draw(snake_element_);
    }
}