#pragma once

#include <cstdint>

#include "raylib.h"

inline constexpr int SCREEN_WIDTH = 500;
inline constexpr int SCREEN_HEIGHT = 620;
inline constexpr int DEFAULT_BLOCK_MOVE_DOWN_INTERVAL = 400;
inline constexpr int REFRESH_GRID_INTERVAL = 200;
inline constexpr int ROWS = 20;
inline constexpr int COLS = 10;
inline constexpr int CELL_SIZE_PIXELS = 30;
inline constexpr int OFFSET_PIXELS = 1;
inline constexpr int PIECES_COUNT = 7;
inline constexpr int FIGURE_CELLS_COUNT = 4;
inline constexpr int BLOCK_TYPES_COUNT = 7;
inline constexpr int ROTATION_STATES_COUNT = 4;

// Constants for block preview drawing
static constexpr int PREVIEW_CELL_SIZE = 25;
static constexpr int PREVIEW_OFFSET_X = 320;
static constexpr int PREVIEW_OFFSET_Y = 217;
static constexpr int PREVIEW_CENTER_X = PREVIEW_OFFSET_X + 100; 
static constexpr int PREVIEW_CENTER_Y = PREVIEW_OFFSET_Y + 90; 


inline constexpr int MAX_BLOCK_I_DEG_0_AND_180_OFFSET = 3;
inline constexpr int MAX_BLOCK_I_DEG_90_AND_270_OFFSET_POSITIVE = 5;
inline constexpr int MAX_BLOCK_I_DEG_90_AND_270_OFFSET_NEGATIVE = 3;

inline constexpr int MAX_BLOCK_L_DEG_0_AND_180_OFFSET = 4;
inline constexpr int MAX_BLOCK_L_DEG_90_AND_270_OFFSET_POSITIVE = 4;
inline constexpr int MAX_BLOCK_L_DEG_90_AND_270_OFFSET_NEGATIVE = 3;

inline constexpr int MAX_BLOCK_J_DEG_0_AND_180_OFFSET = 4;
inline constexpr int MAX_BLOCK_J_DEG_90_AND_270_OFFSET_POSITIVE = 4;
inline constexpr int MAX_BLOCK_J_DEG_90_AND_270_OFFSET_NEGATIVE = 3;

inline constexpr int MAX_BLOCK_O_OFFSET = 4;

inline constexpr int MAX_BLOCK_Z_DEG_0_AND_180_OFFSET_POSITIVE = 4;
inline constexpr int MAX_BLOCK_Z_DEG_0_AND_180_OFFSET_NEGATIVE = 3;
inline constexpr int MAX_BLOCK_Z_DEG_90_AND_270_OFFSET = 4;

inline constexpr int MAX_BLOCK_S_DEG_0_AND_180_OFFSET_POSITIVE = 4;
inline constexpr int MAX_BLOCK_S_DEG_0_AND_180_OFFSET_NEGATIVE = 3;
inline constexpr int MAX_BLOCK_S_DEG_90_AND_270_OFFSET = 4;

inline constexpr int MAX_BLOCK_T_DEG_0_AND_180_OFFSET_POSITIVE = 4;
inline constexpr int MAX_BLOCK_T_DEG_0_AND_180_OFFSET_NEGATIVE = 3;
inline constexpr int MAX_BLOCK_T_DEG_90_AND_270_OFFSET = 4;

inline constexpr const char* FONT_PATH = "assets/PressStart2P-Regular.ttf"; 
inline constexpr const char* WINDOW_ICON_PATH = "assets/tetris.png"; 

inline constexpr Color COLOR_WHITE = {241, 243, 249, 255};
inline constexpr Color COLOR_DARK_GRAY = {26, 31, 40, 255};
inline constexpr Color COLOR_LIGHT_GRAY = {200, 200, 200, 255};
inline constexpr Color COLOR_GREEN = {47, 230, 23, 255};
inline constexpr Color COLOR_RED = {232, 18, 18, 255};
inline constexpr Color COLOR_ORANGE = {226, 116, 17, 255};
inline constexpr Color COLOR_YELLOW = {237, 234, 4, 255};
inline constexpr Color COLOR_PURPLE = {226, 34, 229, 255};
inline constexpr Color COLOR_BLUE = {13, 64, 216, 255};