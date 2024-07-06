#pragma once

enum GameState
{
    eRunning,
    ePaused
};

void process_turn_event(sf::Event &event, Snake &snake, bool &is_key_already_pressed);
