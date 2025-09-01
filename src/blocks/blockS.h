#pragma once

#include "block.h"

class Grid;

class BlockS : public Block {
public:
    BlockS(const CellsArray& array, BlockRotationState startRotationState);
    bool tryRotate(Grid& grid) override;
    bool tryRotateReversed(Grid& grid) override;
};