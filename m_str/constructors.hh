/**
 * @file constructors.hh
 * @brief Implementation of class constructors.
 */

#ifndef CONSTRUCTORS_HH
#define CONSTRUCTORS_HH

#include "m_str.hh"

namespace m_str {
constexpr m_str::m_str(const_pointer str) noexcept {
    write(str);
}

constexpr m_str::m_str(const_iterator begin, const_iterator end) noexcept {
    for (const auto* iter = begin; iter != end; ++iter) {
        push_back(*iter);
    }
}

constexpr m_str::m_str(const m_str& m_str) noexcept {
    if (m_str.check_use_short_str_()) {
        write(std::get<short_str>(m_str.sso_).data());
        return;
    }
    write(std::get<long_str>(m_str.sso_).str.get());
}

constexpr inline m_str& m_str::operator=(const m_str& m_str) noexcept {
    if (m_str.check_use_short_str_()) {
        write(std::get<short_str>(m_str.sso_).data());
        return *this;
    }
    write(std::get<long_str>(m_str.sso_).str.get());
    return *this;
}

// use after move
/*constexpr m_str::m_str(m_str&& m_str) noexcept : size_(m_str.size_) {
    m_str.size_ = 0;
    if (m_str.check_use_short_str_()) {
        sso_.emplace<short_str>();
        std::swap(std::get<short_str>(sso_),std::get<short_str>(m_str.sso_));
        m_str.sso_.emplace<short_str>();

        return;
    }

    sso_.emplace<long_str>();
    std::swap(std::get<long_str>(sso_),std::get<long_str>(m_str.sso_));
    m_str.sso_.emplace<short_str>();
}

inline m_str& m_str::operator=(m_str&& m_str) noexcept {
    size_ = m_str.size_;
    m_str.size_ = 0;

    if (m_str.check_use_short_str_()) {
        sso_.emplace<short_str>();
        std::swap(std::get<short_str>(sso_),std::get<short_str>(m_str.sso_));
        m_str.sso_.emplace<short_str>();

        return *this;
    }

    sso_.emplace<long_str>();
    std::swap(std::get<long_str>(sso_),std::get<long_str>(m_str.sso_));
    m_str.sso_.emplace<short_str>();

    return *this;
}*/
}  // namespace m_str

#endif
