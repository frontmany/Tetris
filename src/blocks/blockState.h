#pragma once

#include <cstdint>

enum class BlockState : uint32_t {
    ACTIVE,
    TRANSPARENT,
    EMPTY
};