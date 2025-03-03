#include "game.h"
#include "raylib.h"
#include "MenuState.h"

Game* Game::getInstance()
{
    static Game* instance = NULL;

    if (instance == NULL)
    {
        instance = new Game();
    }

    return instance;
}

void Game::init()
{
    InitWindow(gWidth, gHeight, "raylib Tetris");
    SetTargetFPS(60);
    // Set statemachine to menuState
    stateMachine = new GameStateMachine();
    stateMachine->changeState(new MenuState());
}

void Game::render()
{
    stateMachine->render();
}

void Game::update()
{
    stateMachine->update();
}