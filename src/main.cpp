#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "snake.h"
#include "food.h"
#include "walls.h"

const uint16_t WINDOW_PIXEL_WIDTH = 640; //needs to be evenly divisible by grid_element_width_
const uint8_t FRAME_RATE_LIMIT = 14;

enum GameState
{
    eRunning,
    ePaused,
    eGameOver = -1
};

void toggle_pause(GameState &game_state);
void process_turn_event(sf::Keyboard::Key button_pressed, Snake &snake);
bool check_if_key_is_turn_key(sf::Keyboard::Key pressed_key);

int main()
{
    GameState game_state = ePaused;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_PIXEL_WIDTH, WINDOW_PIXEL_WIDTH),
        "ZNAKE TIME");

    window.setFramerateLimit(FRAME_RATE_LIMIT);

    Grid grid(WINDOW_PIXEL_WIDTH);
    Snake snake(grid);
    Food food;
    Walls walls(grid);
    bool has_collided = false;
    sf::Keyboard::Key queued_turn_event = sf::Keyboard::Unknown;

    food.spawn(grid.get_max_element_index());

    while (window.isOpen())
    {
        bool turn_event_is_queued = queued_turn_event != sf::Keyboard::Unknown;
        bool has_turned_once = false;
        bool is_queueing_allowed = false;
        bool has_made_queued_turn = false;
        if (turn_event_is_queued)
        {
            process_turn_event(queued_turn_event, snake);
            has_made_queued_turn = true;
        }

        sf::Event event;
        queued_turn_event = sf::Keyboard::Unknown;

        while (window.pollEvent(event))
        {
            sf::Keyboard::Key button_pressed = event.key.code;
            bool space_bar_pressed = event.type == sf::Event::KeyPressed && button_pressed == sf::Keyboard::Space;
            bool any_key_pressed = event.type == sf::Event::KeyPressed;

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }else if (space_bar_pressed)
            {
                toggle_pause(game_state);
            }else if (any_key_pressed && game_state == eRunning)
            {
                if (!has_turned_once && !has_made_queued_turn)
                {
                    process_turn_event(button_pressed, snake);
                    has_turned_once = true;
                    is_queueing_allowed = true;
                }else if (is_queueing_allowed)
                {
                    queued_turn_event = button_pressed;
                    is_queueing_allowed = false;
                }
            }
        }

        if (game_state == eRunning) {
            snake.move();
            has_collided = snake.check_for_collision(walls);
            if(has_collided)
            {
                game_state = eGameOver;
            }
            snake.check_for_food(food, grid);

            if (snake.is_digesting())
            {
                snake.digest();
            }
        }

        window.clear(sf::Color(155,186,90,255));

        snake.draw(window, grid);
        food.draw(window, grid);
        walls.draw(window, grid);

        window.display();
    }

    return 0;
}

void toggle_pause(GameState &game_state)
{
    if (game_state == ePaused)
    {
        game_state = eRunning;
    }else if (game_state == eRunning)
    {
        game_state = ePaused;
    }
}

void process_turn_event(sf::Keyboard::Key button_pressed, Snake &snake)
{
    uint8_t current_direction = snake.direction();

    switch (button_pressed)
    {
    case sf::Keyboard::Up:
        if (current_direction != down)
        {
            snake.turn(up);
        }
        break;
    case sf::Keyboard::Right:
        if (current_direction != left)
        {
            snake.turn(right);
        }
        break;
    case sf::Keyboard::Down:
        if (current_direction != up)
        {
            snake.turn(down);
        }
        break;
    case sf::Keyboard::Left:
        if (current_direction != right)
        {
            snake.turn(left);
        }
        break;
    default:
        break;
    }
}