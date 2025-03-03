#pragma once
#include <vector>
#include "position.h"
#include "colors.h"
#include "simple_map.h"  // Include the custom map header

class Block
{
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int id;

protected:
    SimpleMap cells;  // Using custom SimpleMap instead of std::map

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};
