#include <iostream>
#include <vector>
#include <cstdint>
#include <SFML/Graphics.hpp>

#ifndef GRID_H
#define GRID_H

class Grid {
    private:
        uint8_t nr_of_elements_wide_;
        uint16_t nr_of_pixels_wide_;

    public:
        Grid(uint8_t nr_of_elements_wide, uint16_t window_pixel_width)
            : nr_of_elements_wide_(nr_of_elements_wide),
              nr_of_pixels_wide_(window_pixel_width)
        {
        }

        int get_pixel_x_from_coordinate_x(uint8_t coordinate_x) const
        {
            //Assumes grid elements are evenly divisible by the nr of pixels in window
            int pixel_x;

            pixel_x = coordinate_x * nr_of_pixels_wide_ / nr_of_elements_wide_;

            return pixel_x;
        }

        int get_pixel_y_from_coordinate_y(uint8_t coordinate_y) const
        {
            //Assumes grid elements are evenly divisible by the nr of pixels in window
            //Assumes square grid
            int pixel_y;

            pixel_y = coordinate_y * nr_of_pixels_wide_ / nr_of_elements_wide_;

            return pixel_y;
        }
};

#endif // GRID_H