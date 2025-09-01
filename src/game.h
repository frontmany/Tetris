#pragma once

#include <vector>
#include <memory>

#include "grid.h"
#include "timer.h"
#include "block.h"
#include "blocksFactory.h"
#include "renderer.h"


using namespace std::chrono_literals;

typedef std::shared_ptr<Block> BlockPtr;
typedef std::tuple<BlockType, BlockRotationState, Color> BlockPreviewData;

class Game {
public:
    Game();
    void run();

private:
    void updateGridIfNeeded();
    void generateNewBlockAndNextBlockPreview();
    void loadNewBlock();
    void handleInput();
    void moveBlockDown();
    void checkTimer();
    void restartGame();
    void updateDifficulty(); 

private:
    bool m_gameOver = false;
    uint32_t m_score;
    std::chrono::milliseconds m_blockMoveDownInterval;
    std::chrono::milliseconds m_keyRepeatDelay = 100ms;
    std::chrono::milliseconds m_fastDropDelay = 50ms;

    Grid m_grid;
    BlocksFactory m_blocksFactory;
    Renderer m_renderer;
    BlockPtr m_currentBlock;
    BlockPreviewData m_nextBlockPreview;
    Timer m_timer;
};