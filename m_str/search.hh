#ifndef SEARCH_HH
#define SEARCH_HH

#include "m_str.hh"

namespace m_str {
constexpr inline m_str::size_type m_str::find(std::string_view value,
                                              size_type pos) const {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    std::string_view str(std::next(begin(), static_cast<std::int64_t>(pos)),
                         end());
    return str.find(value);
}

constexpr inline m_str::size_type m_str::rfind(std::string_view value,
                                               size_type pos) const {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    std::string_view str(std::next(begin(), static_cast<std::int64_t>(pos)),
                         end());
    return str.rfind(value);
}

constexpr inline m_str::size_type m_str::find_first_of(std::string_view value,
                                                       size_type pos) const {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    std::string_view str(std::next(begin(), static_cast<std::int64_t>(pos)),
                         end());
    return str.find_first_of(value);
}

constexpr inline m_str::size_type m_str::find_first_not_of(
    std::string_view value,
    size_type pos) const {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    std::string_view str(std::next(begin(), static_cast<std::int64_t>(pos)),
                         end());
    return str.find_first_not_of(value);
}

constexpr inline m_str::size_type m_str::find_last_of(std::string_view value,
                                                      size_type pos) const {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    std::string_view str(std::next(begin(), static_cast<std::int64_t>(pos)),
                         end());
    return str.find_last_of(value);
}

constexpr inline m_str::size_type m_str::find_last_not_of(
    std::string_view value,
    size_type pos) const {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    std::string_view str(std::next(begin(), static_cast<std::int64_t>(pos)),
                         end());
    return str.find_last_not_of(value);
}
}  // namespace m_str

#endif
