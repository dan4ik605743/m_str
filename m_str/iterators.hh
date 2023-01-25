#ifndef ITERATORS_HH
#define ITERATORS_HH

#include "m_str.hh"

namespace m_str {
constexpr inline m_str::pointer m_str::begin() noexcept {
    if (check_use_short_str_()) {
        return &std::get<short_str>(sso_).at(0);
    }
    return &std::get<long_str>(sso_).str.get()[0];
}

constexpr inline m_str::const_pointer m_str::begin() const noexcept {
    if (check_use_short_str_()) {
        return &std::get<short_str>(sso_).at(0);
    }
    return &std::get<long_str>(sso_).str.get()[0];
}

constexpr inline m_str::pointer m_str::end() noexcept {
    if (check_use_short_str_()) {
        return &std::get<short_str>(sso_).at(size_);
    }
    return &std::get<long_str>(sso_).str.get()[size_];
}

constexpr inline m_str::const_pointer m_str::end() const noexcept {
    if (check_use_short_str_()) {
        return &std::get<short_str>(sso_).at(size_);
    }
    return &std::get<long_str>(sso_).str.get()[size_];
}
}  // namespace m_str

#endif
