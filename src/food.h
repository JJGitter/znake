#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#ifndef FOOD_H
#define FOOD_H

class Food {
    private:
        std::array<uint8_t, 2> coordinates_;
        uint8_t* x_position_;
        uint8_t* y_position_;

    public:
        Food()
        {
            x_position_ = &coordinates_[0];
            y_position_ = &coordinates_[1];
        }

        std::array<uint8_t, 2> get_coordinates() const
        {
            return coordinates_;
        }

        std::array<uint8_t, 2> spawn(uint8_t max_x, uint8_t max_y)
        {
            uint8_t random_x = rand() % max_x;
            uint8_t random_y = rand() % max_y;
            *x_position_ = random_x;
            *y_position_ = random_y;

            return coordinates_;
        }

};

#endif // FOOD_H