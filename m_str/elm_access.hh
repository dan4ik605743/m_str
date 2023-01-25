#ifndef ELM_ACCESS_HH
#define ELM_ACCESS_HH

#include "m_str.hh"

namespace m_str {
constexpr inline m_str::const_reference m_str::operator[](
    size_type index) const {
    return *(begin() + index);
}

constexpr inline m_str::reference m_str::operator[](size_type index) {
    return *(begin() + index);
}

constexpr inline m_str::const_reference m_str::at(size_type index) const {
    if (index > size_) {
        throw std::out_of_range("Index out of buffer");
    }
    return *(begin() + index);
}

constexpr inline m_str::reference m_str::at(size_type index) {
    if (index > size_) {
        throw std::out_of_range("Index out of buffer");
    }
    return *(begin() + index);
}

constexpr inline m_str::reference m_str::front() {
    if (empty()) {
        throw std::out_of_range("Str is empty");
    }
    if (check_use_short_str_()) {
        return std::get<short_str>(sso_).front();
    }
    return std::get<long_str>(sso_).str.get()[0];
}

constexpr inline m_str::const_reference m_str::front() const {
    if (empty()) {
        throw std::out_of_range("Str is empty");
    }
    if (check_use_short_str_()) {
        return std::get<short_str>(sso_).front();
    }
    return std::get<long_str>(sso_).str.get()[0];
}

constexpr inline m_str::reference m_str::back() {
    if (empty()) {
        throw std::out_of_range("Str is empty");
    }
    if (check_use_short_str_()) {
        return std::get<short_str>(sso_).at(size_ - 1);
    }
    return std::get<long_str>(sso_).str.get()[size_ - 1];
}

constexpr inline m_str::const_reference m_str::back() const {
    if (empty()) {
        throw std::out_of_range("Str is empty");
    }
    if (check_use_short_str_()) {
        return std::get<short_str>(sso_).at(size_ - 1);
    }
    return std::get<long_str>(sso_).str.get()[size_ - 1];
}

constexpr inline m_str::const_pointer m_str::data() const noexcept {
    return begin();
}

constexpr inline m_str::pointer m_str::data() noexcept {
    return begin();
}

constexpr inline std::string_view m_str::view() const noexcept {
    return {begin(), end()};
}
}  // namespace m_str

#endif
