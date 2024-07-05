#include "walls.h"

void Walls::draw(sf::RenderWindow &window, Grid &grid)
{
    uint16_t wall_pixel_x;
    uint16_t wall_pixel_y;
    uint8_t grid_element_width = grid.get_pixel_width_of_single_element();
    uint8_t grid_width = grid.get_width_in_nr_of_elements();

    for (uint8_t i = 0; i < grid_width; i++)
    {
        //Top wall
        wall_pixel_x = grid.get_pixel_x_from_coordinate_x(i);
        wall_pixel_y = grid.get_pixel_y_from_coordinate_y(0);
        wall_element_.setPosition(wall_pixel_x, wall_pixel_y);
        window.draw(wall_element_);

        //Bottom wall
        wall_pixel_x = grid.get_pixel_x_from_coordinate_x(i);
        wall_pixel_y = grid.get_pixel_y_from_coordinate_y(grid_width - 1);
        wall_element_.setPosition(wall_pixel_x, wall_pixel_y);
        window.draw(wall_element_);
    }

    for (uint8_t i = 1; i < grid_width - 1; i++)
    {
        //Right wall
        wall_pixel_x = grid.get_pixel_x_from_coordinate_x(grid_width - 1);
        wall_pixel_y = grid.get_pixel_y_from_coordinate_y(i);
        wall_element_.setPosition(wall_pixel_x, wall_pixel_y);
        window.draw(wall_element_);
        //Left wall
        wall_pixel_x = grid.get_pixel_x_from_coordinate_x(0);
        wall_pixel_y = grid.get_pixel_y_from_coordinate_y(i);
        wall_element_.setPosition(wall_pixel_x, wall_pixel_y);
        window.draw(wall_element_);
    }
}