#pragma once

#include "block.h"

class Grid;

class BlockT : public Block {
public:
    BlockT(const CellsArray& array, BlockRotationState startRotationState);
    bool tryRotate(Grid& grid) override;
    bool tryRotateReversed(Grid& grid) override;
};