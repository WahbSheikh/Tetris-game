#ifndef __PAUSE_STATE__
#define __PAUSE_STATE__

#include "GameState.h"

class PauseState : public GameState{
private:
    static const std::string s_menuID;
    static void pauseToPlay();
    static void exitToMenu();

public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_menuID; }
};

#endif

