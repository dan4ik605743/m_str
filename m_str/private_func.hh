#ifndef PRIVATE_FUNC_HH
#define PRIVATE_FUNC_HH

#include "m_str.hh"

namespace m_str {
constexpr inline void m_str::check_capacity_() {
    auto capacity = std::get<long_str>(sso_).capacity;
    if (capacity <= size_) {
        while (capacity <= size_) {
            capacity *= 2;
        }
        reserve(capacity);
    }
}

constexpr inline bool m_str::check_use_short_str_() const noexcept {
    return static_cast<bool>(std::get_if<short_str>(&sso_));
}

constexpr inline bool m_str::check_use_long_str_() const noexcept {
    return !check_use_short_str_();
}
}  // namespace m_str

#endif
