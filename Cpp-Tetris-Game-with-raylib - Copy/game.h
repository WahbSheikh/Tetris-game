#pragma once
#include "GameStateMachine.h"
#include "FileManagement.h"

class Game
{
private:
    GameStateMachine* stateMachine;
    int gWidth = 500;
    int gHeight = 620;
    std::string currentPlayerName; // Store the current player's name
    int playerCount = 0; // Track the number of players

public:

    GameStateMachine* getGameStateMachine() { return stateMachine; }

    void init();
    static Game* getInstance();
    void render();
    void update();
    int getHeight() { return gHeight; }
    int getWidth() { return gWidth; }
    const std::string& getCurrentPlayerName() const { return currentPlayerName; }
    void setCurrentPlayerName(const std::string& name) { currentPlayerName = name; }

    void incrementPlayerCount() { playerCount++; }
    int getPlayerCount() const { return playerCount; }

    void resetScoresIfNeeded() {
        if (playerCount >= 3) {
            FileManagement::resetHighScores();
            playerCount = 0; // Reset the count
        }
    }
};

