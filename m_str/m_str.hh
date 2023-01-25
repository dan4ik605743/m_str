#ifndef M_STR_HH
#define M_STR_HH

#include <algorithm>
#include <array>
#include <charconv>
#include <iostream>
#include <memory>
#include <string_view>
#include <variant>

namespace m_str {
class m_str {
   public:
    using value_type = char;
    using reference = char&;
    using const_reference = const char&;
    using pointer = char*;
    using const_pointer = const char*;
    using iterator = char*;
    using const_iterator = const char*;
    using size_type = std::size_t;

    m_str() noexcept = default;
    constexpr m_str(const_pointer str);
    constexpr m_str(const_iterator begin, const_iterator end);
    constexpr m_str(const m_str& m_str);
    constexpr m_str& operator=(const m_str& m_str);
    m_str(m_str&& m_str) noexcept = default;
    m_str& operator=(m_str&& m_str) noexcept = default;
    // constexpr m_str(m_str&& m_str) noexcept;
    // inline m_str& operator=(m_str&& m_str) noexcept;
    ~m_str() noexcept = default;

    constexpr m_str& operator+=(m_str& m_str);
    constexpr void write(const_pointer str);
    constexpr void append(const_pointer str);
    constexpr void append(const m_str& m_str);
    constexpr void push_back(value_type symbol);
    constexpr void pop_back();
    constexpr void erase(size_type index, size_type count);
    constexpr void erase(iterator pos);

    void resize(size_type count);
    void write(const m_str& m_str);
    void swap(m_str&& m_str);
    void reserve(size_type new_capacity);
    void clear() noexcept;

    void insert(size_type index, size_type count, value_type symbol);
    void insert(size_type index, value_type symbol);
    void insert(size_type index, std::string_view str);
    void insert(size_type index,
                std::string_view str,
                size_type index_str,
                size_type count);

    void replace(size_type pos, size_type count, std::string_view str);

    template <typename OutputIt>
    constexpr void copy(OutputIt iter,
                        size_type count,
                        size_type pos = 0) const;

    [[nodiscard]] constexpr pointer begin() noexcept;
    [[nodiscard]] constexpr pointer end() noexcept;
    [[nodiscard]] constexpr const_pointer begin() const noexcept;
    [[nodiscard]] constexpr const_pointer end() const noexcept;

    [[nodiscard]] constexpr reference front();
    [[nodiscard]] constexpr reference back();
    [[nodiscard]] constexpr const_reference front() const;
    [[nodiscard]] constexpr const_reference back() const;

    [[nodiscard]] constexpr std::string_view view() const noexcept;
    [[nodiscard]] constexpr const_pointer data() const noexcept;
    [[nodiscard]] constexpr pointer data() noexcept;

    [[nodiscard]] constexpr size_type size() const noexcept;
    [[nodiscard]] constexpr size_type length() const noexcept;
    [[nodiscard]] constexpr size_type capacity() const noexcept;

    [[nodiscard]] constexpr bool empty() const noexcept;
    [[nodiscard]] constexpr const_reference at(size_type index) const;
    [[nodiscard]] constexpr reference at(size_type index);
    [[nodiscard]] constexpr std::string_view substr(size_type count,
                                                    size_type pos = 0) const;

    [[nodiscard]] constexpr bool starts_with(
        std::string_view prefix) const noexcept;
    [[nodiscard]] constexpr bool ends_with(
        std::string_view prefix) const noexcept;

    [[nodiscard]] constexpr bool compare(const_pointer str) const noexcept;
    [[nodiscard]] constexpr bool compare(const m_str& m_str) const noexcept;
    [[nodiscard]] constexpr bool compare(
        const std::string_view& str_view) const noexcept;

    [[nodiscard]] constexpr bool containts(std::string_view str) const noexcept;

    [[nodiscard]] constexpr size_type find(std::string_view value,
                                           size_type pos = 0) const;
    [[nodiscard]] constexpr size_type rfind(std::string_view value,
                                            size_type pos = 0) const;
    [[nodiscard]] constexpr size_type find_first_of(std::string_view value,
                                                    size_type pos = 0) const;
    [[nodiscard]] constexpr size_type find_first_not_of(
        std::string_view value,
        size_type pos = 0) const;
    [[nodiscard]] constexpr size_type find_last_of(std::string_view value,
                                                   size_type pos = 0) const;
    [[nodiscard]] constexpr size_type find_last_not_of(std::string_view value,
                                                       size_type pos = 0) const;

    [[nodiscard]] constexpr reference operator[](size_type index);
    [[nodiscard]] constexpr const_reference operator[](size_type index) const;

    // No need use
    /*using it = iterator<T>;
    template<class T>
    class iterator
        : public std::
              iterator<TYPE_ITERATOR, char, char, T*, T&> {
       public:
        using pointer = T*;
        using reference = T&;

        constexpr explicit iterator(pointer ptr) noexcept : ptr_(ptr) {}

        constexpr reference operator*() noexcept { return *ptr_; }
        constexpr pointer operator->() noexcept { return ptr_; }

        constexpr iterator& operator++() noexcept {
            ++ptr_;
            return *this;
        }

        constexpr iterator operator++(int) noexcept {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        constexpr iterator& operator--() noexcept {
            --ptr_;
            return *this;
        }

        constexpr iterator operator--(int) noexcept {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        constexpr bool operator==(const iterator& oth) const noexcept {
            return ptr_ == oth.ptr_;
        };

        constexpr bool operator!=(const iterator& oth) const noexcept {
            return ptr_ != oth.ptr_;
        };

       private:
        pointer ptr_;
    };*/

   private:
    class m_str_opt {
       public:
        constexpr explicit m_str_opt(m_str& m_str) : m_str_(m_str) {}
        constexpr void push_back(value_type symbol);

       private:
        m_str& m_str_;
    };

    static constexpr uint8_t size_long_str_ = 16;

    using short_str = std::array<char, size_long_str_>;
    struct long_str {
        std::unique_ptr<char[]> str;
        size_type capacity = size_long_str_;
    };

    std::variant<short_str, long_str> sso_;
    size_type size_ = 0;

    constexpr void check_capacity_();
    [[nodiscard]] constexpr bool check_use_short_str_() const noexcept;
    [[nodiscard]] constexpr bool check_use_long_str_() const noexcept;
};
}  // namespace m_str

#endif
