#ifndef CAPACITY_HH
#define CAPACITY_HH

#include "m_str.hh"
#include "strlen.hh"

namespace m_str {
constexpr inline bool m_str::empty() const noexcept {
    // return begin() == end();
    return !static_cast<bool>(size());
}

constexpr inline m_str::size_type m_str::size() const noexcept {
    return size_;
}

constexpr inline m_str::size_type m_str::length() const noexcept {
    return size_;
}

inline void m_str::reserve(size_type new_capacity) {
    if (new_capacity <= size_long_str_) {
        return;
    }

    if (check_use_short_str_()) {
        auto& short_str_ = std::get<short_str>(sso_);

        std::unique_ptr<char[]> new_buff(new char[new_capacity]);
        std::copy(short_str_.begin(), short_str_.end(), new_buff.get());

        sso_.emplace<long_str>();
        auto& long_str_ = std::get<long_str>(sso_);

        long_str_.capacity = new_capacity;
        long_str_.str = std::move(new_buff);

        return;
    }

    auto& long_str_ = std::get<long_str>(sso_);

    if (long_str_.capacity > new_capacity) {
        return;
    }

    if (long_str_.str != nullptr) {
        std::size_t size_tmp = strlen_(long_str_.str.get());
        std::unique_ptr<char[]> new_buff(new char[new_capacity]);
        std::copy_n(long_str_.str.get(), size_tmp, new_buff.get());

        long_str_.capacity = new_capacity;
        long_str_.str = std::move(new_buff);

        return;
    }

    long_str_.capacity = new_capacity;
    long_str_.str = std::make_unique<char[]>(long_str_.capacity);
}

constexpr inline m_str::size_type m_str::capacity() const noexcept {
    if (check_use_short_str_()) {
        return size_long_str_ - 1;
    }
    return std::get<long_str>(sso_).capacity - 1;
}
}  // namespace m_str

#endif
