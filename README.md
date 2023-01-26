[![CodeFactor](https://www.codefactor.io/repository/github/dan4ik605743/m_str/badge)](https://www.codefactor.io/repository/github/dan4ik605743/m_str)
# m_str 
The <a href="https://en.cppreference.com/w/cpp/string/basic_string">std::string</a> header-only library is written with constexpr, <a href="https://en.cppreference.com/w/cpp/memory/unique_ptr">std::unique_ptrs</a> and SSO realization with <a href="https://en.cppreference.com/w/cpp/utility/variant">std::variant</a> (<a href="https://stackoverflow.com/questions/21694302/what-are-the-mechanics-of-short-string-optimization-in-libc">Small String Optimization</a>)

## Install
```
git clone https://github.com/dan4ik605743/m_str
cd m_str
mkdir build && cd build
cmake ..
sudo cmake --build . --target install --config Release
```

## Usage with not installed
Check <a href="https://github.com/dan4ik605743/m_str/tree/master/examples/usage_with_not_installed">examples</a>

//TODO Doxygen