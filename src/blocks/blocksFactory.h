#pragma once 

#include <random>
#include <functional>
#include <memory>

#include "allBlocks.h"
#include "blockRotationState.h"

class Grid;

typedef std::shared_ptr<Block> BlockPtr;
typedef std::tuple<BlockType, BlockRotationState, Color> BlockPreviewData;

class BlocksFactory{
public:
    BlocksFactory(Grid& grid);
    BlockPtr tryGenerateRandomBlock();
    BlockPtr tryGenerateBlock(BlockPreviewData blockPreviewData);
    BlockPreviewData generatePreviewData();
private:
    BlockPtr handleGeneration(BlockType type, BlockRotationState rotationState);
    BlockPtr generateBlockI(BlockRotationState rotationState);
    BlockPtr generateBlockJ(BlockRotationState rotationState);
    BlockPtr generateBlockL(BlockRotationState rotationState);
    BlockPtr generateBlockO(BlockRotationState rotationState);
    BlockPtr generateBlockS(BlockRotationState rotationState);
    BlockPtr generateBlockZ(BlockRotationState rotationState);
    BlockPtr generateBlockT(BlockRotationState rotationState);

    Color generateRandomBlockColor();
    BlockType generateRandomBlockType();
    BlockRotationState generateRandomRotationState();
    int generateRandomOffset(int maxNegativeOffset, int maxPositiveOffset);

private:
    std::array<Color, 6> m_colors;
    std::mt19937 m_numbersGenerator{std::random_device{}()};
    Grid& m_grid;
};