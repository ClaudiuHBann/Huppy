#pragma once

namespace Model
{
enum class Format : uint8_t
{
    EXE,
    DMG
};

enum class OS : uint8_t
{
    Windows,
    Mac
};

enum class Arch : uint8_t
{
    _32,
    _64
};
} // namespace Model
