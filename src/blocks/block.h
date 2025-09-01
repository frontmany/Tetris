#pragma once

#include <array>

#include "cell.h"
#include "constants.h"
#include "blockType.h"
#include "blockState.h"
#include "blockRotationState.h"
#include "moveDirection.h"

class Grid;

typedef std::array<Cell*, FIGURE_CELLS_COUNT> CellsArray;

class Block {
public:
    Block();
    Block(const CellsArray& array, BlockRotationState startRotationState);
    bool tryMove(Grid& grid, MoveDirection direction);
    virtual bool tryRotate(Grid& grid){ return false; }
    virtual bool tryRotateReversed(Grid& grid){return false; }

    void clearColor();
    void setColor(Color color);
    BlockState getState();

protected:
    const CellsArray& getCells();
    CellsArray& getCells_mut();
    BlockRotationState getRotationState();

    void setCells(const CellsArray& cellsArray);
    void setRotationState(BlockRotationState position);

private:
    BlockState m_state;
    BlockRotationState m_rotationState;
    CellsArray m_cells;
};