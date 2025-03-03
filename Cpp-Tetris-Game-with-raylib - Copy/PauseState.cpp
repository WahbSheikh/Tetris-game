#include "PauseState.h"
#include "Game.h"
#include "raylib.h"
#include <iostream>
#include "MenuState.h"
#include "PlayState.h"
const std::string PauseState::s_menuID = "PAUSE";

void PauseState::update()
{
    // Check for mouse click on buttons
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        // Continue Button
        if (GetMouseX() >= 200 && GetMouseX() <= 300 && GetMouseY() >= 300 && GetMouseY() <= 340)
        {
            pauseToPlay();
        }

        // Exit Button
        if (GetMouseX() >= 200 && GetMouseX() <= 300 && GetMouseY() >= 350 && GetMouseY() <= 390)
        {
            exitToMenu();
        }
    }
}

void PauseState::render()
{
    // Clear the screen
    // Draw Menu Buttons

    BeginDrawing();
    ClearBackground(BLUE);

    // draw 2 buttons, one for Continue and second for Exit to menu

    DrawText("PAUSE", 190, 200, 20, LIGHTGRAY);

    // Continue Button
    DrawRectangle(200, 300, 100, 40, DARKBLUE);
    DrawText("CONTINUE", 210, 310, 20, WHITE);

// Exit Button
    DrawRectangle(200, 350, 100, 40, DARKBLUE);
    DrawText("EXIT", 210, 360, 20, WHITE);

    EndDrawing();   

}

bool PauseState::onEnter()
{
    std::cout << "Entered Pause State!" << std::endl;
    return true;
}


bool PauseState::onExit(){

    std::cout << "exiting Pause State\n";
    return true;

}

void PauseState::pauseToPlay(){
   std::cout << "PausetoPlay Button clicked!" << std::endl;
    // Change the state to PlayState
    Game::getInstance()->getGameStateMachine()->popState();
    
    }

void PauseState::exitToMenu(){
   std::cout << "Exit button clicked!" << std::endl;
    // Change the state to MenuState
    Game::getInstance()->getGameStateMachine()->popState();
    Game::getInstance()->getGameStateMachine()->popState();
    Game::getInstance()->getGameStateMachine()->changeState(new MenuState());
}