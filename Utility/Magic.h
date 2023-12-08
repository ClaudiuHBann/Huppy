#pragma once

#define EXPAND(x) x
#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, MACRO, ...) MACRO

// clang-format off
#define PASTE(...) EXPAND(GET_MACRO(__VA_ARGS__, PASTE9, PASTE8, PASTE7, PASTE6, PASTE5, PASTE4, PASTE3, PASTE2, PASTE1)(__VA_ARGS__))

#define PASTE1(func, v1) func(v1)
#define PASTE2(func, v1, v2) PASTE1(func, v1) PASTE1(func, v2)
#define PASTE3(func, v1, v2, v3) PASTE1(func, v1) PASTE2(func, v2, v3)
#define PASTE4(func, v1, v2, v3, v4) PASTE1(func, v1) PASTE3(func, v2, v3, v4)
#define PASTE5(func, v1, v2, v3, v4, v5) PASTE1(func, v1) PASTE4(func, v2, v3, v4, v5)
#define PASTE6(func, v1, v2, v3, v4, v5, v6) PASTE1(func, v1) PASTE5(func, v2, v3, v4, v5, v6)
#define PASTE7(func, v1, v2, v3, v4, v5, v6, v7) PASTE1(func, v1) PASTE6(func, v2, v3, v4, v5, v6, v7)
#define PASTE8(func, v1, v2, v3, v4, v5, v6, v7, v8) PASTE1(func, v1) PASTE7(func, v2, v3, v4, v5, v6, v7, v8)
#define PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8, v9) PASTE1(func, v1) PASTE8(func, v2, v3, v4, v5, v6, v7, v8, v9)
// clang-format on

namespace Utility
{
template <typename> inline constexpr bool always_false = false;

template <typename Type, typename TypeM> constexpr void Move(Type &aObject, TypeM &&aObjectM) noexcept
{
    if constexpr (std::is_move_assignable_v<TypeM>)
    {
        aObject = std::move(aObjectM);
    }
    else if constexpr (std::is_swappable_with_v<Type, TypeM>)
    {
        std::swap(aObject, aObjectM);
    }
    else
    {
        static_assert(always_false<TypeM>, "Type cannot be moved to or swapped with TypeM");
    }
}
} // namespace Utility
