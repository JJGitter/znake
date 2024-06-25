#include <iostream>
#include <vector>
#include <cstdint>
#include <SFML/Graphics.hpp>

#ifndef GRID_H
#define GRID_H

class Grid {
    private:
        const uint8_t grid_element_width_ = 16; //window_pixel_width needs to be evenly divisible by this
        uint16_t nr_of_pixels_wide_;
        uint8_t nr_of_elements_wide_;

    public:
        Grid(uint16_t window_pixel_width)
            : nr_of_pixels_wide_(window_pixel_width)
        {
            nr_of_elements_wide_ = nr_of_pixels_wide_ / grid_element_width_;
        }

    uint8_t get_pixel_width_of_single_element() const;
    uint8_t get_width_in_nr_of_elements() const;
    int get_pixel_x_from_coordinate_x(uint8_t coordinate_x) const;
    int get_pixel_y_from_coordinate_y(uint8_t coordinate_y) const;
};

#endif // GRID_H