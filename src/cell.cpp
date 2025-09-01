#include "cell.h"
#include "constants.h"

Cell::Cell() 
    : m_color(COLOR_DARK_GRAY) 
{
}

Cell::Cell(uint32_t row, uint32_t col, Color color) 
    : m_row(row), m_col(col), m_color(color) 
{
}

bool Cell::isEmpty() const {
    return m_color.r == COLOR_DARK_GRAY.r &&
        m_color.g == COLOR_DARK_GRAY.g &&
        m_color.b == COLOR_DARK_GRAY.b &&
        m_color.a == COLOR_DARK_GRAY.a;
}

Color Cell::getColor() const
{
    return m_color;
}

void Cell::setColor(Color color)
{
    m_color = color;
}

void Cell::setRow(uint32_t row)
{
    m_row = row;
}

void Cell::setCol(uint32_t col)
{
    m_col = col;
}

void Cell::clearColor()
{
    m_color = COLOR_DARK_GRAY;
}

uint32_t Cell::getRow() const 
{
    return m_row;
}
    
uint32_t Cell::getCol() const 
{
    return m_col;     
}