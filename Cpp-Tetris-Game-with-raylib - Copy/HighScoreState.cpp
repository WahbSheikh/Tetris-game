#include "HighScoreState.h"
#include "FileManagement.h"
#include "Game.h"
#include "MenuState.h"
#include "raylib.h"
#include <iostream>
#include "LinkedList.h"

const std::string HighScoreState::s_HiID = "HIGHSCORE";

// Load high scores from the file and sort them
void HighScoreState::loadHighScores() {
    FileManagement::loadHighScores(highScores); // Assuming FileManagement correctly handles LinkedList
    highScores.SortList();                      // Sort the scores in descending order
}

// Display high scores on the screen
void HighScoreState::displayHighScores() {
    int y = 100; // Initial position for the high scores
    for (LinkedList::Node* temp = highScores.getHead(); temp != nullptr; temp = temp->next) {
        std::string entry = temp->name + ": " + std::to_string(temp->score);
        DrawText(entry.c_str(), 80, y, 20, WHITE); // Adjust X and font size if needed
        y += 30; // Move down for the next score
    }
}

// Handle input and update state
void HighScoreState::update() {
    if (IsKeyPressed(KEY_M)) { // Use the 'M' key for returning to the menu
        HighScoreToMenu();
    }
}


// Render high scores and navigation instructions
void HighScoreState::render() {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    // Title
    DrawText("High Scores", 180, 50, 30, RAYWHITE);

    // Display high scores from the member highScores list
    displayHighScores();

    // Instruction to return to the menu
    DrawText("Press 'M' to return to the menu", 100, 400, 20, LIGHTGRAY);

    EndDrawing();
}

// State transition: Load high scores when entering
bool HighScoreState::onEnter() {
    std::cout << "Entered HighScore State!" << std::endl;
    loadHighScores();
    return true;
}

// State transition: Clean up when exiting
bool HighScoreState::onExit() {
    std::cout << "Exiting HighScore State!" << std::endl;
    return true;
}

// Handle navigation back to the main menu
void HighScoreState::HighScoreToMenu() {
    std::cout << "Exiting HighScore State and returning to Menu!" << std::endl;

    // Transition back to Menu State
    Game::getInstance()->getGameStateMachine()->popState();
    Game::getInstance()->getGameStateMachine()->pushState(new MenuState());
}
