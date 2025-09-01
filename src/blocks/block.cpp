#include "block.h"

#include <cassert>

#include "grid.h"
#include "constants.h"
#include "cell.h"

Block::Block(const CellsArray& cellsArray, BlockRotationState startRotationState)
    : m_cells(cellsArray), m_rotationState(startRotationState), m_state(BlockState::TRANSPARENT)
{
}

Block::Block()
    : m_state(BlockState::EMPTY)
{
}

bool Block::tryMove(Grid& grid, MoveDirection direction) {
    CellsArray expectedCells;
    
    Color color = m_cells[0]->getColor();
    
    for (auto cell : m_cells) {
        cell->clearColor();
    }

    for (int i = 0; i < m_cells.size(); i++) {
        int newRow = m_cells[i]->getRow();
        int newCol = m_cells[i]->getCol();
        
        switch (direction) {
            case LEFT:  newCol--; break;
            case RIGHT: newCol++; break;
            case UP:    newRow--; break;
            case DOWN:  newRow++; break;
        }
        
        if (!Grid::checkCellValid(newRow, newCol)) {
            for (auto cell : m_cells) {
                cell->setColor(color);
            }
            return false;
        }
        else {
            if (!grid.getArray_mut()[newRow][newCol].isEmpty()) {
                for (auto cell : m_cells) {
                    cell->setColor(color);
                }
                return false;
            }
        }
        
        expectedCells[i] = &grid.getArray_mut()[newRow][newCol];
    }

    for (auto cell : expectedCells) {
        cell->setColor(color);
    }
    
    m_cells = expectedCells;
    return true;
}

void Block::setColor(Color color) {
    assert(m_state != BlockState::EMPTY && "Cannot set color for empty block");

    for (auto& cell : m_cells){
        cell->setColor(color);
    }
    
    m_state = BlockState::ACTIVE;
}

void Block::clearColor()
{
    for (auto& cell : m_cells){
        cell->setColor(COLOR_DARK_GRAY);
    }

    m_state = BlockState::TRANSPARENT;
}

// GET
const CellsArray& Block::getCells() {
    return m_cells;
}

CellsArray& Block::getCells_mut() {
    return m_cells;
}

BlockRotationState Block::getRotationState() {
    return m_rotationState;
}


BlockState Block::getState() {
    return m_state;
}


// SET
void Block::setCells(const CellsArray& cellsArray){
    m_cells = cellsArray;
    m_state = BlockState::TRANSPARENT;
}

void Block::setRotationState(BlockRotationState rotationState){
    m_rotationState = rotationState;
}