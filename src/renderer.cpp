#include "renderer.h"
#include "grid.h"
#include "constants.h"
#include <cmath>

Renderer::Renderer(Grid& grid)
    : m_grid(grid), m_font(LoadFontEx(FONT_PATH, 64, 0, 0))
{
}

void Renderer::draw(bool isGameOver, uint32_t score, BlockPreviewData blockPreviewData) {
    BeginDrawing();
    ClearBackground(COLOR_WHITE);
    drawGrid();
    drawBasicUIElements();
    drawScore(score);
    drawNextBlockHint(blockPreviewData);
    
    if (isGameOver) {
        drawGameOverLabel();
    }
    EndDrawing();
}

void Renderer::drawScore(uint32_t score) {
    DrawTextEx(m_font, std::to_string(score).c_str(), {400, 70}, 38, 2, COLOR_DARK_GRAY);
}

void Renderer::drawGrid() {
    auto array = m_grid.getArray();
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            DrawRectangle((col + 0.3) * CELL_SIZE_PIXELS + OFFSET_PIXELS,
                (row + 0.3) * CELL_SIZE_PIXELS + OFFSET_PIXELS,
                CELL_SIZE_PIXELS - OFFSET_PIXELS,
                CELL_SIZE_PIXELS - OFFSET_PIXELS,
                array[row][col].getColor()
            );
        }
    }
}

void Renderer::drawGameOverLabel() {
    DrawTextEx(m_font, "GAME\nOVER", {345, 440}, 44, 3, COLOR_RED);
    DrawTextEx(m_font, "press any key", {345, 550}, 16, 2, COLOR_DARK_GRAY);
    DrawTextEx(m_font, "to restart", {362, 575}, 16, 2, COLOR_DARK_GRAY);
}

void Renderer::drawBasicUIElements() {
    DrawTextEx(m_font, "Score", {355, 15}, 38, 2, COLOR_DARK_GRAY);
    DrawRectangleRounded({320, 57, 170, 60}, 0.2, 6, COLOR_LIGHT_GRAY);

    DrawTextEx(m_font, "Next", {365, 175}, 40, 2, COLOR_DARK_GRAY);
    DrawRectangleRounded({320, 217, 170, 180}, 0.2, 6, COLOR_LIGHT_GRAY);
}



void Renderer::drawNextBlockHint(BlockPreviewData blockPreviewData) {
    BlockType type = std::get<BlockType>(blockPreviewData);
    BlockRotationState rotationState = std::get<BlockRotationState>(blockPreviewData);
    Color color = std::get<Color>(blockPreviewData);
    
    Vector2 centerPosition = { 
        PREVIEW_CENTER_X - (2 * PREVIEW_CELL_SIZE), 
        PREVIEW_CENTER_Y - (2 * PREVIEW_CELL_SIZE) 
    };

    switch (type) {
        case BlockType::O:
            drawBlockO(color, centerPosition);
            break;
        case BlockType::I:
            drawBlockI(rotationState, color, centerPosition);
            break;
        case BlockType::J:
            drawBlockJ(rotationState, color, centerPosition);
            break;
        case BlockType::L:
            drawBlockL(rotationState, color, centerPosition);
            break;
        case BlockType::S:
            drawBlockS(rotationState, color, centerPosition);
            break;
        case BlockType::Z:
            drawBlockZ(rotationState, color, centerPosition);
            break;
        case BlockType::T:
            drawBlockT(rotationState, color, centerPosition);
            break;
        default:
            throw std::runtime_error("Unknown block type");
    }   
}

void Renderer::drawCell(Vector2 position, Color color) {
    DrawRectangle(position.x, position.y, PREVIEW_CELL_SIZE, PREVIEW_CELL_SIZE, color);
    DrawRectangleLines(position.x, position.y, PREVIEW_CELL_SIZE, PREVIEW_CELL_SIZE, Fade(BLACK, 0.3f));
}

void Renderer::drawBlockO(Color color, Vector2 position) {
    drawCell({position.x + 10, position.y+ 20}, color);
    drawCell({position.x + PREVIEW_CELL_SIZE + 10, position.y+ 20}, color);
    drawCell({position.x + 10, position.y + PREVIEW_CELL_SIZE+ 20}, color);
    drawCell({position.x + PREVIEW_CELL_SIZE + 10, position.y + PREVIEW_CELL_SIZE+ 20}, color);
}

void Renderer::drawBlockI(BlockRotationState rotationState, Color color, Vector2 position) {
    switch (rotationState) {
        case DEG_0:
        case DEG_180:
            drawCell({position.x - PREVIEW_CELL_SIZE + 10, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 10, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE + 10, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE + 10, position.y + PREVIEW_CELL_SIZE + 10}, color);
            break;
        case DEG_90:
        case DEG_270:
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + 2 * PREVIEW_CELL_SIZE}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + 3 * PREVIEW_CELL_SIZE}, color);
            break;
    }
}

void Renderer::drawBlockJ(BlockRotationState rotationState, Color color, Vector2 position) {
    switch (rotationState) {
        case DEG_0:
            drawCell({position.x + 15, position.y + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + 10}, color);
            drawCell({position.x + 15, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 15, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            break;
        case DEG_90:
            drawCell({position.x, position.y + 20}, color);
            drawCell({position.x, position.y + PREVIEW_CELL_SIZE + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            break;
        case DEG_180:
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 15, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            break;
        case DEG_270:
            drawCell({position.x, position.y + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            break;
    }
}

void Renderer::drawBlockL(BlockRotationState rotationState, Color color, Vector2 position) {
    switch (rotationState) {
        case DEG_0:
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x, position.y + PREVIEW_CELL_SIZE + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            break;
        case DEG_90:
            drawCell({position.x + 15, position.y + 10}, color);
            drawCell({position.x + 15, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 15, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            break;
        case DEG_180:
            drawCell({position.x, position.y + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x, position.y + PREVIEW_CELL_SIZE + 20}, color);
            break;
        case DEG_270:
            drawCell({position.x + 15, position.y + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            break;
    }
}

void Renderer::drawBlockS(BlockRotationState rotationState, Color color, Vector2 position) {
    switch (rotationState) {
        case DEG_0:
        case DEG_180:
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x, position.y + PREVIEW_CELL_SIZE + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            break;
        case DEG_90:
        case DEG_270:
            drawCell({position.x + 15, position.y + 10}, color);
            drawCell({position.x + 15, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            break;
    }
}

void Renderer::drawBlockZ(BlockRotationState rotationState, Color color, Vector2 position) {
    switch (rotationState) {
        case DEG_0:
        case DEG_180:
            drawCell({position.x, position.y + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            break;
        case DEG_90:
        case DEG_270:
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + 10}, color);
            drawCell({position.x + 15, position.y + PREVIEW_CELL_SIZE+ 10}, color);
            drawCell({position.x + 15 + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE+ 10}, color);
            drawCell({position.x + 15, position.y + 2 * PREVIEW_CELL_SIZE+ 10}, color);
            break;
    }
}

void Renderer::drawBlockT(BlockRotationState rotationState, Color color, Vector2 position) {
    switch (rotationState) {
        case DEG_0:
            drawCell({position.x, position.y + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            break;
        case DEG_90:
            drawCell({position.x + 13 + PREVIEW_CELL_SIZE, position.y + 10}, color);
            drawCell({position.x + 13, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 13 + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 13 + PREVIEW_CELL_SIZE, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            break;
        case DEG_180:
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + 20}, color);
            drawCell({position.x, position.y + PREVIEW_CELL_SIZE + 20}, color);
            drawCell({position.x + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            drawCell({position.x + 2 * PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 20}, color);
            break;
        case DEG_270:
            drawCell({position.x + 13, position.y + 10}, color);
            drawCell({position.x + 13, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 13 + PREVIEW_CELL_SIZE, position.y + PREVIEW_CELL_SIZE + 10}, color);
            drawCell({position.x + 13, position.y + 2 * PREVIEW_CELL_SIZE + 10}, color);
            break;
    }
}