#include "game.h"

Game::Game() 
    : m_grid([this](int newPoints){ m_score += newPoints; }),
    m_blocksFactory(m_grid),
     m_renderer(m_grid),
     m_blockMoveDownInterval(std::chrono::milliseconds(DEFAULT_BLOCK_MOVE_DOWN_INTERVAL))
{
}

void Game::run() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    SetTargetFPS(60);

    Image icon = LoadImage(WINDOW_ICON_PATH);
    SetWindowIcon(icon);
    UnloadImage(icon);

    generateNewBlockAndNextBlockPreview();  

    m_timer.start(m_blockMoveDownInterval);

    while (!WindowShouldClose())
    {
        checkTimer();
        handleInput();
        m_renderer.draw(m_gameOver, m_score, m_nextBlockPreview);
    }

    CloseWindow();
}

void Game::checkTimer() {
    if (!m_timer.isStopped() && m_timer.isExpired()) {
        if (m_grid.getState() == GridState::SOLID) {
            moveBlockDown();

            if (!m_gameOver && m_grid.getState() == GridState::SOLID) {
                m_timer.start(m_blockMoveDownInterval);
            }
            else if (!m_gameOver) {
                m_timer.start(std::chrono::milliseconds(REFRESH_GRID_INTERVAL));
            }
            else 
            {
            }
        }
        else {
            auto gridState = m_grid.refreshIfNeeded();
            if (m_grid.getState() == GridState::SOLID) {
                loadNewBlock();
                m_timer.start(m_blockMoveDownInterval);
            }
            else{
                m_timer.start(std::chrono::milliseconds(REFRESH_GRID_INTERVAL));
            }
        }
    }
}

void Game::loadNewBlock() {
    if(m_currentBlock = m_blocksFactory.tryGenerateBlock(m_nextBlockPreview); !m_currentBlock) {
        m_timer.stop();
        m_gameOver = true;
        m_score = 0;
    }
    else {
        m_score++;
        m_nextBlockPreview = m_blocksFactory.generatePreviewData();
        updateDifficulty();
    }
}

void Game::generateNewBlockAndNextBlockPreview() {
    m_currentBlock = m_blocksFactory.tryGenerateRandomBlock();
    m_nextBlockPreview = m_blocksFactory.generatePreviewData();
    m_score++;
}

void Game::updateDifficulty() {
    if (m_score <= 100) {
        if (m_blockMoveDownInterval > 300ms) {
            m_blockMoveDownInterval = std::max(300ms, m_blockMoveDownInterval - 5ms);
        }
    }
    else if (m_score <= 200) {
        if (m_blockMoveDownInterval > 200ms) {
            m_blockMoveDownInterval = std::max(200ms, m_blockMoveDownInterval - 10ms);
        }
    }
    else if (m_score <= 500) {
        if (m_blockMoveDownInterval > 120ms) {
            m_blockMoveDownInterval = std::max(120ms, m_blockMoveDownInterval - 5ms);
        }
    }
}

void Game::moveBlockDown() {
    bool moved = m_currentBlock->tryMove(m_grid, MoveDirection::DOWN);
    if (!moved) {
        auto gridState = m_grid.refreshIfNeeded();
        if (gridState == GridState::SOLID) {
            loadNewBlock();
        }
    }
}

void Game::restartGame() {
    m_grid.reset();
    m_gameOver = false;
    generateNewBlockAndNextBlockPreview();
    m_timer.start(std::chrono::milliseconds(DEFAULT_BLOCK_MOVE_DOWN_INTERVAL));
}

void Game::handleInput() {
    if (m_gameOver && GetKeyPressed()) {
        restartGame();
    } 

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        static auto leftLastTime = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - leftLastTime);
        
        if (elapsed > m_keyRepeatDelay) {
            if (m_currentBlock->tryMove(m_grid, LEFT)) {
                leftLastTime = now;
            }
        }
    }
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        static auto rightLastTime = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - rightLastTime);
        
        if (elapsed > m_keyRepeatDelay) {
            if (m_currentBlock->tryMove(m_grid, RIGHT)) {
                rightLastTime = now;
            }
        }
    }
    
    if (IsKeyPressed(KEY_Q)) {
        if (m_currentBlock->tryRotateReversed(m_grid)) {
        }
    }
    
    if (IsKeyPressed(KEY_E)) {
        if (m_currentBlock->tryRotate(m_grid)) {
        }
    }
    
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        static auto downLastTime = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - downLastTime);
        
        if (elapsed > m_fastDropDelay) {
            if (m_currentBlock->tryMove(m_grid, DOWN)) {
                downLastTime = now;
            }
        }
    }
}