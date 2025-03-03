#include "block.h"
#include "position.h"

class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1;
        cells.Insert(0, {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)});
        cells.Insert(1, {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)});
        cells.Insert(2, {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)});
        cells.Insert(3, {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)});
        Move(0, 3);
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;
        cells.Insert(0,{Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)});
        cells.Insert(1,{Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)});
        cells.Insert(2,{Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)});
        cells.Insert(3,{Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)});
        Move(0, 3);
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        cells.Insert(0,{Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)});
        cells.Insert(1,{Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)});
        cells.Insert(2,{Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)});
        cells.Insert(3,{Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)});
        Move(-1, 3);
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        cells.Insert(0,{Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)});
        Move(0, 4);
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
        cells.Insert(0,{Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)});
        cells.Insert(1,{Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)});
        cells.Insert(2,{Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)});
        cells.Insert(3,{Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)});
        Move(0, 3);
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        cells.Insert(0,{Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)});
        cells.Insert(1,{Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)});
        cells.Insert(2,{Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)});
        cells.Insert(3,{Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)});
        Move(0, 3);
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
         cells.Insert(0,{Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)});
         cells.Insert(1,{Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)});
         cells.Insert(2,{Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)});
         cells.Insert(3,{Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)});
        Move(0, 3);
    }
};