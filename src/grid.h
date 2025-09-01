#pragma once

#include <cstdint>
#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <vector>
#include <optional>

#include "raylib.h"

#include "cell.h"
#include "constants.h"

enum class GridState {
    SOLID,
    NEED_TO_REFRESH
};

class Grid {
public:
    Grid(std::function<void(int)> addNewPoints);
    const std::array<std::array<Cell, COLS>, ROWS>& getArray() const;
    std::array<std::array<Cell, COLS>, ROWS>& getArray_mut();
    GridState getState();
    void reset();
    GridState refreshIfNeeded();
    static bool checkCellValid(int row, int col);

private:
    std::optional<uint32_t> clearFilledRows();
    void moveDownCachedCells();
    bool checkIfCellBelowEmptyOrAlreadyInCache(const Cell& cell);
    void transferCellColor(Cell& from, Cell& to);

private:
    std::array<std::array<Cell, COLS>, ROWS> m_array;
    GridState m_state = GridState::SOLID;
    std::vector<Cell*> m_cachedCellsToMoveDownNextStep;
    std::function<void(int)> m_addNewPoints;
};