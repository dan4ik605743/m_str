#ifndef M_STR_OPT_HH
#define M_STR_OPT_HH

#include "m_str.hh"

namespace m_str {
constexpr inline void m_str::m_str_opt::push_back(value_type symbol) {
    const std::size_t old_size = m_str_.size_;
    ++m_str_.size_;

    if (m_str_.size_ < size_long_str_ && m_str_.check_use_short_str_()) {
        auto& short_str_ = std::get<short_str>(m_str_.sso_);
        short_str_.at(m_str_.size_ - 1) = symbol;
        short_str_.at(m_str_.size_) = '\0';

        return;
    }

    if (m_str_.check_use_long_str_()) {
        auto& long_str_ = std::get<long_str>(m_str_.sso_);

        m_str_.check_capacity_();
        long_str_.str.get()[m_str_.size_ - 1] = symbol;
        long_str_.str.get()[m_str_.size_] = '\0';

        return;
    }

    // !m_str_.check_user_long_str()
    if (!m_str_.empty()) {
        std::array<char, size_long_str_> old_buff{};
        std::copy(std::get<short_str>(m_str_.sso_).begin(),
                  std::get<short_str>(m_str_.sso_).end(), old_buff.begin());
        old_buff.at(old_size) = '\0';

        m_str_.sso_.emplace<long_str>();
        auto& long_str_ = std::get<long_str>(m_str_.sso_);
        m_str_.check_capacity_();
        std::copy(old_buff.begin(), old_buff.end(), long_str_.str.get());

        long_str_.str.get()[m_str_.size_ - 1] = symbol;
        long_str_.str.get()[m_str_.size_] = '\0';
    } else {
        m_str_.sso_.emplace<long_str>();
        auto& long_str_ = std::get<long_str>(m_str_.sso_);
        m_str_.check_capacity_();

        long_str_.str.get()[m_str_.size_ - 1] = symbol;
        long_str_.str.get()[m_str_.size_] = '\0';
    }
}
}  // namespace m_str

#endif
