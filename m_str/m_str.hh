/**
 * @file m_str.hh
 * @brief m_str class declaration.
 */

#ifndef M_STR_HH
#define M_STR_HH

#include <algorithm>
#include <array>
#include <charconv>
#include <iostream>
#include <memory>
#include <string_view>
#include <variant>

/// Namespace for the entire class string and for non-class methods.
namespace m_str {
/**
 * @brief The main class of the string itself.
 *
 * Contains all the main methods from std::string, also implemented by SSO.
 * Up to 16 bytes, the memory lies on the stack, after which it is transferred
 * to dynamic memory.
 */
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

    /// Default constrcutor.
    constexpr m_str() noexcept = default;

    /**
     * @brief Constructor that does this->write(str).
     *
     * @param str - Data to be recorded.
     *
     */
    constexpr m_str(const_pointer str) noexcept;

    /**
     * @brief Constructor that does this nicely is this->push_back(begin++).
     *
     * @param begin - Iterator for begin data.
     * @param end - Iterator for end data.
     *
     */
    constexpr m_str(const_iterator begin, const_iterator end) noexcept;

    /**
     * @brief Constructor that does this->write(m_str).
     *
     * @param m_str - Data to be recorded.
     *
     */
    constexpr m_str(const m_str& m_str) noexcept;

    /**
     * @brief Constructor that does this->write(m_str).
     *
     * @param m_str - Data to be recorded.
     *
     */
    constexpr m_str& operator=(const m_str& m_str) noexcept;

    /**
     * @brief Construct a new m_str object.
     *
     * @param m_str - Data which gives its state.
     */
    m_str(m_str&& m_str) noexcept = default;

    /**
     * @brief Operator a new m_str object.
     *
     * @param m_str - Data which gives its state.
     * @return m_str& - New object.
     */
    m_str& operator=(m_str&& m_str) noexcept = default;

    // constexpr m_str(m_str&& m_str) noexcept;
    // inline m_str& operator=(m_str&& m_str) noexcept;

    /// Destroy the m_str object.
    ~m_str() noexcept = default;

    /**
     * @brief Appends data to the end.
     *
     * @param m_str - Data which will be this->append(m_str).
     * @return constexpr m_str& - New data.
     */
    constexpr m_str& operator+=(m_str& m_str);

    /**
     * @brief Copies data to m_str.
     *
     * @param str - Data to be recorded.
     */
    constexpr void write(const_pointer str);

    /**
     * @brief Copied data to m_str.
     *
     * @param m_str - Data to be recorded.
     */
    void write(const m_str& m_str);

    /**
     * @brief Appends a data to the end.
     *
     * @param str - Data which will be this->append(str).
     */
    constexpr void append(const_pointer str);

    /**
     * @brief Appends a data to the end.
     *
     * @param m_str - Data which will be this->append(m_str).
     */
    constexpr void append(const m_str& m_str);

    /**
     * @brief Appends a character to the end.
     *
     * @param symbol - Character added to the end.
     */
    constexpr void push_back(value_type symbol);

    ///  Removes the last character.
    constexpr void pop_back();

    /**
     * @brief Removes characters.
     *
     * @param index - First character to remove.
     * @param count - Number of characters to remove.
     *
     * @throw std::out_of_range: pos > size.
     */
    constexpr void erase(size_type index, size_type count);

    /**
     * @brief Removes characters.
     *
     * @param pos - The position from which one character is removed.
     *
     * @throw std::out_of_range: pos > size.
     */
    constexpr void erase(iterator pos);

    /**
     * @brief Changes the number of characters stored.
     *
     * @param count - New size.
     */
    void resize(size_type count);

    /**
     * @brief Swaps the contents.
     *
     * @param m_str - New content.
     */
    void swap(m_str&& m_str);

    /**
     * @brief Reserves storage.
     *
     * @param new_capacity - New size storage.
     */
    void reserve(size_type new_capacity);

    /// Clears the contents.
    void clear() noexcept;

    /**
     * @brief Inserts characters.
     *
     * @param index - Position at which the content will be inserted.
     * @param count - Number of characters to insert.
     * @param symbol - Character to insert.
     *
     * @throw std::out_of_range: index > size.
     */
    void insert(size_type index, size_type count, value_type symbol);

    /**
     * @brief Insert one character.
     *
     * @param index - Where the character will be written.
     * @param symbol - Character to insert.
     *
     * @throw std::out_of_range: index > size.
     */
    void insert(size_type index, value_type symbol);

    /**
     * @brief Insert data.
     *
     * @param index - Where will data be written.
     * @param str - Data to insert.
     *
     * @throw std::out_of_range: index > size.
     */
    void insert(size_type index, std::string_view str);

    /**
     * @brief Insert data with options for data.
     *
     * @param index - Where will data be written.
     * @param str - Data to insert.
     * @param index_str - Where will the data be taken from data to be written
     * to m_str.
     * @param count - Number of characters to write from data.
     *
     * @throw std::out_of_range: index > size.
     * @throw std::out_of_ragnge: index_str > size_str.
     */
    void insert(size_type index,
                std::string_view str,
                size_type index_str,
                size_type count);

    /**
     * @brief Replaces specified portion of a string.
     *
     * @param pos Start of the substring that is going to be replaced.
     * @param count Length of the substring that is going to be replaced.
     * @param str - Data to use for replacement.
     *
     * @throw std::out_of_range: pos > size.
     */
    void replace(size_type pos, size_type count, std::string_view str);

    /**
     * @brief Copies characters.
     *
     * @tparam OutputIt - Template iterator.
     *
     * @param iter - Iterator to the destination character string .
     * @param count - Length of the substring.
     * @param pos - Position of the first character to include.
     *
     * @throw std::out_of_range: pos > size.
     */
    template <typename OutputIt>
    constexpr void copy(OutputIt iter,
                        size_type count,
                        size_type pos = 0) const;

    /**
     * @brief Returns an iterator to the beginning.
     *
     * @return constexpr pointer - Iterator for begin.
     */
    [[nodiscard]] constexpr iterator begin() noexcept;

    /**
     * @brief Returns an iterator to the end.
     *
     * @return constexpr pointer - Iterator for end.
     */
    [[nodiscard]] constexpr iterator end() noexcept;

    /**
     * @brief Returns an const_iterator to the beginning.
     *
     * @return constexpr pointer - Const iterator for begin.
     */
    [[nodiscard]] constexpr const_iterator begin() const noexcept;

    /**
     * @brief Returns an const_iterator to the end.
     *
     * @return constexpr pointer - Const iterator for end.
     */
    [[nodiscard]] constexpr const_iterator end() const noexcept;

    /**
     * @brief Accesses the first character.
     *
     * @return constexpr reference - Reference for first character.
     */
    [[nodiscard]] constexpr reference front();

    /**
     * @brief Accesses the last character.
     *
     * @return constexpr reference - Reference for last character.
     */
    [[nodiscard]] constexpr reference back();

    /**
     * @brief Accesses the first character.
     *
     * @return constexpr reference - Const Reference for first character.
     */
    [[nodiscard]] constexpr const_reference front() const;

    /**
     * @brief Accesses the last character.
     *
     * @return constexpr reference - Const reference for last character.
     */
    [[nodiscard]] constexpr const_reference back() const;

    /**
     * @brief View str.
     *
     * @return constexpr std::string_view - std::string_view to view the str.
     */
    [[nodiscard]] constexpr std::string_view view() const noexcept;

    /**
     * @brief Returns a const_pointer to the first character of a string.
     *
     * @return constexpr const_pointer - Const pointer for first character.
     */
    [[nodiscard]] constexpr const_pointer data() const noexcept;

    /**
     * @brief Returns a pointer to the first character of a string.
     *
     * @return constexpr pointer - Pointer for first character.
     */
    [[nodiscard]] constexpr pointer data() noexcept;

    /**
     * @brief Returns the number of characters.
     *
     * @return constexpr size_type - Number of characters.
     */
    [[nodiscard]] constexpr size_type size() const noexcept;

    /**
     * @brief Returns the number of characters.
     *
     * @return constexpr size_type - Number of characters.
     */
    [[nodiscard]] constexpr size_type length() const noexcept;

    /**
     * @brief Returns the number of characters that can be held in currently
     * allocated storage.
     *
     * @return constexpr size_type - number of characters that can be held in
     * currently allocated storage.
     */
    [[nodiscard]] constexpr size_type capacity() const noexcept;

    /**
     * @brief Checks whether the string is empty.
     *
     * @return true - String is empty.
     * @return false - String dont empty.
     */
    [[nodiscard]] constexpr bool empty() const noexcept;

    /**
     * @brief Accesses the specified character with bounds checking.
     *
     * @param index - Position of the character to return.
     * @return constexpr const_reference - Character to return.
     *
     * @throw std::out_of_range: index > size.
     */
    [[nodiscard]] constexpr const_reference at(size_type index) const;

    /**
     * @brief Accesses the specified character with bounds checking.
     *
     * @param index - Position of the character to return.
     * @return constexpr reference - Character to return.
     *
     * @throw std::out_of_range: index > size.
     */
    [[nodiscard]] constexpr reference at(size_type index);

    /**
     * @brief Returns a substring.
     *
     * @param count - Length of the substring.
     * @param pos - Position of the first character to include.
     * @return constexpr std::string_view - String containing the substring.
     *
     * @throw std::out_of_range: pos > size.
     */
    [[nodiscard]] constexpr std::string_view substr(size_type count,
                                                    size_type pos = 0) const;

    /**
     * @brief Checks if the string starts with the given prefix.
     *
     * @param prefix - A string view which may be a result of implicit
     * conversion from another std::basic_string.
     * @return true - If the string begins with the provided prefix.
     * @return false - Otherwise.
     */
    [[nodiscard]] constexpr bool starts_with(
        std::string_view prefix) const noexcept;

    /**
     * @brief Checks if the string ends with the given prefix.
     *
     * @param prefix - A string view which may be a result of implicit
     * conversion from another std::basic_string.
     * @return true - If the string ends with the provided prefix.
     * @return false - Otherwise.
     */
    [[nodiscard]] constexpr bool ends_with(
        std::string_view prefix) const noexcept;

    /**
     * @brief Compares two strings.
     *
     * @param str - Other string to compare to.
     * @return true - Strings are equal.
     * @return false - Strings dont equal.
     */
    [[nodiscard]] constexpr bool compare(const_pointer str) const noexcept;

    /**
     * @brief Compares two string.
     *
     * @param m_str - Other string to compare to.
     * @return true - Strings are equal.
     * @return false - Strings dont equal.
     */
    [[nodiscard]] constexpr bool compare(const m_str& m_str) const noexcept;

    /**
     * @brief Compares two string.
     *
     * @param str_view - Other string to compare to.
     * @return true - Strings are equal.
     * @return false - Strings dont equal.
     */
    [[nodiscard]] constexpr bool compare(
        const std::string_view& str_view) const noexcept;

    /**
     * @brief Checks if the string contains the given substring or character.
     *
     * @param str - A string view which may be a result of implicit conversion
     * from another std::basic_string.
     * @return true - If the string contains the provided substring.
     * @return false - Otherwise.
     */
    [[nodiscard]] constexpr bool containts(std::string_view str) const noexcept;

    /**
     * @brief Finds the first occurrence of the given substring.
     *
     * @param value - String to search for.
     * @param pos - Position at which to start the search.
     * @return constexpr size_type - Position of the first character of the
     * found substring or std::string_view::npos if no such substring is found.
     *
     * @throw std::out_of_range: pos > size.
     */
    [[nodiscard]] constexpr size_type find(std::string_view value,
                                           size_type pos = 0) const;

    /**
     * @brief Find the last occurrence of a substring.
     *
     * @param value - String to search for.
     * @param pos - Position at which to start the search.
     * @return constexpr size_type - Position of the first character of the
     * found substring or std::string_view::npos if no such substring is found.
     *
     * @throw std::out_of_range: pos > size.
     */
    [[nodiscard]] constexpr size_type rfind(std::string_view value,
                                            size_type pos = 0) const;

    /**
     * @brief Find first occurrence of characters.
     *
     * @param value - String to search for.
     * @param pos - Position at which to start the search.
     * @return constexpr size_type - Position of the first character of the
     * found substring or std::string_view::npos if no such substring is found.
     *
     * @throw std::out_of_range: pos > size.
     */
    [[nodiscard]] constexpr size_type find_first_of(std::string_view value,
                                                    size_type pos = 0) const;

    /**
     * @brief Find first absence of characters.
     *
     * @param value - String to search for.
     * @param pos - Position at which to start the search.
     * @return constexpr size_type - Position of the first character of the
     * found substring or std::string_view::npos if no such substring is found.
     *
     * @throw std::out_of_range: pos > size.
     */
    [[nodiscard]] constexpr size_type find_first_not_of(
        std::string_view value,
        size_type pos = 0) const;

    /**
     * @brief Find last occurrence of characters.
     *
     * @param value - String to search for.
     * @param pos - Position at which to start the search.
     * @return constexpr size_type - Position of the first character of the
     * found substring or std::string_view::npos if no such substring is found.
     *
     * @throw std::out_of_range: pos > size.
     */
    [[nodiscard]] constexpr size_type find_last_of(std::string_view value,
                                                   size_type pos = 0) const;

    /**
     * @brief Find last absence of characters.
     *
     * @param value - String to search for.
     * @param pos - Position at which to start the search.
     * @return constexpr size_type - Position of the first character of the
     * found substring or std::string_view::npos if no such substring is found.
     *
     * @throw std::out_of_range: pos > size.
     */
    [[nodiscard]] constexpr size_type find_last_not_of(std::string_view value,
                                                       size_type pos = 0) const;

    /**
     * @brief Accesses the specified character.
     *
     * @param index - position of the character to return.
     * @return constexpr reference - Reference for character.
     */
    [[nodiscard]] constexpr reference operator[](size_type index);

    /**
     * @brief Accesses the specified character.
     *
     * @param index - position of the character to return.
     * @return constexpr reference - Const reference for character.
     */
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
