#pragma once

#include "block.h"

class Grid;

class BlockJ : public Block {
public:
    BlockJ(const CellsArray& array, BlockRotationState startRotationState);
    bool tryRotate(Grid& grid) override;
    bool tryRotateReversed(Grid& grid) override;
};