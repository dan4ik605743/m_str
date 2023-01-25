#ifndef NON_MEMBER_FUNC_HH
#define NON_MEMBER_FUNC_HH

#include "m_str.hh"

namespace m_str {
inline std::ostream& operator<<(std::ostream& ostrm,
                                const m_str& m_str) noexcept {
    return ostrm << m_str.data();
}

inline std::istream& operator>>(std::istream& istrm, m_str& m_str) {
    m_str.clear();

    char buff = 0;
    while (true) {
        buff = static_cast<char>(istrm.get());
        if (buff == '\n' || buff == ' ') {
            return istrm;
        }
        m_str.push_back(buff);
    }

    return istrm;
}

[[nodiscard]] constexpr inline bool operator<(const m_str& lhs,
                                              const m_str& rhs) noexcept {
    return lhs.size() < rhs.size();
};

[[nodiscard]] constexpr inline bool operator>(const m_str& lhs,
                                              const m_str& rhs) noexcept {
    return lhs.size() > rhs.size();
};

[[nodiscard]] constexpr inline bool operator<=(const m_str& lhs,
                                               const m_str& rhs) noexcept {
    return !(lhs.size() > rhs.size());
};

[[nodiscard]] constexpr inline bool operator>=(const m_str& lhs,
                                               const m_str& rhs) noexcept {
    return !(lhs.size() < rhs.size());
};

[[nodiscard]] constexpr inline bool operator==(const m_str& lhs,
                                               const m_str& rhs) noexcept {
    return lhs.compare(rhs.data());
};

[[nodiscard]] constexpr inline bool operator!=(const m_str& lhs,
                                               const m_str& rhs) noexcept {
    return !lhs.compare(rhs.data());
};

template <typename T>
[[nodiscard]] inline m_str to_m_str(T value) {
    constexpr std::uint8_t size = 64;
    std::array<char, size> buff{};

    if (auto [end, ec] = std::to_chars(buff.begin(), buff.end(), value);
        ec == std::errc()) {
        return {buff.begin(), end};

    } else {
        throw std::invalid_argument(std::make_error_code(ec).message());
    }
}
}  // namespace m_str

#endif
