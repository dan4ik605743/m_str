/**
 * @file non_member_func.hh
 * @brief Implementation of methods in the Non member function category.
 */

#ifndef NON_MEMBER_FUNC_HH
#define NON_MEMBER_FUNC_HH

#include "m_str.hh"

namespace m_str {
/**
 * @brief Performs stream output on strings.
 *
 * @param ostrm - A character output stream.
 * @param m_str - The string to be inserted or extracted.
 * @return std::ostream&
 */
inline std::ostream& operator<<(std::ostream& ostrm,
                                const m_str& m_str) noexcept {
    return ostrm << m_str.data();
}

/**
 * @brief Performs stream input on strings.
 *
 * @param ostrm - A character input stream.
 * @param m_str - The string to be inserted or extracted.
 * @return std::istream&
 */
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

/**
 * @brief String comparsion(first with second).
 *
 * @param lhs - First string.
 * @param rhs - Second string.
 * @return true - Strings are equal.
 * @return false - String dont equasl.
 */
[[nodiscard]] constexpr inline bool operator<(const m_str& lhs,
                                              const m_str& rhs) noexcept {
    return lhs.size() < rhs.size();
};

/**
 * @brief String comparsion(first with second).
 *
 * @param lhs - First string.
 * @param rhs - Second string.
 * @return true - Strings are equal.
 * @return false - String dont equasl.
 */
[[nodiscard]] constexpr inline bool operator>(const m_str& lhs,
                                              const m_str& rhs) noexcept {
    return lhs.size() > rhs.size();
};

/**
 * @brief String comparsion(first with second).
 *
 * @param lhs - First string.
 * @param rhs - Second string.
 * @return true - Strings are equal.
 * @return false - String dont equasl.
 */
[[nodiscard]] constexpr inline bool operator<=(const m_str& lhs,
                                               const m_str& rhs) noexcept {
    return !(lhs.size() > rhs.size());
};

/**
 * @brief String comparsion(first with second).
 *
 * @param lhs - First string.
 * @param rhs - Second string.
 * @return true - Strings are equal.
 * @return false - String dont equasl.
 */
[[nodiscard]] constexpr inline bool operator>=(const m_str& lhs,
                                               const m_str& rhs) noexcept {
    return !(lhs.size() < rhs.size());
};

/**
 * @brief String comparsion(first with second).
 *
 * @param lhs - First string.
 * @param rhs - Second string.
 * @return true - Strings are equal.
 * @return false - String dont equasl.
 */
[[nodiscard]] constexpr inline bool operator==(const m_str& lhs,
                                               const m_str& rhs) noexcept {
    return lhs.compare(rhs.data());
};

/**
 * @brief String comparsion(first with second).
 *
 * @param lhs - First string.
 * @param rhs - Second string.
 * @return true - Strings are equal.
 * @return false - String dont equasl.
 */
[[nodiscard]] constexpr inline bool operator!=(const m_str& lhs,
                                               const m_str& rhs) noexcept {
    return !lhs.compare(rhs.data());
};

/**
 * @brief String concatenates(first with second). 
 * 
 * @param lhs - First string. 
 * @param rhs - Second string.
 * @return m_str - Result concatenates.
 */
[[nodiscard]] inline m_str operator+(const m_str& lhs,
                                     const m_str& rhs) noexcept {
    m_str tmp(lhs);
    tmp.append(rhs);

    return tmp;
}

/**
 * @brief Converts an integral or floating point value to string.
 *
 * @tparam T - Template value.
 * @param value - value to converting.
 * @return m_str - Converted value.
 *
 * @throw std::invalid_argument: std::make_error_code(std::errc()).message().
 */
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
