#include "blockL.h"
#include "grid.h"

BlockL::BlockL(const CellsArray& array, BlockRotationState startRotationState) 
    : Block(array, startRotationState)
{
}

bool BlockL::tryRotate(Grid& grid) {
    auto& cells = getCells_mut();
    CellsArray expectedCells;
    Color color = cells[0]->getColor();

    for (auto cell : cells) {
        cell->clearColor();
    }

    if (getRotationState() == BlockRotationState::DEG_0) {
        int newRow0 = cells[0]->getRow() + 1;
        int newCol0 = cells[0]->getCol() + 1;

        int newRow1 = cells[1]->getRow();
        int newCol1 = cells[1]->getCol();

        int newRow2 = cells[2]->getRow() - 1;
        int newCol2 = cells[2]->getCol() - 1;
        
        int newRow3 = cells[3]->getRow();
        int newCol3 = cells[3]->getCol() - 2;
        
        if (!Grid::checkCellValid(newRow0, newCol0) ||
            !Grid::checkCellValid(newRow1, newCol1) ||
            !Grid::checkCellValid(newRow2, newCol2) ||
            !Grid::checkCellValid(newRow3, newCol3)) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        if (!grid.getArray_mut()[newRow0][newCol0].isEmpty() ||
            !grid.getArray_mut()[newRow1][newCol1].isEmpty() ||
            !grid.getArray_mut()[newRow2][newCol2].isEmpty() ||
            !grid.getArray_mut()[newRow3][newCol3].isEmpty()) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        expectedCells = {
            &grid.getArray_mut()[newRow0][newCol0],
            &grid.getArray_mut()[newRow1][newCol1],
            &grid.getArray_mut()[newRow2][newCol2],
            &grid.getArray_mut()[newRow3][newCol3]
        };
        setRotationState(BlockRotationState::DEG_90);
    }
    else if (getRotationState() == BlockRotationState::DEG_90) {
        int newRow0 = cells[0]->getRow() + 1;
        int newCol0 = cells[0]->getCol() - 1;

        int newRow1 = cells[1]->getRow();
        int newCol1 = cells[1]->getCol();

        int newRow2 = cells[2]->getRow() - 1;
        int newCol2 = cells[2]->getCol() + 1;
        
        int newRow3 = cells[3]->getRow() - 2;
        int newCol3 = cells[3]->getCol();
        
        if (!Grid::checkCellValid(newRow0, newCol0) ||
            !Grid::checkCellValid(newRow1, newCol1) ||
            !Grid::checkCellValid(newRow2, newCol2) ||
            !Grid::checkCellValid(newRow3, newCol3)) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        if (!grid.getArray_mut()[newRow0][newCol0].isEmpty() ||
            !grid.getArray_mut()[newRow1][newCol1].isEmpty() ||
            !grid.getArray_mut()[newRow2][newCol2].isEmpty() ||
            !grid.getArray_mut()[newRow3][newCol3].isEmpty()) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        expectedCells = {
            &grid.getArray_mut()[newRow0][newCol0],
            &grid.getArray_mut()[newRow1][newCol1],
            &grid.getArray_mut()[newRow2][newCol2],
            &grid.getArray_mut()[newRow3][newCol3]
        };
        setRotationState(BlockRotationState::DEG_180);
    }
    else if (getRotationState() == BlockRotationState::DEG_180) {
        int newRow0 = cells[0]->getRow() - 1;
        int newCol0 = cells[0]->getCol() - 1;

        int newRow1 = cells[1]->getRow();
        int newCol1 = cells[1]->getCol();

        int newRow2 = cells[2]->getRow() + 1;
        int newCol2 = cells[2]->getCol() + 1;
        
        int newRow3 = cells[3]->getRow();
        int newCol3 = cells[3]->getCol() + 2;
        
        if (!Grid::checkCellValid(newRow0, newCol0) ||
            !Grid::checkCellValid(newRow1, newCol1) ||
            !Grid::checkCellValid(newRow2, newCol2) ||
            !Grid::checkCellValid(newRow3, newCol3)) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        if (!grid.getArray_mut()[newRow0][newCol0].isEmpty() ||
            !grid.getArray_mut()[newRow1][newCol1].isEmpty() ||
            !grid.getArray_mut()[newRow2][newCol2].isEmpty() ||
            !grid.getArray_mut()[newRow3][newCol3].isEmpty()) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        expectedCells = {
            &grid.getArray_mut()[newRow0][newCol0],
            &grid.getArray_mut()[newRow1][newCol1],
            &grid.getArray_mut()[newRow2][newCol2],
            &grid.getArray_mut()[newRow3][newCol3]
        };
        setRotationState(BlockRotationState::DEG_270);
    }
    else if (getRotationState() == BlockRotationState::DEG_270) {
        int newRow0 = cells[0]->getRow() - 1;
        int newCol0 = cells[0]->getCol() + 1;

        int newRow1 = cells[1]->getRow();
        int newCol1 = cells[1]->getCol();

        int newRow2 = cells[2]->getRow() + 1;
        int newCol2 = cells[2]->getCol() - 1;
        
        int newRow3 = cells[3]->getRow() + 2;
        int newCol3 = cells[3]->getCol();
        
        if (!Grid::checkCellValid(newRow0, newCol0) ||
            !Grid::checkCellValid(newRow1, newCol1) ||
            !Grid::checkCellValid(newRow2, newCol2) ||
            !Grid::checkCellValid(newRow3, newCol3)) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        if (!grid.getArray_mut()[newRow0][newCol0].isEmpty() ||
            !grid.getArray_mut()[newRow1][newCol1].isEmpty() ||
            !grid.getArray_mut()[newRow2][newCol2].isEmpty() ||
            !grid.getArray_mut()[newRow3][newCol3].isEmpty()) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        expectedCells = {
            &grid.getArray_mut()[newRow0][newCol0],
            &grid.getArray_mut()[newRow1][newCol1],
            &grid.getArray_mut()[newRow2][newCol2],
            &grid.getArray_mut()[newRow3][newCol3]
        };
        setRotationState(BlockRotationState::DEG_0);
    }

    for (auto cell : expectedCells) {
        cell->setColor(color);
    }

    cells = expectedCells;
    return true;
}

bool BlockL::tryRotateReversed(Grid& grid) {
    auto& cells = getCells_mut();
    CellsArray expectedCells;
    Color color = cells[0]->getColor();

    for (auto cell : cells) {
        cell->clearColor();
    }

    if (getRotationState() == BlockRotationState::DEG_0) {
        int newRow0 = cells[0]->getRow() + 1;
        int newCol0 = cells[0]->getCol() - 1;

        int newRow1 = cells[1]->getRow();
        int newCol1 = cells[1]->getCol();

        int newRow2 = cells[2]->getRow() - 1;
        int newCol2 = cells[2]->getCol() + 1;
        
        int newRow3 = cells[3]->getRow() - 2;
        int newCol3 = cells[3]->getCol();
        
        if (!Grid::checkCellValid(newRow0, newCol0) ||
            !Grid::checkCellValid(newRow1, newCol1) ||
            !Grid::checkCellValid(newRow2, newCol2) ||
            !Grid::checkCellValid(newRow3, newCol3)) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        if (!grid.getArray_mut()[newRow0][newCol0].isEmpty() ||
            !grid.getArray_mut()[newRow1][newCol1].isEmpty() ||
            !grid.getArray_mut()[newRow2][newCol2].isEmpty() ||
            !grid.getArray_mut()[newRow3][newCol3].isEmpty()) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        expectedCells = {
            &grid.getArray_mut()[newRow0][newCol0],
            &grid.getArray_mut()[newRow1][newCol1],
            &grid.getArray_mut()[newRow2][newCol2],
            &grid.getArray_mut()[newRow3][newCol3]
        };
        setRotationState(BlockRotationState::DEG_270);
    }
    else if (getRotationState() == BlockRotationState::DEG_90) {
        int newRow0 = cells[0]->getRow() - 1;
        int newCol0 = cells[0]->getCol() - 1;

        int newRow1 = cells[1]->getRow();
        int newCol1 = cells[1]->getCol();

        int newRow2 = cells[2]->getRow() + 1;
        int newCol2 = cells[2]->getCol() + 1;
        
        int newRow3 = cells[3]->getRow();
        int newCol3 = cells[3]->getCol() + 2;
        
        if (!Grid::checkCellValid(newRow0, newCol0) ||
            !Grid::checkCellValid(newRow1, newCol1) ||
            !Grid::checkCellValid(newRow2, newCol2) ||
            !Grid::checkCellValid(newRow3, newCol3)) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        if (!grid.getArray_mut()[newRow0][newCol0].isEmpty() ||
            !grid.getArray_mut()[newRow1][newCol1].isEmpty() ||
            !grid.getArray_mut()[newRow2][newCol2].isEmpty() ||
            !grid.getArray_mut()[newRow3][newCol3].isEmpty()) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        expectedCells = {
            &grid.getArray_mut()[newRow0][newCol0],
            &grid.getArray_mut()[newRow1][newCol1],
            &grid.getArray_mut()[newRow2][newCol2],
            &grid.getArray_mut()[newRow3][newCol3]
        };
        setRotationState(BlockRotationState::DEG_0);
    }
    else if (getRotationState() == BlockRotationState::DEG_180) {
        int newRow0 = cells[0]->getRow() - 1;
        int newCol0 = cells[0]->getCol() + 1;

        int newRow1 = cells[1]->getRow();
        int newCol1 = cells[1]->getCol();

        int newRow2 = cells[2]->getRow() + 1;
        int newCol2 = cells[2]->getCol() - 1;
        
        int newRow3 = cells[3]->getRow() + 2;
        int newCol3 = cells[3]->getCol();
        
        if (!Grid::checkCellValid(newRow0, newCol0) ||
            !Grid::checkCellValid(newRow1, newCol1) ||
            !Grid::checkCellValid(newRow2, newCol2) ||
            !Grid::checkCellValid(newRow3, newCol3)) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        if (!grid.getArray_mut()[newRow0][newCol0].isEmpty() ||
            !grid.getArray_mut()[newRow1][newCol1].isEmpty() ||
            !grid.getArray_mut()[newRow2][newCol2].isEmpty() ||
            !grid.getArray_mut()[newRow3][newCol3].isEmpty()) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        expectedCells = {
            &grid.getArray_mut()[newRow0][newCol0],
            &grid.getArray_mut()[newRow1][newCol1],
            &grid.getArray_mut()[newRow2][newCol2],
            &grid.getArray_mut()[newRow3][newCol3]
        };
        setRotationState(BlockRotationState::DEG_90);
    }
    else if (getRotationState() == BlockRotationState::DEG_270) {
        int newRow0 = cells[0]->getRow() + 1;
        int newCol0 = cells[0]->getCol() + 1;

        int newRow1 = cells[1]->getRow();
        int newCol1 = cells[1]->getCol();

        int newRow2 = cells[2]->getRow() - 1;
        int newCol2 = cells[2]->getCol() - 1;
        
        int newRow3 = cells[3]->getRow();
        int newCol3 = cells[3]->getCol() - 2;
        
        if (!Grid::checkCellValid(newRow0, newCol0) ||
            !Grid::checkCellValid(newRow1, newCol1) ||
            !Grid::checkCellValid(newRow2, newCol2) ||
            !Grid::checkCellValid(newRow3, newCol3)) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        if (!grid.getArray_mut()[newRow0][newCol0].isEmpty() ||
            !grid.getArray_mut()[newRow1][newCol1].isEmpty() ||
            !grid.getArray_mut()[newRow2][newCol2].isEmpty() ||
            !grid.getArray_mut()[newRow3][newCol3].isEmpty()) 
        {
            for (auto cell : cells) cell->setColor(color);
            return false;
        }

        expectedCells = {
            &grid.getArray_mut()[newRow0][newCol0],
            &grid.getArray_mut()[newRow1][newCol1],
            &grid.getArray_mut()[newRow2][newCol2],
            &grid.getArray_mut()[newRow3][newCol3]
        };
        setRotationState(BlockRotationState::DEG_180);
    }

    for (auto cell : expectedCells) {
        cell->setColor(color);
    }

    cells = expectedCells;
    return true;
}