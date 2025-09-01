#pragma once

#include "block.h"

class Grid;

class BlockO : public Block {
public:
    BlockO(const CellsArray& array, BlockRotationState startRotationState);
    bool tryRotate(Grid& grid) {return false; }
    bool tryRotateReversed(Grid& grid) {return false; }
};