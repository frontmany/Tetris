#pragma once 

#include <cstdint>
#include <tuple>

#include "blockRotationState.h"
#include "blockType.h"


#include "raylib.h"
#if defined(PLATFORM_WEB)
    #include "emscripten.h"
#endif

class Grid;

typedef std::tuple<BlockType, BlockRotationState, Color> BlockPreviewData;

class Renderer {
public:
    Renderer(Grid& grid);
    void draw(bool isGameOver, uint32_t score, BlockPreviewData blockPreviewData);

private:
    void drawGameOverLabel();
    void drawScore(uint32_t score);
    void drawGrid();
    void drawNextBlockHint(BlockPreviewData blockPreviewData);
    void drawBasicUIElements();

    void drawBlockO(Color color, Vector2 position);
    void drawBlockI(BlockRotationState rotationState, Color color, Vector2 position);
    void drawBlockJ(BlockRotationState rotationState, Color color, Vector2 position);
    void drawBlockL(BlockRotationState rotationState, Color color, Vector2 position);
    void drawBlockS(BlockRotationState rotationState, Color color, Vector2 position);
    void drawBlockZ(BlockRotationState rotationState, Color color, Vector2 position);
    void drawBlockT(BlockRotationState rotationState, Color color, Vector2 position);
    void drawCell(Vector2 position, Color color);

private:
    Font m_font;
    Grid& m_grid;
};