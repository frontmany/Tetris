#include "blockS.h"
#include "grid.h"

BlockS::BlockS(const CellsArray& array, BlockRotationState startRotationState) 
    : Block(array, startRotationState)
{
}

bool BlockS::tryRotate(Grid& grid) {
    auto& cells = getCells_mut();
    CellsArray expectedCells;
    Color color = cells[0]->getColor();

    for (auto cell : cells) {
        cell->clearColor();
    }

    int pivotRow = cells[1]->getRow();
    int pivotCol = cells[1]->getCol();

    if (getRotationState() == BlockRotationState::DEG_0) {
        int newRow0 = pivotRow - (cells[0]->getCol() - pivotCol);
        int newCol0 = pivotCol + (cells[0]->getRow() - pivotRow);
        
        int newRow1 = pivotRow;
        int newCol1 = pivotCol;
        
        int newRow2 = pivotRow - (cells[2]->getCol() - pivotCol);
        int newCol2 = pivotCol + (cells[2]->getRow() - pivotRow);
        
        int newRow3 = pivotRow - (cells[3]->getCol() - pivotCol);
        int newCol3 = pivotCol + (cells[3]->getRow() - pivotRow);

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
        int newRow0 = pivotRow - (cells[0]->getCol() - pivotCol);
        int newCol0 = pivotCol + (cells[0]->getRow() - pivotRow);
        
        int newRow1 = pivotRow;
        int newCol1 = pivotCol;
        
        int newRow2 = pivotRow - (cells[2]->getCol() - pivotCol);
        int newCol2 = pivotCol + (cells[2]->getRow() - pivotRow);
        
        int newRow3 = pivotRow - (cells[3]->getCol() - pivotCol);
        int newCol3 = pivotCol + (cells[3]->getRow() - pivotRow);

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
        int newRow0 = pivotRow - (cells[0]->getCol() - pivotCol);
        int newCol0 = pivotCol + (cells[0]->getRow() - pivotRow);
        
        int newRow1 = pivotRow;
        int newCol1 = pivotCol;
        
        int newRow2 = pivotRow - (cells[2]->getCol() - pivotCol);
        int newCol2 = pivotCol + (cells[2]->getRow() - pivotRow);
        
        int newRow3 = pivotRow - (cells[3]->getCol() - pivotCol);
        int newCol3 = pivotCol + (cells[3]->getRow() - pivotRow);

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
        int newRow0 = pivotRow - (cells[0]->getCol() - pivotCol);
        int newCol0 = pivotCol + (cells[0]->getRow() - pivotRow);
        
        int newRow1 = pivotRow;
        int newCol1 = pivotCol;
        
        int newRow2 = pivotRow - (cells[2]->getCol() - pivotCol);
        int newCol2 = pivotCol + (cells[2]->getRow() - pivotRow);
        
        int newRow3 = pivotRow - (cells[3]->getCol() - pivotCol);
        int newCol3 = pivotCol + (cells[3]->getRow() - pivotRow);

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

bool BlockS::tryRotateReversed(Grid& grid) {
    auto& cells = getCells_mut();
    CellsArray expectedCells;
    Color color = cells[0]->getColor();

    for (auto cell : cells) {
        cell->clearColor();
    }

    int pivotRow = cells[1]->getRow();
    int pivotCol = cells[1]->getCol();

    if (getRotationState() == BlockRotationState::DEG_0) {
        int newRow0 = pivotRow + (cells[0]->getCol() - pivotCol);
        int newCol0 = pivotCol - (cells[0]->getRow() - pivotRow);
        
        int newRow1 = pivotRow;
        int newCol1 = pivotCol;
        
        int newRow2 = pivotRow + (cells[2]->getCol() - pivotCol);
        int newCol2 = pivotCol - (cells[2]->getRow() - pivotRow);
        
        int newRow3 = pivotRow + (cells[3]->getCol() - pivotCol);
        int newCol3 = pivotCol - (cells[3]->getRow() - pivotRow);

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
        int newRow0 = pivotRow + (cells[0]->getCol() - pivotCol);
        int newCol0 = pivotCol - (cells[0]->getRow() - pivotRow);
        
        int newRow1 = pivotRow;
        int newCol1 = pivotCol;
        
        int newRow2 = pivotRow + (cells[2]->getCol() - pivotCol);
        int newCol2 = pivotCol - (cells[2]->getRow() - pivotRow);
        
        int newRow3 = pivotRow + (cells[3]->getCol() - pivotCol);
        int newCol3 = pivotCol - (cells[3]->getRow() - pivotRow);

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
        int newRow0 = pivotRow + (cells[0]->getCol() - pivotCol);
        int newCol0 = pivotCol - (cells[0]->getRow() - pivotRow);
        
        int newRow1 = pivotRow;
        int newCol1 = pivotCol;
        
        int newRow2 = pivotRow + (cells[2]->getCol() - pivotCol);
        int newCol2 = pivotCol - (cells[2]->getRow() - pivotRow);
        
        int newRow3 = pivotRow + (cells[3]->getCol() - pivotCol);
        int newCol3 = pivotCol - (cells[3]->getRow() - pivotRow);

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
        int newRow0 = pivotRow + (cells[0]->getCol() - pivotCol);
        int newCol0 = pivotCol - (cells[0]->getRow() - pivotRow);
        
        int newRow1 = pivotRow;
        int newCol1 = pivotCol;
        
        int newRow2 = pivotRow + (cells[2]->getCol() - pivotCol);
        int newCol2 = pivotCol - (cells[2]->getRow() - pivotRow);
        
        int newRow3 = pivotRow + (cells[3]->getCol() - pivotCol);
        int newCol3 = pivotCol - (cells[3]->getRow() - pivotRow);

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