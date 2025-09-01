#pragma once

#include "block.h"

class Grid;

class BlockI : public Block {
public:
    BlockI(const CellsArray& array, BlockRotationState startRotationState);
    bool tryRotate(Grid& grid) override;
    bool tryRotateReversed(Grid& grid) override;
};