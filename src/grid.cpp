#include "grid.h"

Grid::Grid(std::function<void(int)> addNewPoints)
    : m_addNewPoints(addNewPoints)
{
    reset();
}

void Grid::reset() {
    for (uint32_t row = 0; row < ROWS; row++) {
        for (uint32_t col = 0; col < COLS; col++) {
            m_array[row][col].setRow(row);
            m_array[row][col].setCol(col);
            m_array[row][col].setColor(COLOR_DARK_GRAY);
        }
    }

    m_state == GridState::SOLID;
}

const std::array<std::array<Cell, COLS>, ROWS>& Grid::getArray() const {
    return m_array;
}

std::array<std::array<Cell, COLS>, ROWS>& Grid::getArray_mut() {
    return m_array;
}

GridState Grid::getState() {
    return m_state;
}

bool Grid::checkCellValid(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    
    return true;
}

GridState Grid::refreshIfNeeded() {
    if (m_state == GridState::SOLID) {
        auto firstFilledRowOpt = clearFilledRows();

        if (firstFilledRowOpt.has_value()) {
            uint32_t firstFilledRow = firstFilledRowOpt.value();
            
            for (int row = firstFilledRow - 1; row >= 0; row--) {
                for (int col = 0; col < COLS; col++) {

                    if (!m_array[row][col].isEmpty()) {
                        auto& cellTo = m_array[row + 1][col];

                        transferCellColor(m_array[row][col], cellTo);
                        if (checkIfCellBelowEmptyOrAlreadyInCache(cellTo)) {
                            m_cachedCellsToMoveDownNextStep.push_back(&cellTo);
                        }
                    }
                }
            }
        
            if (m_cachedCellsToMoveDownNextStep.size() > 0) {
                m_state = GridState::NEED_TO_REFRESH;
                return m_state;
            }
        }

        return m_state;
    }
    else {
        moveDownCachedCells();
        if (m_cachedCellsToMoveDownNextStep.size() == 0) {
            m_state = GridState::SOLID;
            refreshIfNeeded();
            return m_state;
        }

        return m_state;
    }
}

bool Grid::checkIfCellBelowEmptyOrAlreadyInCache(const Cell& cell) {
    if (checkCellValid(cell.getRow() + 1, cell.getCol())) {
        Cell* cellBelow = &m_array[cell.getRow() + 1][cell.getCol()];

        if (cellBelow->isEmpty()) {
            return true;
        } 
        else {
            bool alreadyCached = std::find(
                m_cachedCellsToMoveDownNextStep.begin(),
                m_cachedCellsToMoveDownNextStep.end(),
                cellBelow
            ) != m_cachedCellsToMoveDownNextStep.end();
            
            if (alreadyCached) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else {
        return false;
    }
}

void Grid::moveDownCachedCells() {
    std::vector<Cell*> newCahce;

    std::sort(m_cachedCellsToMoveDownNextStep.begin(), m_cachedCellsToMoveDownNextStep.end(),
        [](Cell* cell1, Cell* cell2){ return cell1->getRow() > cell2->getRow(); });

    for (auto cell : m_cachedCellsToMoveDownNextStep) {
        if (checkCellValid(cell->getRow() + 1, cell->getCol())) {
            auto& cellTo = m_array[cell->getRow() + 1][cell->getCol()];
        
            transferCellColor(*cell, cellTo);
            if (checkIfCellBelowEmptyOrAlreadyInCache(cellTo)) {
                newCahce.push_back(&cellTo);
            }
        }  
    }

    m_cachedCellsToMoveDownNextStep = newCahce;
}

void Grid::transferCellColor(Cell& from, Cell& to) {
    Color color = from.getColor();
    to.setColor(color);
    from.clearColor();
}

std::optional<uint32_t> Grid::clearFilledRows() {
    std::optional<uint32_t> firstFilledRowIndex = std::nullopt;
    bool isFilledRows = false;

    int filledRowsCount = 0;
    int newPoints = 0; 

    for (int row = ROWS - 1; row >= 0; row--) {
        bool rowFilled = true;
        for (int col = 0; col < COLS; col++) {
            if (m_array[row][col].isEmpty()) {
                rowFilled = false;
                break;
            }
        }
        
        if (rowFilled) {
            filledRowsCount++;
            for (int col = 0; col < COLS; col++) {
                m_array[row][col].clearColor();
            }
            
            if (!firstFilledRowIndex.has_value()) {
                firstFilledRowIndex = row;
            }
            isFilledRows = true;
        }
    }

    if (filledRowsCount == 0) 
    {
    }
    else if (filledRowsCount == 1) {
        newPoints = 100;
    }
    else if (filledRowsCount == 2) {
        newPoints = 300;
    }
    else {
        newPoints = 500;
    }

    m_addNewPoints(newPoints);
    return firstFilledRowIndex;
}