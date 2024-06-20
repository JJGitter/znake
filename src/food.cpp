#include "food.h"

std::array<uint8_t, 2> Food::get_coordinates() const
{
    return coordinates_;
}

std::array<uint8_t, 2> Food::spawn(uint8_t max_x, uint8_t max_y)
{
    uint8_t random_x = rand() % max_x;
    uint8_t random_y = rand() % max_y;
    *x_position_ = random_x;
    *y_position_ = random_y;

    return coordinates_;
}