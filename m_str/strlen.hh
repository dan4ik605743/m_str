#ifndef STRLEN_HH
#define STRLEN_HH

#include <cstddef>

//  Constexpr function never produces a constant expression, clangd error
//  Need use strlen_
//  Заебал уже ебучий еррор светит между ебалом, хотя код собирается

//
namespace m_str {
/// @private
constexpr inline size_t strlen_(const char* str) {
    std::size_t size = 0;

    while (str[size] != '\0') {
        if (str[size] != '\0') {
            ++size;
        }
    }
    return size;
}
}  // namespace m_str
#endif
