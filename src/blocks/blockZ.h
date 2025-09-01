#pragma once

#include "block.h"

class Grid;

class BlockZ : public Block {
public:
    BlockZ(const CellsArray& array, BlockRotationState startRotationState);
    bool tryRotate(Grid& grid) override;
    bool tryRotateReversed(Grid& grid) override;
};