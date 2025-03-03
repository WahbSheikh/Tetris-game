#include "MenuState.h"
#include "Game.h"
#include "raylib.h"
#include <iostream>
#include "PlayState.h"
#include "HighScoreState.h"
#include "FileManagement.h"
const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
    // Check for mouse click on buttons
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        // Play Button
        if (GetMouseX() >= 200 && GetMouseX() <= 300 && GetMouseY() >= 300 && GetMouseY() <= 340)
        {
            menuToPlay();
        }

        // HighScore Button
        if (GetMouseX() >= 200 && GetMouseX() <= 300 && GetMouseY() >= 350 && GetMouseY() <= 390)
        {
            menuToHighScore();
        }

        // Exit Button
        if (GetMouseX() >= 200 && GetMouseX() <= 300 && GetMouseY() >= 400 && GetMouseY() <= 440)
        {
            exitFromMenu();
        }
    }
}

void MenuState::render()
{
    // Clear the screen
    // Draw Menu Buttons

    BeginDrawing();
    ClearBackground(BLUE);

    DrawText("TETRIS", 160, 200, 40, LIGHTGRAY);

    // Play Button
    DrawRectangle(200, 300, 100, 40, DARKBLUE);
    DrawText("PLAY", 210, 310, 20, WHITE);


    // HighScore Button
    DrawRectangle(200, 350, 100, 40, DARKBLUE);
    DrawText("HIGHSCORE", 210, 360, 20, WHITE);


    // Exit Button
    DrawRectangle(200, 400, 100, 40, DARKBLUE);
    DrawText("EXIT", 210, 410, 20, WHITE);

    EndDrawing();   

}

bool MenuState::onEnter()
{
    std::cout << "Entered Menu State!" << std::endl;
    return true;
}


bool MenuState::onExit(){

    std::cout << "exiting MenuState\n";
    return true;

}

void MenuState::menuToPlay() {
    char playerName[20] = "\0"; // Player name buffer
    int nameLength = 0;

    while (!IsKeyPressed(KEY_ENTER)) {
        BeginDrawing();
        ClearBackground(BLUE);

        DrawText("Enter your name:", 150, 180, 20, WHITE);  // Move label slightly higher for better spacing

        // Draw rectangle for the input box
        DrawRectangle(150, 220, 200, 40, LIGHTGRAY);  // Adjust width to 200 and height to 40 for better alignment
        DrawRectangleLines(150, 220, 200, 40, DARKGRAY); // Optional: Add border for clarity

        // Draw player name text within the rectangle
        DrawText(playerName, 160, 230, 20, BLACK);  // Slight offset for centered alignment within the rectangle

        // Draw instruction text
        DrawText("Press ENTER to continue...", 130, 280, 20, LIGHTGRAY);  // Keep it slightly below the input box


        // Handle character input
        int key = GetKeyPressed();
        if (key >= 32 && key <= 126 && nameLength < 19) { // Printable ASCII characters
            playerName[nameLength++] = (char)key;
            playerName[nameLength] = '\0';
        }

        // Handle backspace
        if (IsKeyPressed(KEY_BACKSPACE) && nameLength > 0) {
            playerName[--nameLength] = '\0';
        }

        EndDrawing();
    }

    Game::getInstance()->setCurrentPlayerName(std::string(playerName));
    Game::getInstance()->getGameStateMachine()->changeState(new PlayState());
}



void MenuState::menuToHighScore(){
    std::cout << "HighScore Button clicked!" << std::endl;
     // Change the state to HighScoreState
     Game::getInstance()->getGameStateMachine()->popState();
     Game::getInstance()->getGameStateMachine()->changeState(new HighScoreState());
}
void MenuState::resetHighScores() {
    FileManagement::resetHighScores();
    std::cout << "High scores reset successfully!" << std::endl;
}

void MenuState::exitFromMenu(){
   std::cout << "Exit button clicked!" << std::endl;
    // Close the game
    CloseWindow();
}