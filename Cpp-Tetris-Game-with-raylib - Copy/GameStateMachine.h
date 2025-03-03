#ifndef __GAME_ST_MAC__
#define __GAME_ST_MAC__

#include "GameState.h"
#include "Stack.h" // Include your custom Stack class

class GameStateMachine {
private:
    Stack<GameState*> m_gameStates; // Use your custom Stack
    static const int STACK_SIZE = 100; // Define the maximum size for the stack

public:
    GameStateMachine() : m_gameStates(STACK_SIZE) {} // Initialize custom stack

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();
    void update();
    void render();
};

#endif
