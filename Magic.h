#pragma once

#define EXPAND(x) x
#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME

#define PASTE(...)                                                                                                     \
    EXPAND(GET_MACRO(__VA_ARGS__, PASTE10, PASTE9, PASTE8, PASTE7, PASTE6, PASTE5, PASTE4, PASTE3, PASTE2,             \
                     PASTE1)(__VA_ARGS__))

#define PASTE2(func, v1) func(v1)
#define PASTE3(func, v1, v2) PASTE2(func, v1) PASTE2(func, v2)
#define PASTE4(func, v1, v2, v3) PASTE2(func, v1) PASTE3(func, v2, v3)
#define PASTE5(func, v1, v2, v3, v4) PASTE2(func, v1) PASTE4(func, v2, v3, v4)
#define PASTE6(func, v1, v2, v3, v4, v5) PASTE2(func, v1) PASTE5(func, v2, v3, v4, v5)
#define PASTE7(func, v1, v2, v3, v4, v5, v6) PASTE2(func, v1) PASTE6(func, v2, v3, v4, v5, v6)
#define PASTE8(func, v1, v2, v3, v4, v5, v6, v7) PASTE2(func, v1) PASTE7(func, v2, v3, v4, v5, v6, v7)
#define PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8) PASTE2(func, v1) PASTE8(func, v2, v3, v4, v5, v6, v7, v8)
#define PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9) PASTE2(func, v1) PASTE9(func, v2, v3, v4, v5, v6, v7, v8, v9)
