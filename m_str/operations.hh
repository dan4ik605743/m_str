#ifndef OPERATIONS_HH
#define OPERATIONS_HH

#include <algorithm>
#include <memory>
#include <stdexcept>
#include "m_str.hh"
#include "strlen.hh"

namespace m_str {
constexpr inline m_str& m_str::operator+=(m_str& m_str) {
    append(m_str);
    return *this;
}

inline void m_str::swap(m_str&& m_str) {
    *this = std::move(m_str);
}

inline void m_str::clear() noexcept {
    size_ = 0;
    if (check_use_short_str_()) {
        std::get<short_str>(sso_).front() = '\0';
        // sso_.emplace<short_str>();

        return;
    }
    // sso_.emplace<long_str>();
    std::get<long_str>(sso_).str.get()[0] = '\0';
}

constexpr inline std::string_view m_str::substr(size_type count,
                                                size_type pos) const {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    return {std::next(begin(), static_cast<std::int64_t>(pos)),
            std::next(begin(), static_cast<std::int64_t>(pos + count))};
}

template <typename OutputIt>
constexpr inline void m_str::copy(OutputIt iter,
                                  size_type count,
                                  size_type pos) const {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    std::copy_n(std::next(begin(), static_cast<std::int64_t>(pos)),
                // static_cast<typename
                // std::iterator_traits<OutputIt>::difference_type>(pos)),
                count, iter);

    /*const auto* str_ = begin();
    for (std::size_t i = 0, j = pos; i != count; ++i, ++j) {
        to_buff[i] = str_[j];
    }*/
}

inline void m_str::resize(size_type count) {
    if (count == size_) {
        return;
    }

    size_ = count;
    reserve(size_);
}

constexpr inline void m_str::write(const_pointer str) {
    if (str == nullptr) {
        return;
    }
    clear();

    const std::size_t new_size = strlen_(str);
    m_str_opt m_str_opt_(*this);

    for (std::size_t i = 0; i != new_size; ++i) {
        m_str_opt_.push_back(str[i]);
    }
}

inline void m_str::write(const m_str& m_str) {
    const std::size_t new_size = m_str.size_;
    m_str_opt m_str_opt_(*this);

    clear();
    for (std::size_t i = 0; i != new_size; ++i) {
        m_str_opt_.push_back(m_str.data()[i]);
    }
}

constexpr inline void m_str::erase(size_type index, size_type count) {
    if (size_ < index + count) {
        throw std::out_of_range("pos > size");
    }

    size_ -= count;
    auto* str_ = begin();

    for (std::size_t i = index, j = index + count; i != size_; ++i, j++) {
        str_[i] = str_[j];
    }
    str_[size_] = '\0';
}

constexpr inline void m_str::erase(iterator pos) {
    auto index = std::distance(begin(), pos);
    erase(index, 1);
}

constexpr inline void m_str::pop_back() {
    erase(size_ - 1, 1);
}

constexpr inline bool m_str::compare(const_pointer str) const noexcept {
    return data() == std::string_view(str);
}

constexpr inline bool m_str::compare(const m_str& m_str) const noexcept {
    return data() == m_str.data();
}

constexpr inline bool m_str::compare(
    const std::string_view& str_view) const noexcept {
    return data() == str_view;
}

constexpr inline void m_str::append(const_pointer str) {
    if (str == nullptr) {
        return;
    }

    m_str_opt m_str_opt_(*this);
    const std::size_t new_size = strlen_(str);

    for (std::size_t i = 0; i != new_size; ++i) {
        m_str_opt_.push_back(str[i]);
    }
}

constexpr inline void m_str::append(const m_str& m_str) {
    m_str_opt m_str_opt_(*this);
    const std::size_t new_size = m_str.size_;

    for (std::size_t i = 0; i != new_size; ++i) {
        m_str_opt_.push_back(m_str.data()[i]);
    }
}

constexpr inline void m_str::push_back(value_type symbol) {
    m_str_opt m_str_opt_(*this);
    m_str_opt_.push_back(symbol);
}

inline void m_str::insert(size_type index, size_type count, value_type symbol) {
    if (index > size_) {
        throw std::out_of_range("index > size");
    }

    resize(count + size_);
    auto* str_ = begin();

    std::shift_right(std::next(begin(), static_cast<std::int64_t>(index)),
                     end(), static_cast<std::int64_t>(count));

    for (std::size_t i = index, j = 0; j != count; ++i, ++j) {
        str_[i] = symbol;
    }
    str_[size_] = '\0';
}

inline void m_str::insert(size_type index, value_type symbol) {
    if (index > size_) {
        throw std::out_of_range("index > size");
    }

    resize(++size_);
    auto* str_ = begin();

    std::shift_right(std::next(begin(), static_cast<std::int64_t>(index)),
                     end(), 1);

    str_[index] = symbol;
    str_[size_] = '\0';
}

inline void m_str::insert(size_type index, std::string_view str) {
    if (index > size_) {
        throw std::out_of_range("index > size");
    }

    resize(str.size() + size_);
    auto* str_ = begin();

    std::shift_right(std::next(begin(), static_cast<std::int64_t>(index)),
                     end(), static_cast<std::int64_t>(str.size()));

    for (std::size_t i = index, j = 0; j != str.size(); ++i, ++j) {
        str_[i] = str.at(j);
    }
    str_[size_] = '\0';
}

inline void m_str::insert(size_type index,
                          std::string_view str,
                          size_type index_str,
                          size_type count) {
    if (index > size_) {
        throw std::out_of_range("index > size");
    }

    if (index_str > str.size()) {
        throw std::out_of_range("index_str > size_str");
    }

    resize(count + size_);
    auto* str_ = begin();

    std::shift_right(std::next(begin(), static_cast<std::int64_t>(index)),
                     end(), static_cast<std::int64_t>(count));

    const auto* arg_str =
        std::next(str.begin(), static_cast<std::int64_t>(index_str));

    for (std::size_t i = index, j = 0; j != count; ++i, ++j) {
        str_[i] = arg_str[j];
    }
    str_[size_] = '\0';
}

inline void m_str::replace(size_type pos,
                           size_type count,
                           std::string_view str) {
    if (pos > size_) {
        throw std::out_of_range("pos > size");
    }

    auto substr_ = substr(count, pos);
    auto* begin_ = std::next(begin(), static_cast<std::int64_t>(pos));

    const std::size_t arg_size = str.size();
    const std::size_t size_substr =
        std::distance(substr_.begin(), substr_.end());

    auto update_str = [&]() {
        for (std::size_t i = 0; i != arg_size; ++i, ++begin_) {
            *begin_ = str.at(i);
        }
    };

    if (size_substr == arg_size) {
        update_str();
    } else if (size_substr > arg_size) {
        const std::size_t difference = size_substr - arg_size;

        resize(size_ - difference);
        std::shift_left(begin_, end() + size_substr,
                        static_cast<std::int64_t>(difference));  // TODO?
        update_str();
    } else if (size_substr < arg_size) {
        const std::size_t difference = arg_size - size_substr;

        resize(size_ + difference);
        std::shift_right(std::next(begin_), end(),
                         static_cast<std::int64_t>(difference));
        update_str();
    }
}

constexpr inline bool m_str::starts_with(
    std::string_view prefix) const noexcept {
    const auto* begin_ = begin();

    for (const auto& iter : prefix) {
        if (iter != *begin_) {
            return false;
        }
        ++begin_;
    }

    return true;
}

constexpr inline bool m_str::ends_with(std::string_view prefix) const noexcept {
    const auto* iter_ =
        std::next(begin(), static_cast<std::int64_t>(prefix.size()));

    for (const auto& iter : prefix) {
        if (iter != *iter_) {
            return false;
        }
        ++iter_;
    }

    return true;
}

constexpr inline bool m_str::containts(std::string_view str) const noexcept {
    return find(str) != std::string_view::npos;
}
}  // namespace m_str

#endif