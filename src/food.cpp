#include "food.h"
#include <time.h>

std::array<uint8_t, 2> Food::get_coordinates() const
{
    return coordinates_;
}

std::array<uint8_t, 2> Food::spawn(uint8_t max_x)
{
    //TODO: MAKE SURE THAT FOOD CANNOT SPAWN WITHIN THE SNAKE BODY
    srand(time(NULL));
    uint8_t random_x = rand() % (max_x - 1) + 1; //ranges from 1 -> 'max_x - 1'
    uint8_t random_y = rand() % (max_x - 1) + 1;

    *x_position_ = random_x;
    *y_position_ = random_y;

    return coordinates_;
}

void Food::draw(sf::RenderWindow &window, Grid &grid)
{
    uint16_t food_pixel_x;
    uint16_t food_pixel_y;
    uint8_t grid_element_width = grid.get_pixel_width_of_single_element();

    food_element_.setRadius(grid_element_width / 2);
    food_element_.setFillColor(sf::Color::Red);

    food_pixel_x = grid.get_pixel_x_from_coordinate_x(*x_position_);
    food_pixel_y = grid.get_pixel_y_from_coordinate_y(*y_position_);
    food_element_.setPosition(food_pixel_x, food_pixel_y);

    window.draw(food_element_);
}