#ifndef __PLAY_STATE__
#define __PLAY_STATE__

#include "GameState.h"
#include "raylib.h"
#include "Block.h"
#include "Grid.h"

class PlayState : public GameState{
private:
    static const std::string s_PlayerID;
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
    Font font;
    
public:
    void onGameOver(int score); 
    virtual void update();
    virtual void render();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_PlayerID; }
};
#endif