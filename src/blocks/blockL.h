#pragma once

#include "block.h"

class Grid;

class BlockL : public Block {
public:
    BlockL(const CellsArray& array, BlockRotationState startRotationState);
    bool tryRotate(Grid& grid) override;
    bool tryRotateReversed(Grid& grid) override;
};