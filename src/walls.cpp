#include "walls.h"

void Walls::init(uint8_t max_x)
{
    uint16_t wall_pixel_x;
    uint16_t wall_pixel_y;

    for (uint8_t i = 0; i <= max_x; i++)
    {
        //Top wall
        x_coordinates_->push_back(i);
        y_coordinates_->push_back(0);

        //Bottom wall
        x_coordinates_->push_back(i);
        y_coordinates_->push_back(max_x);
    }

    for (uint8_t i = 1; i < max_x; i++)
    {
        //Right wall
        x_coordinates_->push_back(max_x);
        y_coordinates_->push_back(i);

        //Left wall
        x_coordinates_->push_back(0);
        y_coordinates_->push_back(i);
    }
}

void Walls::draw(sf::RenderWindow &window, Grid &grid)
{
    uint16_t wall_pixel_x = 0;
    uint16_t wall_pixel_y = 0;

    for (uint8_t i = 0; i < x_coordinates_->size(); i++)
    {
        wall_pixel_x = grid.get_pixel_x_from_coordinate_x((*x_coordinates_)[i]);
        wall_pixel_y = grid.get_pixel_y_from_coordinate_y((*y_coordinates_)[i]);
        wall_element_.setPosition(wall_pixel_x, wall_pixel_y);
        window.draw(wall_element_);
    }
}
