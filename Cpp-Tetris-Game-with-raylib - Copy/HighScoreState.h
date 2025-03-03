#ifndef __HIGHSCORE_STATE__
#define __HIGHSCORE_STATE__

#include "GameState.h"
#include "LinkedList.h"

class HighScoreState : public GameState {
private:
    static const std::string s_HiID;
    LinkedList highScores; // Stores the high scores

    void loadHighScores();       // Load high scores from a file
    void displayHighScores();    // Render high scores to the screen

public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_HiID; }
    void HighScoreToMenu();      // Now a non-static member function
};

#endif
