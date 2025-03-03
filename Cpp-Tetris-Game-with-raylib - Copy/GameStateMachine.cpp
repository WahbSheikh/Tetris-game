#include "GameStateMachine.h"
#include <iostream>

void GameStateMachine::pushState(GameState* pState) {
    if (!m_gameStates.isFull()) {
        std::cout << "Pushing state: " << pState->getStateID() << std::endl;
        m_gameStates.push(pState);
        m_gameStates.peek()->onEnter();
    } else {
        std::cerr << "Error: State stack is full, cannot push state." << std::endl;
    }
}

void GameStateMachine::popState() {
    if (!m_gameStates.isEmpty()) {
        std::cout << "Popping state: " << m_gameStates.peek()->getStateID() << std::endl;
        if (m_gameStates.peek()->onExit()) {
            delete m_gameStates.peek(); // Free the memory
            m_gameStates.pop();
        }
    } else {
        std::cerr << "Error: State stack is empty, cannot pop state." << std::endl;
    }
}

void GameStateMachine::changeState(GameState* pState) {
    if (!m_gameStates.isEmpty() && m_gameStates.peek()->getStateID() == pState->getStateID()) { 
        return; // Do nothing if the new state is the same as the current
    }

    std::cout << "Changing to state: " << pState->getStateID() << std::endl;

    if (!m_gameStates.isEmpty()) {
        if (m_gameStates.peek()->onExit()) {
            delete m_gameStates.peek(); // Free the current state memory
            m_gameStates.pop();
        }
    }

    pushState(pState);
}

void GameStateMachine::update() {
    if (!m_gameStates.isEmpty()) {
        m_gameStates.peek()->update();
    }
}

void GameStateMachine::render() {
    if (!m_gameStates.isEmpty()) {
        m_gameStates.peek()->render();
    }
}
