#pragma once

enum GameState
{
    eRunning,
    ePaused,
    eGameOver = -1
};

void toggle_pause(GameState &game_state);
void process_turn_event(sf::Keyboard::Key button_pressed, Snake &snake);