#include <iostream>
#include <vector>
#include <cstdint>
#include <SFML/Graphics.hpp>

#ifndef GRID_H
#define GRID_H

class Grid {
    private:
        const uint8_t grid_element_width_ = 8;
        uint16_t nr_of_pixels_wide_;
        uint8_t nr_of_elements_wide_;

    public:
        Grid(uint16_t window_pixel_width)
            : nr_of_pixels_wide_(window_pixel_width)
        {
            nr_of_elements_wide_ = nr_of_pixels_wide_ / grid_element_width_;
        }

        /// @brief
        /// @return element width in pixels
        uint8_t get_pixel_width_of_single_element()
        {
            return grid_element_width_;
        }

        /// @brief
        /// @return
        uint8_t get_width_in_nr_of_elements()
        {
            return nr_of_elements_wide_;
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