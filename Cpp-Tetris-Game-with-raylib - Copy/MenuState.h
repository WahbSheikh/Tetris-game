#ifndef __MENU_STATE__
#define __MENU__STATE__

#include "GameState.h"

class MenuState : public GameState{
private:
    static const std::string s_menuID;
    static void menuToPlay();
    static void menuToHighScore();
    static void exitFromMenu();
    static void resetHighScores();

public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_menuID; }
};

#endif