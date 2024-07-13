#include "grid.h"

/// @brief
/// @return Width of a single grid element in pixels.
uint8_t Grid::get_pixel_width_of_single_element() const
{
    return GRID_ELEMENT_WIDTH_;
}

/// @brief
/// @return The number of elements that span the width of the playing window.
uint8_t Grid::get_width_in_nr_of_elements() const
{
    return nr_of_elements_wide_;
}

uint8_t Grid::get_max_element_index() const
{
    return nr_of_elements_wide_ - 1;
}

/// @brief Assumes grid elements are evenly divisible by the nr of pixels in window.
/// @return x-coordinate in pixels.
int Grid::get_pixel_x_from_coordinate_x(uint8_t coordinate_x) const
{
    int pixel_x;

    pixel_x = coordinate_x * nr_of_pixels_wide_ / nr_of_elements_wide_;

    return pixel_x;
}

/// @brief Assumes grid elements are evenly divisible by the nr of pixels in window.
/// Assumes square grid.
/// @return y-coordinate in pixels.
int Grid::get_pixel_y_from_coordinate_y(uint8_t coordinate_y) const
{
    int pixel_y;

    pixel_y = coordinate_y * nr_of_pixels_wide_ / nr_of_elements_wide_;

    return pixel_y;
}