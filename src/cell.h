#pragma once

#include <cstdint>

#include "raylib.h"

class Cell
{
public:
    Cell();
    Cell(uint32_t row, uint32_t col, Color color);
    ~Cell() = default;

    bool isEmpty() const;
    Color getColor() const;
    uint32_t getRow() const;
    uint32_t getCol() const;

    void setColor(Color color);
    void setRow(uint32_t row);
    void setCol(uint32_t col);
    void clearColor();

private:
    uint32_t m_row;
    uint32_t m_col;
    Color m_color;
};