#include "blocksFactory.h"

#include "grid.h"
#include "constants.h"

BlocksFactory::BlocksFactory(Grid& grid) 
    : m_grid(grid), m_colors({COLOR_BLUE, COLOR_GREEN, COLOR_ORANGE, COLOR_PURPLE, COLOR_RED, COLOR_YELLOW}) 
{
}

BlockPreviewData BlocksFactory::generatePreviewData() {
    return {generateRandomBlockType(), generateRandomRotationState(), generateRandomBlockColor()};
}

BlockPtr BlocksFactory::tryGenerateRandomBlock() {    
    BlockPtr block = handleGeneration(generateRandomBlockType(), generateRandomRotationState());
    if (block) {
        block->setColor(generateRandomBlockColor());
    }

    return block;
}

BlockPtr BlocksFactory::tryGenerateBlock(BlockPreviewData blockPreviewData) {
    BlockPtr block = handleGeneration(std::get<BlockType>(blockPreviewData),
     std::get<BlockRotationState>(blockPreviewData)
    );

    if (block) {
        block->setColor(std::get<Color>(blockPreviewData));
    }

    return block;
}

Color BlocksFactory::generateRandomBlockColor() {
    std::uniform_int_distribution<> generateIndex(0, 6);
    return m_colors[generateIndex(m_numbersGenerator)];
}

BlockRotationState BlocksFactory::generateRandomRotationState() {
    std::uniform_int_distribution<> generateRotationState(BlockRotationState::DEG_0, BlockRotationState::DEG_270);
    return static_cast<BlockRotationState>(generateRotationState(m_numbersGenerator));
}

BlockType BlocksFactory::generateRandomBlockType() {
    std::uniform_int_distribution<> generateType(BlockType::I, BlockType::T);
    return static_cast<BlockType>(generateType(m_numbersGenerator));
}

int BlocksFactory::generateRandomOffset(int maxNegativeOffset, int maxPositiveOffset) {
    std::uniform_int_distribution<> choice(0, 1);
    std::uniform_int_distribution<> generateNegative(-maxNegativeOffset, 0);
    std::uniform_int_distribution<> generatePositive(0, maxPositiveOffset);
    
    if (choice(m_numbersGenerator) == 0) {
        return generateNegative(m_numbersGenerator);
    } 
    else {
        return generatePositive(m_numbersGenerator);
    }
}

BlockPtr BlocksFactory::handleGeneration(BlockType type, BlockRotationState rotationState) {
    switch (type) {
        case BlockType::O:
            return generateBlockO(BlockRotationState::DEG_0);
        case BlockType::I:
            return generateBlockI(rotationState);
        case BlockType::J:
            return generateBlockJ(rotationState);
        case BlockType::L:
            return generateBlockL(rotationState);
        case BlockType::S:
            return generateBlockS(rotationState);
        case BlockType::Z:
            return generateBlockZ(rotationState);
        case BlockType::T:
            return generateBlockT(rotationState);
        default:
            throw std::runtime_error("Unknown block type");
    }
}






BlockPtr BlocksFactory::generateBlockI(BlockRotationState rotationState) {
    auto& array = m_grid.getArray_mut();

    if (rotationState == BlockRotationState::DEG_0 || rotationState == BlockRotationState::DEG_180) {
        int offset = generateRandomOffset(MAX_BLOCK_I_DEG_0_AND_180_OFFSET, MAX_BLOCK_I_DEG_0_AND_180_OFFSET);
        
        CellsArray cellsI {
        &array[0][3 + offset],
        &array[0][4 + offset],
        &array[0][5 + offset],
        &array[0][6 + offset]
        };

        for (auto cell : cellsI) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockI>(cellsI, BlockRotationState::DEG_0); 
    }
    else {
        int offset = generateRandomOffset(MAX_BLOCK_I_DEG_90_AND_270_OFFSET_NEGATIVE, MAX_BLOCK_I_DEG_90_AND_270_OFFSET_POSITIVE);
        
        CellsArray cellsI {
        &array[0][4 + offset],
        &array[1][4 + offset],
        &array[2][4 + offset],
        &array[3][4 + offset]
        };

        for (auto cell : cellsI) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockI>(cellsI, BlockRotationState::DEG_90);
    }
}

BlockPtr BlocksFactory::generateBlockJ(BlockRotationState rotationState) {
    auto& array = m_grid.getArray_mut();

    if (rotationState == BlockRotationState::DEG_0) {
        int offset = generateRandomOffset(MAX_BLOCK_J_DEG_0_AND_180_OFFSET, MAX_BLOCK_J_DEG_0_AND_180_OFFSET);
        
        CellsArray cellsJ {
        &array[0][5 + offset],
        &array[1][5 + offset],
        &array[2][5 + offset],
        &array[2][4 + offset]
        };

        for (auto cell : cellsJ) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockJ>(cellsJ, BlockRotationState::DEG_0); 
    }
    else if (rotationState == BlockRotationState::DEG_180) {
        int offset = generateRandomOffset(MAX_BLOCK_J_DEG_0_AND_180_OFFSET, MAX_BLOCK_J_DEG_0_AND_180_OFFSET);
        
        CellsArray cellsJ {
        &array[2][4 + offset],
        &array[1][4 + offset],
        &array[0][4 + offset],
        &array[0][5 + offset]
        };

        for (auto cell : cellsJ) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockJ>(cellsJ, BlockRotationState::DEG_180); 
    }
    else if (rotationState == BlockRotationState::DEG_90) {
        int offset = generateRandomOffset(MAX_BLOCK_J_DEG_90_AND_270_OFFSET_NEGATIVE, MAX_BLOCK_J_DEG_90_AND_270_OFFSET_POSITIVE);
        
        CellsArray cellsJ {
        &array[1][5 + offset],
        &array[1][4 + offset],
        &array[1][3 + offset],
        &array[0][3 + offset]
        };

        for (auto cell : cellsJ) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }
        
        return std::make_shared<BlockJ>(cellsJ, BlockRotationState::DEG_90);
    }
    else {
        int offset = generateRandomOffset(MAX_BLOCK_J_DEG_90_AND_270_OFFSET_NEGATIVE, MAX_BLOCK_J_DEG_90_AND_270_OFFSET_POSITIVE);
        
        CellsArray cellsJ {
        &array[0][3 + offset],
        &array[0][4 + offset],
        &array[0][5 + offset],
        &array[1][5 + offset]
        };

        for (auto cell : cellsJ) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockJ>(cellsJ, BlockRotationState::DEG_270);
    }
}

BlockPtr BlocksFactory::generateBlockL(BlockRotationState rotationState) {
    auto& array = m_grid.getArray_mut();

    if (rotationState == BlockRotationState::DEG_0) {
        int offset = generateRandomOffset(MAX_BLOCK_L_DEG_0_AND_180_OFFSET, MAX_BLOCK_L_DEG_0_AND_180_OFFSET);
        
        CellsArray cellsL {
        &array[0][4 + offset],
        &array[1][4 + offset],
        &array[2][4 + offset],
        &array[2][5 + offset]
        };

        for (auto cell : cellsL) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockL>(cellsL, BlockRotationState::DEG_0); 
    }
    else if (rotationState == BlockRotationState::DEG_180) {
        int offset = generateRandomOffset(MAX_BLOCK_L_DEG_0_AND_180_OFFSET, MAX_BLOCK_L_DEG_0_AND_180_OFFSET);
        
        CellsArray cellsL {
        &array[2][5 + offset],
        &array[1][5 + offset],
        &array[0][5 + offset],
        &array[0][4 + offset]
        };

        for (auto cell : cellsL) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockL>(cellsL, BlockRotationState::DEG_180); 
    }
    else if (rotationState == BlockRotationState::DEG_90) {
        int offset = generateRandomOffset(MAX_BLOCK_L_DEG_90_AND_270_OFFSET_NEGATIVE, MAX_BLOCK_L_DEG_90_AND_270_OFFSET_POSITIVE);
        
        CellsArray cellsL {
        &array[0][5 + offset],
        &array[0][4 + offset],
        &array[0][3 + offset],
        &array[1][3 + offset]
        };

        for (auto cell : cellsL) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockL>(cellsL, BlockRotationState::DEG_90);
    }
    else {
        int offset = generateRandomOffset(MAX_BLOCK_L_DEG_90_AND_270_OFFSET_NEGATIVE, MAX_BLOCK_L_DEG_90_AND_270_OFFSET_POSITIVE);
        
        CellsArray cellsL {
        &array[1][3 + offset],
        &array[1][4 + offset],
        &array[1][5 + offset],
        &array[0][5 + offset]
        };

        for (auto cell : cellsL) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockL>(cellsL, BlockRotationState::DEG_270);
    }
}

BlockPtr BlocksFactory::generateBlockO(BlockRotationState rotationState) {
    auto& array = m_grid.getArray_mut();

    int offset = generateRandomOffset(MAX_BLOCK_O_OFFSET, MAX_BLOCK_O_OFFSET);
    
    CellsArray cellsO {
    &array[0][4 + offset],
    &array[0][5 + offset],
    &array[1][4 + offset],
    &array[1][5 + offset]
    };

    for (auto cell : cellsO) {
        if (!cell->isEmpty()) {
            return nullptr;
        }
    }

    return std::make_shared<BlockO>(cellsO, BlockRotationState::DEG_270);
}

BlockPtr BlocksFactory::generateBlockS(BlockRotationState rotationState) {
    auto& array = m_grid.getArray_mut();

    if (rotationState == BlockRotationState::DEG_0 || rotationState == BlockRotationState::DEG_180) {
        int offset = generateRandomOffset(MAX_BLOCK_S_DEG_0_AND_180_OFFSET_NEGATIVE, MAX_BLOCK_S_DEG_0_AND_180_OFFSET_POSITIVE);
        
        CellsArray cellsS {
        &array[1][3 + offset],
        &array[1][4 + offset],
        &array[0][4 + offset],
        &array[0][5 + offset],
        };

        for (auto cell : cellsS) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockS>(cellsS, BlockRotationState::DEG_0); 
    }
    else {
        int offset = generateRandomOffset(MAX_BLOCK_S_DEG_90_AND_270_OFFSET, MAX_BLOCK_S_DEG_90_AND_270_OFFSET);
        
        CellsArray cellsS {
        &array[2][5 + offset],
        &array[1][5 + offset],
        &array[1][4 + offset],
        &array[0][4 + offset]
        };

        for (auto cell : cellsS) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockS>(cellsS, BlockRotationState::DEG_90);
    }
}

BlockPtr BlocksFactory::generateBlockZ(BlockRotationState rotationState) {
    auto& array = m_grid.getArray_mut();

    if (rotationState == BlockRotationState::DEG_0 || rotationState == BlockRotationState::DEG_180) {
        int offset = generateRandomOffset(MAX_BLOCK_Z_DEG_0_AND_180_OFFSET_NEGATIVE, MAX_BLOCK_Z_DEG_0_AND_180_OFFSET_POSITIVE);
        
        CellsArray cellsZ {
        &array[0][3 + offset],
        &array[0][4 + offset],
        &array[1][4 + offset],
        &array[1][5 + offset],
        };
        
        for (auto cell : cellsZ) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockZ>(cellsZ, BlockRotationState::DEG_0); 
    }
    else {
        int offset = generateRandomOffset(MAX_BLOCK_Z_DEG_90_AND_270_OFFSET, MAX_BLOCK_Z_DEG_90_AND_270_OFFSET);
        
        CellsArray cellsZ {
        &array[0][5 + offset],
        &array[1][5 + offset],
        &array[1][4 + offset],
        &array[2][4 + offset]
        };

        for (auto cell : cellsZ) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockZ>(cellsZ, BlockRotationState::DEG_90);
    }
}

BlockPtr BlocksFactory::generateBlockT(BlockRotationState rotationState) {
    auto& array = m_grid.getArray_mut();

    if (rotationState == BlockRotationState::DEG_0) {
        int offset = generateRandomOffset(MAX_BLOCK_T_DEG_0_AND_180_OFFSET_NEGATIVE, MAX_BLOCK_T_DEG_0_AND_180_OFFSET_POSITIVE);
        
        CellsArray cellsT {
        &array[0][3 + offset],
        &array[0][4 + offset],
        &array[0][5 + offset],
        &array[1][4 + offset]
        };

        for (auto cell : cellsT) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockT>(cellsT, BlockRotationState::DEG_0); 
    }
    else if (rotationState == BlockRotationState::DEG_180) {
        int offset = generateRandomOffset(MAX_BLOCK_T_DEG_0_AND_180_OFFSET_NEGATIVE, MAX_BLOCK_T_DEG_0_AND_180_OFFSET_POSITIVE);
        
        CellsArray cellsT {
        &array[1][5 + offset],
        &array[1][4 + offset],
        &array[1][3 + offset],
        &array[0][4 + offset]
        };

        for (auto cell : cellsT) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }
        
        return std::make_shared<BlockT>(cellsT, BlockRotationState::DEG_180); 
    }
    else if (rotationState == BlockRotationState::DEG_90) {
        int offset = generateRandomOffset(MAX_BLOCK_T_DEG_90_AND_270_OFFSET, MAX_BLOCK_T_DEG_90_AND_270_OFFSET);
        
        CellsArray cellsT {
        &array[0][5 + offset],
        &array[1][5 + offset],
        &array[2][5 + offset],
        &array[1][4 + offset]
        };

        for (auto cell : cellsT) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockT>(cellsT, BlockRotationState::DEG_90);
    }
    else {
        int offset = generateRandomOffset(MAX_BLOCK_J_DEG_90_AND_270_OFFSET_NEGATIVE, MAX_BLOCK_J_DEG_90_AND_270_OFFSET_POSITIVE);
        
        CellsArray cellsT {
        &array[2][4 + offset],
        &array[1][4 + offset],
        &array[0][4 + offset],
        &array[1][5 + offset]
        };

        for (auto cell : cellsT) {
            if (!cell->isEmpty()) {
                return nullptr;
            }
        }

        return std::make_shared<BlockT>(cellsT, BlockRotationState::DEG_270);
    }
}